class GameOfLife
{
public:
  GameOfLife(int noOfXCells, int noOfYCells);
  ~GameOfLife();
  
  int* GameGrid;

protected:

private:
  const int noOfXCells;
  const int noOfYCells;
  

  GameOfLife(const GameOfLife&);
  GameOfLife& operator=(const GameOfLife&);

  void CreateGrid();
};