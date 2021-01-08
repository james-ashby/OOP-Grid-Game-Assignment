#pragma once
class Tile
{
    // assessors
    
public:
    Tile::Tile(int x, int y) : x(x), y(y)
    {

    };
    int GetX();
    int GetY();
    char GetSymbol() const;
    bool IsAtPosition(int x, int y);
private:
    // data members
    char symbol;
    int x, y;
};

