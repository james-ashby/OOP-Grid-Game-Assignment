#pragma once

#include "constants.h"
#include <vector>
#include "Score.h"

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
        void setCurrentGrid(const vector<vector<char>>& currentGrid);
        int getScore();
        void removeLife();
        // mutators
        void Move(int key);

        char symbol;
        int  x, y;
    private:
        // data members
        bool alive;
        int lives;
        bool escaped;
        int dx;
        int dy;
        Score score;
        vector<vector<char>> currentGrid;
        // supporting functions 
        void PositionInMiddleOfGrid();
        void UpdatePosition(int dx, int dy);

};