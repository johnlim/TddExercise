#include "CppUTest/TestHarness.h"
#include "GameOfLife.h"

TEST_GROUP(GameOfLifeEngine)
{
    
};

TEST(GameOfLifeEngine, GameGridIsCreatedWhenGameOfLifeIsInstantiated)
{
  GameOfLife game(2,3);
  CHECK_TRUE(game.GameGrid);
}