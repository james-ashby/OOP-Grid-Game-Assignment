#include "Wall.h"

Wall::Wall()
{
}

Wall::Wall(int x, int y)
{
    symbol = WALL;
    this->x = x;
    this->y = y;
}

int Wall::GetX()
{
    return x;
}

int Wall::GetY()
{
    return y;
}

char Wall::GetSymbol() const
{
    return symbol;
}

bool Wall::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}