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
  if(((x > noOfXCells) || (y > noOfYCells) || (x < 0) || (y < 0)))
  {
    return false;
  }
  return ((bool) GameGrid[x * noOfYCells + y]);
}

void GameOfLife::GiveCellLife(int x, int y)
{
  assert((x < noOfXCells) && (y < noOfYCells));
  assert(((x >= 0) && (y >= 0)));
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

unsigned int GameOfLife::ReturnNumberOfLiveNeighboursForCell(int x, int y)
{
  unsigned int NumberOfLiveNeighbours = 0;
  
  if (IsCellAlive(x+1,y))   NumberOfLiveNeighbours++;
  if (IsCellAlive(x,y+1))   NumberOfLiveNeighbours++;
  if (IsCellAlive(x+1,y+1)) NumberOfLiveNeighbours++;
  if (IsCellAlive(x-1,y))   NumberOfLiveNeighbours++;
  if (IsCellAlive(x,y-1))   NumberOfLiveNeighbours++;
  if (IsCellAlive(x-1,y-1)) NumberOfLiveNeighbours++;
  if (IsCellAlive(x+1,y-1)) NumberOfLiveNeighbours++;
  if (IsCellAlive(x-1,y+1)) NumberOfLiveNeighbours++;
    
  return NumberOfLiveNeighbours;
}
