#pragma once

#include <assert.h>
#include "constants.h"
#include "Tile.h"

using namespace std;

class Coin : public Tile
{
public:
    // constructors
    Coin(int x, int y);

private:
    // data members
    char symbol;
};
