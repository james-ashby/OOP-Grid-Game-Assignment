#pragma once
#include "Tile.h"
#include <assert.h>
#include "constants.h"

using namespace std;
class Spike : public Tile
{
public:
    // constructors
    Spike(int x, int y);

private:
    // data members
    char symbol;
};


