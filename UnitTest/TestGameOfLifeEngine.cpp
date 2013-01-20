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
  
  //check boundary + 1 conditions 
  game.GiveCellLife(0,1); 
  game.GiveCellLife(1,0); 
  
  for (int x = 0; x<(noOfXCells); x++)
  {
    for(int y = 0; y<(noOfYCells); y++)
    {
      if((x==0 && y==1)||(x==1 && y==0))
      {
        CHECK_TRUE(game.IsCellAlive(x,y));
      }
      else
      {
          CHECK_FALSE(game.IsCellAlive(x,y)); 
      }
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

TEST(GameOfLifeEngine, IsCellAliveReturnsFalseForInvalidCells)
{
  int noOfXCells = 2;
  int noOfYCells = 3;
  int NoOfCellsChecked = 0;

  GameOfLife game(noOfXCells,noOfYCells);

  for (int y = 0; y < noOfYCells; y++)
  {
    CHECK_FALSE(game.IsCellAlive(-1,y));
    CHECK_FALSE(game.IsCellAlive(noOfXCells+1,y));
    NoOfCellsChecked+=2;;
  }
  for (int x = 0; x < noOfXCells; x++)
  {
    CHECK_FALSE(game.IsCellAlive(x,-1));
    CHECK_FALSE(game.IsCellAlive(x,noOfYCells+1));
    NoOfCellsChecked+=2;
  }
  CHECK_FALSE(game.IsCellAlive(-1,-1));
  CHECK_FALSE(game.IsCellAlive(noOfXCells + 1 , noOfYCells + 1));
  CHECK_FALSE(game.IsCellAlive(noOfXCells + 1 , -1));
  CHECK_FALSE(game.IsCellAlive(-1 , noOfYCells + 1));
  NoOfCellsChecked+=4;

  //Ensure every adjacent boundary cell was checked;
  LONGS_EQUAL((noOfXCells*2+ noOfYCells*2 + 4), NoOfCellsChecked);
}

TEST(GameOfLifeEngine, ReturnsNumberOfLiveNeighbours)
{
  int noOfXCells = 3;
  int noOfYCells = 3;
  GameOfLife game(noOfXCells, noOfYCells);

  game.GiveCellLife(0,0);
  LONGS_EQUAL(0, game.ReturnNumberOfLiveNeighboursForCell(0,0));
  
  game.GiveCellLife(1,1);
  LONGS_EQUAL(1, game.ReturnNumberOfLiveNeighboursForCell(0,0));
  LONGS_EQUAL(1, game.ReturnNumberOfLiveNeighboursForCell(1,1));
  LONGS_EQUAL(2, game.ReturnNumberOfLiveNeighboursForCell(1,0));

  game.GiveCellLife(0,1);
  LONGS_EQUAL(3, game.ReturnNumberOfLiveNeighboursForCell(1,0));

}

TEST(GameOfLifeEngine, AnyLiveCellWithFewerThanTwoLiveNeighboursDies)
{
  int noOfXCells = 3;
  int noOfYCells = 3;
  int NoOfCellsChecked = 0;
  
  GameOfLife game(noOfXCells, noOfYCells);

  game.GiveCellLife(0,0);
  game.TriggerNextGeneration();

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

