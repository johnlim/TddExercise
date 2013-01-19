class GameOfLife
{
public:
  GameOfLife(int noOfXCells, int noOfYCells);
  ~GameOfLife();
  GameOfLife(const GameOfLife& rhs);
  
  bool IsCellAlive(int x, int y) const;
  void GiveCellLife(int x, int y);
  unsigned int ReturnNumberOfLiveNeighboursForCell(int x, int y);

protected:

private:
  const int noOfXCells;
  const int noOfYCells;
  bool* GameGrid;  

  GameOfLife& operator=(const GameOfLife&);

  void CreateGrid();
  
};