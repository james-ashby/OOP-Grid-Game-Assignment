#pragma once
#include "Wall.h"
#include "Hole.h"
#include "Key.h"
#include <vector>
class Level
{
private:
    vector<Wall> walls;   // TODO - Level class, each level has vector of walls, holes and keys
    vector<Hole> holes;
    vector<Key> keys;
public:
    bool IsHoleAtPosition(int x, int y);
    bool IsKeyAtPosition(int x, int y);
    bool IsWallAtPosition(int x, int y);
    void AddWall(int x, int y);
    void AddHole(int x, int y);
    void AddKey(int x, int y);

};

