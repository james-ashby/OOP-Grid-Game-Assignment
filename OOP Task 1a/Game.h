#pragma once

#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "RandomNumberGenerator.h"
#include "Level.h"
using namespace std;

class Game
{
   public:
      Player player;
      void Setup();
      void LoadLevel(vector<vector<char>> levelMap);
      void ProcessInput(int key, const vector<vector<char>>& currentGrid);
      vector<vector<char>> PrepareGrid(Level level);
      Level CurrentLevelMap();
      bool LevelComplete();
      bool IsRunning();
      void ChangeLevel();
      void LevelRemoveKey();
      int GetScore();
      int GetCurrentLevel();
      int GetPlayerDirection();
private:
    vector<Level> levels;
    int currentLevel = 0;

};