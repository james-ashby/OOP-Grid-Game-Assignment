#pragma once

#include "constants.h"
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
        char GetSymbol() const;
        bool IsAtPosition(int x, int y);
        void setCurrentGrid(const vector<vector<char>>& currentGrid);
        // mutators
        void Move(int key);

        char symbol;
        int  x, y;
    private:
        // data members
        bool alive;
        bool escaped;
        int dx;
        int dy;
        vector<vector<char>> currentGrid;
        // supporting functions 
        void PositionInMiddleOfGrid();
        void UpdatePosition(int dx, int dy);

};