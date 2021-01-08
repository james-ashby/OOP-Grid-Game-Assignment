#pragma once

#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "Wall.h"

using namespace std;

class Game
{
   public:
      Player player;
      vector<Wall> walls;
      void Setup();
      void ProcessInput(int key, const vector<vector<char>>& currentGrid);
      vector<vector<char>> PrepareGrid();
      bool IsRunning();
      bool IsWallAtPosition(int x, int y);
};