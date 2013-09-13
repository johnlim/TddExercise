#include "GameOfLife.h"

using namespace std;

Cell::Cell(int x, int y) : xCoordinate(x), yCoordinate(y){
}

bool Cell::operator== (const Cell& _cell) const { 
	return (_cell.xCoordinate == xCoordinate) && (_cell.yCoordinate == yCoordinate);
}
	/*Note: operator== is not used by std::set. Elements a and b are considered equal if !(a < b) && !(b < a)*/
bool Cell::operator< (const Cell& _cell) const {
	if (xCoordinate < _cell.xCoordinate)
		return true;
	if (xCoordinate > _cell.xCoordinate)
		return false;
	return (yCoordinate < _cell.yCoordinate);
}
	
vector<Cell> Cell::neighbours() const {
  vector<Cell> recordOfNeighbours;
  recordOfNeighbours.push_back(Cell(xCoordinate-1, yCoordinate));
  recordOfNeighbours.push_back(Cell(xCoordinate, yCoordinate-1));
  recordOfNeighbours.push_back(Cell(xCoordinate+1, yCoordinate));
  recordOfNeighbours.push_back(Cell(xCoordinate, yCoordinate+1));
  recordOfNeighbours.push_back(Cell(xCoordinate-1, yCoordinate-1));
  recordOfNeighbours.push_back(Cell(xCoordinate+1, yCoordinate+1));
  recordOfNeighbours.push_back(Cell(xCoordinate-1, yCoordinate+1));
  recordOfNeighbours.push_back(Cell(xCoordinate+1, yCoordinate-1));
  return recordOfNeighbours;
}

void World::giveCellLife(const Cell& _cell){
  recordOfLivingCells.insert(_cell); 
}

bool World::isCellAlive(const Cell& _cell){
  return (recordOfLivingCells.count(_cell) > 0);
}

World World::tick() {
  World nextWorld;
       
  for(set<Cell>::iterator it = recordOfLivingCells.begin(); it != recordOfLivingCells.end(); it++){
    tickOfLiveCells(nextWorld, *it);
    tickOfDeadCells(nextWorld, *it);
  }
  return nextWorld;
}
  
int World::numberOfLiveNeighbours(const Cell& _cell){
  int liveNeighbourCount=0;
  for (int i = 0; i < _cell.neighbours().size(); i++){
    if(isCellAlive(_cell.neighbours()[i])){
      liveNeighbourCount++;
    }
  }
  return liveNeighbourCount;
}

bool World::cellHasTwoOrThreeLiveNeighbours(const Cell& _cell){ 
    return (numberOfLiveNeighbours(_cell) == 2 || numberOfLiveNeighbours(_cell) == 3);    
}

bool World::deadCellHasExactlyThreeLiveNeighbours(const Cell& _cell){
   return (!(isCellAlive(_cell)) && (numberOfLiveNeighbours(_cell) == 3));
}

void World::tickOfLiveCells(World& worldOfNextTick, const Cell& liveCell)
{
  if( cellHasTwoOrThreeLiveNeighbours(liveCell) )
      worldOfNextTick.giveCellLife(liveCell);
}

void World::tickOfDeadCells(World& worldOfNextTick, const Cell& liveCell)
{
  for(int i = 0; i < liveCell.neighbours().size(); i++){
      if(deadCellHasExactlyThreeLiveNeighbours(liveCell.neighbours()[i])){      
        worldOfNextTick.giveCellLife(liveCell.neighbours()[i]);
      }
  }
}