#include "CppUTest/TestHarness.h"
#include "GameOfLife.h"

TEST_GROUP(GameOfLifeEngine)
{
    
};

TEST(GameOfLifeEngine, GameGridIsBlankWhenGameOfLifeIsInstantiated)
{
  int noOfXCells = 2;
  int noOfYCells = 3;
  int NoOfCellsChecked = 0;
  GameOfLife game(noOfXCells,noOfYCells);
  for (int x = 0; x<(noOfXCells); x++)
  {
    for(int y = 0; y<(noOfYCells); y++)
    {
      CHECK_FALSE(0, game.IsCellAlive(x,y)); 
      NoOfCellsChecked++;
    }
  }
  //Ensure every cell was checked;
  LONGS_EQUAL(noOfXCells*noOfYCells, NoOfCellsChecked);
}