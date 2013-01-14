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
      CHECK_FALSE(game.IsCellAlive(x,y)); 
      NoOfCellsChecked++;
    }
  }
  //Ensure every cell was checked;
  LONGS_EQUAL(noOfXCells*noOfYCells, NoOfCellsChecked);
}

TEST(GameOfLifeEngine, CellReturnsTrueIfItIsAliveAndReturnsFalseIfOtherwise)
{
  int noOfXCells = 2;
  int noOfYCells = 3;
  int NoOfCellsChecked = 0;

  GameOfLife game(noOfXCells,noOfYCells);
  game.GiveCellLife(1,1);
  CHECK_TRUE(game.IsCellAlive(1,1));
  NoOfCellsChecked++;

  for (int x = 0; x<(noOfXCells); x++)
  {
    for(int y = 0; y<(noOfYCells); y++)
    {
      if(x==1 && y==1)
      {
        continue;
      }
      CHECK_FALSE(game.IsCellAlive(x,y)); 
      NoOfCellsChecked++;
    }
  }
  //Ensure every cell was checked;
  LONGS_EQUAL(noOfXCells*noOfYCells, NoOfCellsChecked);
}

TEST(GameOfLifeEngine, CopyConstructorCreatesACopyOfGameGridAndItsStates)
{
  int noOfXCells = 5;
  int noOfYCells = 8;
  int NoOfCellsChecked = 0;

  GameOfLife game(noOfXCells,noOfYCells);
  game.GiveCellLife(4,7);

  GameOfLife gameCopy(game);
  
  for (int x = 0; x<(noOfXCells); x++)
  {
    for(int y = 0; y<(noOfYCells); y++)
    {
      if(x==4 && y==7)
      {
        CHECK_TRUE(game.IsCellAlive(x,y));
      }
      else
      {
        CHECK_FALSE(gameCopy.IsCellAlive(x,y)); 
      }
      NoOfCellsChecked++;
    }
  }
  //Ensure every cell was checked;
  LONGS_EQUAL(noOfXCells*noOfYCells, NoOfCellsChecked);
}

//TEST(GameOfLifeEngine, AnyLiveCellWithFewerThanTwoLiveNeighboursDies)
//{
//  FAIL("Pass the Test!");
//}

