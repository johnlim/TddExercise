//Rules
//Any live cell with fewer than two live neighbours dies, as if caused by under-population.
//Any live cell with two or three live neighbours lives on to the next generation.
//Any live cell with more than three live neighbours dies, as if by overcrowding.
//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <set>
#include <vector>

class Cell{
public:
  Cell(int x, int y);
  bool operator== (const Cell& _cell) const;
  /*Note: operator== is not used by std::set. Elements a and b are considered equal if !(a < b) && !(b < a)*/
  bool operator< (const Cell& _cell) const;
  std::vector<Cell> neighbours() const;
private:
  int xCoordinate;
  int yCoordinate;
};

class World{
public:
  void giveCellLife(const Cell& _cell);
  bool isCellAlive(Cell _cell);
  World tick();
  int numberOfLiveNeighbours(Cell _cell);

private:
  std::set<Cell> recordOfLivingCells;
  bool cellHasTwoOrThreeLiveNeighbours(Cell _cell);
  bool deadCellHasExactlyThreeLiveNeighbours(Cell _cell);
  void tickOfLiveCells(World& worldOfNextTick, Cell liveCell);
  void tickOfDeadCells(World& worldOfNextTick, Cell liveCell);
};

#endif