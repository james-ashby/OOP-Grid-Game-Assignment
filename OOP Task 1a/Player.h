#pragma once

#include "constants.h"
#include "Score.h"
#include <vector>

using namespace std;
class Player
{
    public:
        // constructor
        Player();

        // assessors
        int GetX();
        int GetY();
        int GetLives();
        char GetSymbol() const;
        bool IsAtPosition(int x, int y);
        void SetCurrentGrid(const vector<vector<char>>& currentGrid);
        int GetScore();
        int GetDirection();
        void RemoveLife();

        // mutators
        void Move(int key);
        bool CheckComplete();
        void ResetCompleteFlag();
        void LevelCompleted();
        void MoveToSpawn();
        void ChangeDirection(int _direction);
        int GetKeys();
    private:
        // data members
        bool alive;
        int lives;
        bool escaped;
        int dx;
        int dy;
        int direction;
        bool levelComplete;
        int currentLevel;
        char symbol;
        int  x, y;
        Score score;
        vector<vector<char>> currentGrid;

        // supporting functions
        void UpdatePosition(int dx, int dy);
};