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
