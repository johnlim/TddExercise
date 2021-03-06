#include "CppUTest/TestHarness.h"
#include "GameOfLife.h"
using namespace std;
//Rules
//Any live cell with fewer than two live neighbours dies, as if caused by under-population.
//Any live cell with two or three live neighbours lives on to the next generation.
//Any live cell with more than three live neighbours dies, as if by overcrowding.
//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

/*Note: operator== is not used by std::set. Elements a and b are considered equal if !(a < b) && !(b < a)*/
#define CHECK_CELL_EQUAL(a,b) (!(a < b) && !(b < a))

TEST_GROUP(testGameOfLife)
{
  World _world;

  vector<Cell> createNeighboursForCell(Cell cell){
    return cell.neighbours();
  }
};

/*http://stackoverflow.com/questions/9040689/stl-less-operator-and-invalid-operator-error http://cpp-next.com/archive/2010/02/order-i-say/ */
TEST(testGameOfLife, testStricWeakOrdering) 
{
  /*
  Irreflexivity: x < x is always false.
  Antisymmetry: If x < y, then y < x is always false.
  Transitivity: If x < y and y < z, then x < z is always true.
  Transitivity of Equivalence: If x and y are incomparable and y and z are incomparable, then x and z are incomparable.
  */

  Cell x(0,0);
  Cell y(1,0);
  Cell z(0,1);
  
  //Irreflexivity
  CHECK_FALSE(x < x); 
    
  Antisymmetry:
  if(x < y)
    CHECK_FALSE(y < x);  
  if(z < y)
    CHECK_FALSE(y < z);
  
//Transitivity
  if((x < y) && (y < z))
    CHECK_TRUE(x < y);
  if((x < z) && (z < y))
    CHECK_TRUE(x < y);
}

TEST(testGameOfLife, testCellsComparisonReturnTrueIfEqual)
{
  Cell _cellOne(0,0);
  Cell _cellTwo(0,0);
  CHECK_TRUE(CHECK_CELL_EQUAL(_cellOne, _cellTwo));
}

TEST(testGameOfLife, testCellsComparisonReturnFalseIfNotEqual)
{
  Cell _cellOne(0,0);
  Cell _cellTwo(0,1);
  CHECK_FALSE(CHECK_CELL_EQUAL(_cellOne, _cellTwo));
}
TEST(testGameOfLife, testWorldGivesCellLifeResultsInCellHavingLife)
{
  Cell _cell(0,1);
  Cell anotherCell(1,0);
  _world.giveCellLife(_cell);
  _world.giveCellLife(anotherCell);
  CHECK_TRUE(_world.isCellAlive(_cell));
  CHECK_TRUE(_world.isCellAlive(anotherCell));
}

TEST(testGameOfLife, testCellShouldKnowWhoAreItsNeighbours)
{
  int x=6, y=7;
  Cell cell(x,y);
  int index[][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}, {-1,-1}, {1,1}, {-1,1}, {1,-1}};
  for(unsigned int i = 0; i < cell.neighbours().size(); i++)
  {
    CHECK_TRUE(CHECK_CELL_EQUAL(cell.neighbours()[i], Cell(x+index[i][0], y+index[i][1])));
  }
}

TEST(testGameOfLife, worldKnowsCellHasZeroLiveNeighbours)
{
  int x = 7, y = 5;
  vector<Cell> neighbours;
  Cell _cell(x,y);
  neighbours = createNeighboursForCell(_cell);
  
  LONGS_EQUAL(0, _world.numberOfLiveNeighbours(_cell));
}

TEST(testGameOfLife, testWorldKnowsHowManyNeighborsAreLiveCells)
{
  int x = 0, y =0;
  vector<Cell> neighbours;    
  Cell _cell(x,y);

  neighbours = createNeighboursForCell(_cell);
  LONGS_EQUAL(0, _world.numberOfLiveNeighbours(_cell));
  
  for( unsigned int i = 0; i < neighbours.size(); i++)
  {
    _world.giveCellLife(neighbours[i]);
    LONGS_EQUAL(i+1, _world.numberOfLiveNeighbours(_cell));
  }
}

TEST(testGameOfLife, CellWithZeroLiveNeighbourDiesOnNextTick)
{
  Cell soloCell(9,6);
  _world.giveCellLife(soloCell);
  CHECK_FALSE(_world.tick().isCellAlive(soloCell));
}
TEST(testGameOfLife, testCellWithOneLiveNeighbourDiesOnNextTick)
{
  Cell _cell00(0,0);
  Cell _cell01(0,1);
  _world.giveCellLife(_cell00);
  _world.giveCellLife(_cell01);
  CHECK_FALSE(_world.tick().isCellAlive(_cell00));
  CHECK_FALSE(_world.tick().isCellAlive(_cell01));
}

TEST(testGameOfLife, testCellWithTwoNeighboursLivesOnNextTick)
{
  Cell _cell(2,0);
  World world;
  world.giveCellLife(_cell);
  vector<Cell> neighbours;
  neighbours = createNeighboursForCell(_cell);
  
  world.giveCellLife(neighbours[0]);
  world.giveCellLife(neighbours[1]);
  CHECK_TRUE(world.tick().isCellAlive(_cell));
}

TEST(testGameOfLife, testCellWithThreeNeighboursLivesOnNextTick)
{
  Cell _cell(2,0);
  _world.giveCellLife(_cell);
  vector<Cell> neighbours;
  neighbours = createNeighboursForCell(_cell);
  
  _world.giveCellLife(neighbours[0]);
  _world.giveCellLife(neighbours[1]);
  _world.giveCellLife(neighbours[2]);
  CHECK_TRUE(_world.tick().isCellAlive(_cell));
}

TEST(testGameOfLife, testCellWithMoreThanThreeLiveNeighboursDiesOnNextTick)
{
  Cell _cell(4,5);
  _world.giveCellLife(_cell);
  vector<Cell> neighbours = createNeighboursForCell(_cell);
  
  _world.giveCellLife(neighbours[0]);
  _world.giveCellLife(neighbours[1]);
  _world.giveCellLife(neighbours[2]);
  _world.giveCellLife(neighbours[3]);
  CHECK_FALSE(_world.tick().isCellAlive(_cell));
}

TEST(testGameOfLife, DeadCellWithExactlyThreeLiveNeighboursLivesOnNextTick)
{
  int x = 7, y = 10;
  Cell _cell(x,y);
  
  vector<Cell> neighbour = createNeighboursForCell(_cell);
  _world.giveCellLife(neighbour[4]);
  _world.giveCellLife(neighbour[5]);
  _world.giveCellLife(neighbour[6]);
  
  CHECK_TRUE(_world.tick().isCellAlive(_cell));
}