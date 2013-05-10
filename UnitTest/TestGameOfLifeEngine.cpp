#include "CppUTest\TestHarness.h"
#include <vector>
using namespace std;
class Cell{
public:
  Cell(int x, int y){cellX = x; cellY = y;}
  Cell neighbor(int index) {
    int deltas[][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    return Cell(cellX + deltas[index][0], cellY + deltas[index][1]);
  }
  bool operator==(Cell cell){ return (cellX == cell.cellX && cellY == cell.cellY);}
private:
  int cellX;
  int cellY;
};

class World{
public:
  World() : livingCell_(0,0) {}
  void live(Cell cell){livingCell_ = cell;}
  World tick(){return World();};
  bool isLive(Cell cell){return livingCell_ == cell;};

private:
  vector<Cell> livingCells;
  Cell livingCell_;
};

TEST_GROUP(GameOfLife)
{
};


TEST(GameOfLife, cellsNotEqual) {
  CHECK_FALSE(Cell(2, 3) == Cell(4,5));
}

TEST(GameOfLife, neighborOfCell) {
  int x = 4, y = 6;
  Cell cell(x, y);

  CHECK(Cell(x - 1, y) == cell.neighbor(0));
  CHECK(Cell(x + 1, y) == cell.neighbor(1));
  CHECK(Cell(x, y - 1) == cell.neighbor(2));
  CHECK(Cell(x, y + 1) == cell.neighbor(3));
  CHECK(Cell(x - 1, y - 1) == cell.neighbor(4));
  CHECK(Cell(x - 1, y + 1) == cell.neighbor(5));
  CHECK(Cell(x + 1, y - 1) == cell.neighbor(6));
  CHECK(Cell(x + 1, y + 1) == cell.neighbor(7));
}

TEST(GameOfLife, liveCellShouldBeLiving) {
  Cell cell(2, 3);
  Cell anotherCell(4, 5);
  World world;
  world.live(cell);
  world.live(anotherCell);
  CHECK_TRUE(world.isLive(cell));

}

TEST(GameOfLife, liveCellShouldDieInNextTickWhenHaving0Neighbor) {
  Cell cell(2, 3);
  World world;
  world.live(cell);
  CHECK_FALSE(world.tick().isLive(cell));

}

IGNORE_TEST(GameOfLife, liveCellShouldSurviveInNextTickIfHas2Neighbours)
{
  Cell cell(2, 3);
  World world;
  world.live(cell);
  world.live(cell.neighbor(0));
  world.live(cell.neighbor(1));
  CHECK_TRUE(world.tick().isLive(cell)); 
}

