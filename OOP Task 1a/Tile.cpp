#include "Tile.h"

int Tile::GetX()
{
    return x;
}

int Tile::GetY()
{
    return y;
}

char Tile::GetSymbol() const
{
    return symbol;
}

bool Tile::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}