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

bool World::isCellAlive(Cell _cell){
  return (recordOfLivingCells.count(_cell) > 0);
}

World World::tick() {
  World _world;
       
  for(set<Cell>::iterator it = recordOfLivingCells.begin(); it != recordOfLivingCells.end(); it++){
    if( cellHasTwoOrThreeLiveNeighbours(*it) )
      _world.giveCellLife(*it);
  }

  for(set<Cell>::iterator it = recordOfLivingCells.begin(); it != recordOfLivingCells.end(); it++){
    for(int i = 0; i < it->neighbours().size(); i++){
        if(!(isCellAlive((*it).neighbours()[i])) && (numberOfLiveNeighbours((*it).neighbours()[i])) == 3)
          _world.giveCellLife((*it).neighbours()[i]);
    }
  }
  return _world;
}
  
int World::numberOfLiveNeighbours(Cell _cell){
  int liveNeighbourCount=0;
  for (int i = 0; i < _cell.neighbours().size(); i++){
    if(isCellAlive(_cell.neighbours()[i])){
      liveNeighbourCount++;
    }
  }
  return liveNeighbourCount;
}

bool World::cellHasTwoOrThreeLiveNeighbours(Cell _cell){ 
    return (numberOfLiveNeighbours(_cell) == 2 || numberOfLiveNeighbours(_cell) == 3);    
}