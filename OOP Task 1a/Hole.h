#pragma once

#include <assert.h>
#include "constants.h"
#include "Tile.h"

using namespace std;

class Hole : public Tile
{
public:
    // constructors
    Hole(int x, int y);
private:
    // data members
    char symbol;

};