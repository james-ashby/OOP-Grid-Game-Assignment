#pragma once

#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "Level.h"
#include "HighScoreList.h"

using namespace std;

class Game
{
   public:
       //accessors
        Player GetPlayer();
        vector<pair<string, int>> GetHighscoreList();
       //mutators
        void AddToHighScoreList(string, int);
        void Setup();
        void LoadLevel(vector<vector<char>> levelMap);
        void ProcessInput(int key, const vector<vector<char>>& currentGrid);
        Level CurrentLevelMap();
        bool LevelComplete();
        bool IsRunning();
        void ChangeLevel();
        void LevelRemoveKey();
        void LevelRemoveCoin();
        int GetScore();
        int GetCurrentLevel();
        int GetPlayerDirection();
        bool HasStarted();
        void StartGame();
        vector<vector<char>> PrepareGrid(Level level);
    private:
        //data members
        HighScoreList highscoreList;
        Player player;
        vector<Level> levels;
        int currentLevel = 0;
        bool started = false;
};