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