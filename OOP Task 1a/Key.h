#pragma once

#include <assert.h>
#include "constants.h"
#include "Tile.h"

using namespace std;

class Key : public Tile
{
public:
    // constructors
    Key(int x, int y);

private:
    // data members
    char symbol;
};
