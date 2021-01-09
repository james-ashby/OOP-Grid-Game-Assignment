#pragma once

#include <assert.h>
#include "constants.h"
#include "Tile.h"

using namespace std;

class Door : public Tile
{
public:
    // constructors
    Door(int x, int y);
private:
    // data members
    char symbol;
};
