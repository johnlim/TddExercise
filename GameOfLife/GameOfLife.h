class GameOfLife
{
public:
  GameOfLife(int noOfXCells, int noOfYCells);
  ~GameOfLife();
  
  bool IsCellAlive(int x, int y);
  //void GiveCellLife(int x, int y);

protected:

private:
  const int noOfXCells;
  const int noOfYCells;
  bool* GameGrid;
  

  GameOfLife(const GameOfLife&);
  GameOfLife& operator=(const GameOfLife&);

  void CreateGrid();
  
};