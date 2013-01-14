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

bool GameOfLife::IsCellAlive(int x, int y)
{
  assert((x < noOfXCells) && (y < noOfYCells));
  return ((bool) GameGrid[x * y]);
}

void GameOfLife::GiveCellLife(int x, int y)
{
  assert((x < noOfXCells) && (y < noOfYCells));
  GameGrid[x * y] = true;
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
      GameGrid[x * y] = rhs.GameGrid[x * y];
    }
  }
}