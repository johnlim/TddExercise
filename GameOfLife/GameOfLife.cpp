#include "GameOfLife.h"

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
  GameGrid = new int[noOfXCells * noOfYCells];
}

bool GameOfLife::IsCellAlive(int x, int y)
{
  return GameGrid[x * y];
}