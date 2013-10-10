#include "Cell.h"

using namespace std;

Cell::Cell(int x, int y) : xCoordinate(x), yCoordinate(y){
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