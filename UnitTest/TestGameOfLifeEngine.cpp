#include "CppUTest\TestHarness.h"

class Cell {
public:
  Cell(int x, int y) { }
};

class GameBoard {
public:
  GameBoard(){ cellState = (true);}
  
  void setCellAlive(Cell cell) {
  }

  bool isCellAlive(Cell cell) {
    return cellState;
  }

  void tick() {
    cellState = false;
  }
private:
  bool cellState;
};

TEST_GROUP(GameOfLife)
{
  GameBoard gameBoard;
};

TEST(GameOfLife, ifCellIsAliveGetCellReturnsTrue)
{
  Cell cell(2,3);
  gameBoard.setCellAlive(cell);
  CHECK_TRUE(gameBoard.isCellAlive(cell));
}

TEST(GameOfLife, livingCellShouldDieWithoutAnyLivingNeighbour)
{
  Cell cell(2,3);
  gameBoard.setCellAlive(cell);
  gameBoard.tick();
  CHECK_FALSE(gameBoard.isCellAlive(cell));
}
