#include "GameOfLife.h"
#include <assert.h>

GameOfLife::GameOfLife(int noOfXCells, int noOfYCells)
           :GameGrid(0),
            noOfXCells(noOfXCells),
            noOfYCells(noOfYCells)
            
{
  CreateGrid();
}

GameOfLife::~GameOfLife()
{
  delete GameGrid;
}

void GameOfLife::CreateGrid()
{
  GameGrid = new bool[noOfXCells * noOfYCells]();
}

bool GameOfLife::IsCellAlive(int x, int y) const
{
  assert((x < noOfXCells) && (y < noOfYCells));
  return ((bool) GameGrid[x * noOfYCells + y]);
}

void GameOfLife::GiveCellLife(int x, int y)
{
  assert((x < noOfXCells) && (y < noOfYCells));
  GameGrid[x * noOfYCells + y] = true;
}

GameOfLife::GameOfLife(const GameOfLife& rhs)
            :GameGrid(0),
            noOfXCells(rhs.noOfXCells),
            noOfYCells(rhs.noOfYCells)
{
  CreateGrid();
  for (int x = 0; x < noOfXCells; x++)
  {
    for (int y = 0; y < noOfYCells; y++)
    {
      GameGrid[x * noOfYCells + y] = rhs.GameGrid[x * noOfYCells + y];
    }
  }
}

//void GameOfLife::TriggerNextGeneration(void)
//{
//  GameGridCache = new bool[noOfXCells * noOfYCells]();
//  for (int x = 0; x < noOfXCells; x++)
//  {
//    for (int y = 0; y < noOfYCells; y++)
//    {
//      GameGridCache[x * y] = GameGrid[x * y];
//    }
//  }
//  for (int x = 0; x < noOfCells; x++)
//  {
//    for (int y = 0; y < noOfYCells; y++)
//    {
//      if IsCellAlive(x,y)
//      {
//        if(IsCellAlive(x+1,y)||(IsCellAlive(x-1,y)||(IsCellAlive(x,y+1)||(IsCellAlive(x,y-1)||(IsCellAlive(x+1,y+1))||(IsCellAlive(x-1,y-1)||(IsCellAlive(x+1,y-1))||(IsCellAlive(x-1,y+1))
//      }
//    }
//}