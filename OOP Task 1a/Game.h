#pragma once

#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "Wall.h"
#include "Hole.h"
#include "RandomNumberGenerator.h"

using namespace std;

class Game
{
   public:
      Player player;
      vector<Wall> walls;
      vector<Hole> holes;
      void Setup();
      void SetMap();
      void ProcessInput(int key, const vector<vector<char>>& currentGrid);
      vector<vector<char>> PrepareGrid();
      bool IsRunning();
      bool IsWallAtPosition(int x, int y);
      int getScore();
      bool IsHoleAtPosition(int x, int y);

};