#pragma once

#include <assert.h>
#include "constants.h"
#include "Tile.h"

using namespace std;

class Water : public Tile
{
public:
    // constructors
    Water(int x, int y);
private:
    // data members
    char symbol;

};