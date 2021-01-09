#pragma once

#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "Wall.h"
#include "Hole.h"
#include "RandomNumberGenerator.h"
#include "Key.h"
using namespace std;

class Game
{
   public:
      Player player;
      vector<Wall> walls;   // TODO - Level class, each level has vector of walls, holes and keys
      vector<Hole> holes;
      vector<Key> keys;
      void Setup();
      void SetMap();
      void ProcessInput(int key, const vector<vector<char>>& currentGrid);
      vector<vector<char>> PrepareGrid();
      bool IsRunning();
      bool IsWallAtPosition(int x, int y);
      int getScore();
      bool IsHoleAtPosition(int x, int y);
      bool IsKeyAtPosition(int x, int y);

};