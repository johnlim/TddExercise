#ifndef _CELL_H_
#define _CELL_H_

#include <vector>

class Cell{
public:
  Cell(int x, int y);
  
  /*Note: operator== is not used by std::set. Elements a and b are considered equal if !(a < b) && !(b < a)*/
  bool operator< (const Cell& _cell) const;
  std::vector<Cell> neighbours() const;
private:
  int xCoordinate;
  int yCoordinate;
};

#endif