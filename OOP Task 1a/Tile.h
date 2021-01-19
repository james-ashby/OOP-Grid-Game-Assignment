#pragma once
class Tile
{
    // assessors
    
public:
    Tile::Tile(int x, int y) : x(x), y(y)
    {

    };
    Tile::Tile(int x, int y, char symbol) : x(x), y(y), symbol(symbol)
    {

    };
    int GetX();
    int GetY();
    char GetSymbol();
    bool IsAtPosition(int x, int y);
private:
    // data members
    char symbol;
    int x, y;
};

