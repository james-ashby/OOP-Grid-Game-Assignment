#pragma once
class Tile
{
    // assessors
    int GetX();
    int GetY();
    char GetSymbol() const;
    bool IsAtPosition(int x, int y);

private:
    // data members
    char symbol;
    int x, y;
};

