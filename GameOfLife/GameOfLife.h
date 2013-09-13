//Rules
//Any live cell with fewer than two live neighbours dies, as if caused by under-population.
//Any live cell with two or three live neighbours lives on to the next generation.
//Any live cell with more than three live neighbours dies, as if by overcrowding.
//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include "Cell.h"
#include <set>

class World{
public:
  void giveCellLife(const Cell& _cell);
  bool isCellAlive(const Cell& _cell);
  World tick();
  int numberOfLiveNeighbours(const Cell& _cell);

private:
  std::set<Cell> recordOfLivingCells;
  bool cellHasTwoOrThreeLiveNeighbours(const Cell& _cell);
  bool deadCellHasExactlyThreeLiveNeighbours(const Cell& _cell);
  void tickOfLiveCells(World& worldOfNextTick, const Cell& liveCell);
  void tickOfDeadCells(World& worldOfNextTick, const Cell& liveCell);
};

#endif