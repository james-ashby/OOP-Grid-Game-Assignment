#pragma once

#include <assert.h>
#include "constants.h"
#include "Tile.h"
using namespace std;

class Wall : public Tile
{
    public:
        // constructors
        Wall();
        Wall(int x, int y);
    private:
        // data members
        char symbol;
        int x, y;
};