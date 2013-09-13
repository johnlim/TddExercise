#include "CppUTest/TestHarness.h"
#include <set>
#include <vector>

using namespace std;
//Rules
//Any live cell with fewer than two live neighbours dies, as if caused by under-population.
//Any live cell with two or three live neighbours lives on to the next generation.
//Any live cell with more than three live neighbours dies, as if by overcrowding.
//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

class Cell
{
public:
  Cell(int x, int y)
  :xCoordinate(x),
   yCoordinate(y)
  {
  }
  bool operator== (const Cell& _cell) const { return (_cell.xCoordinate == xCoordinate) && (_cell.yCoordinate == yCoordinate);}
  /*Note: operator== is not used by std::set. Elements a and b are considered equal if !(a < b) && !(b < a)*/
  bool operator< (const Cell& _cell) const {
    if (xCoordinate < _cell.xCoordinate)
		return true;
	if (xCoordinate > _cell.xCoordinate)
		return false;
	return (yCoordinate < _cell.yCoordinate);
  }
  vector<Cell> neighbours() const {
    vector<Cell> recordOfNeighbours;
    recordOfNeighbours.push_back(Cell(xCoordinate-1, yCoordinate));
    recordOfNeighbours.push_back(Cell(xCoordinate, yCoordinate-1));
    recordOfNeighbours.push_back(Cell(xCoordinate+1, yCoordinate));
    recordOfNeighbours.push_back(Cell(xCoordinate, yCoordinate+1));
    recordOfNeighbours.push_back(Cell(xCoordinate-1, yCoordinate-1));
    recordOfNeighbours.push_back(Cell(xCoordinate+1, yCoordinate+1));
    recordOfNeighbours.push_back(Cell(xCoordinate-1, yCoordinate+1));
    recordOfNeighbours.push_back(Cell(xCoordinate+1, yCoordinate-1));
    return recordOfNeighbours;
  }
private:
  int xCoordinate;
  int yCoordinate;
};

class World
{
public:
  void giveCellLife(const Cell& _cell)  {recordOfLivingCells.insert(_cell); };
  bool isCellAlive(Cell _cell){return (recordOfLivingCells.count(_cell) > 0);};
  World tick() {
    World _world;
       
    for(set<Cell>::iterator it = recordOfLivingCells.begin(); it != recordOfLivingCells.end(); it++){
      if( cellHasTwoOrThreeLiveNeighbours(*it) )
        _world.giveCellLife(*it);
    }

    for(set<Cell>::iterator it = recordOfLivingCells.begin(); it != recordOfLivingCells.end(); it++){
      for(int i = 0; i < it->neighbours().size(); i++){
         if(!(isCellAlive((*it).neighbours()[i])) && (numberOfLiveNeighbours((*it).neighbours()[i])) == 3)
            _world.giveCellLife((*it).neighbours()[i]);
      }
  }
    return _world;
  }
  int numberOfLiveNeighbours(Cell _cell){
    int liveNeighbourCount=0;
    for (int i = 0; i < _cell.neighbours().size(); i++){
      if(isCellAlive(_cell.neighbours()[i])){
        liveNeighbourCount++;
      }
    }
  return liveNeighbourCount;
  };
private:
  std::set<Cell> recordOfLivingCells;
  bool cellHasTwoOrThreeLiveNeighbours(Cell _cell){ 
    return (numberOfLiveNeighbours(_cell) == 2 || numberOfLiveNeighbours(_cell) == 3);    
  }
};



TEST_GROUP(testGameOfLife)
{
  World _world;
  
  vector<Cell> createNeighboursForCell(Cell cell){
    return cell.neighbours();
  }
};

TEST(testGameOfLife, testCellsComparisonReturnTrueIfEqual)
{
  Cell _cellOne(0,0);
  Cell _cellTwo(0,0);
  CHECK_TRUE(_cellOne==_cellTwo);
}

TEST(testGameOfLife, testCellsComparisonReturnFalseIfNotEqual)
{
  Cell _cellOne(0,0);
  Cell _cellTwo(0,1);
  CHECK_FALSE(_cellOne==_cellTwo);
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
    CHECK_TRUE(cell.neighbours()[i] == Cell(x+index[i][0], y+index[i][1]));
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
  
  for( int i = 0; i < neighbours.size(); i++)
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
  

