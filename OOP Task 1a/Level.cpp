#include "Level.h"
bool Level::IsWallAtPosition(int x, int y)
{
    for (size_t i = 0; i < walls.size(); ++i)
    {
        if (walls[i].IsAtPosition(x, y))
        {
            return true;
        }
    }

    return false;
}
bool Level::IsDoorAtPosition(int x, int y)
{
    for (size_t i = 0; i < doors.size(); ++i)
    {
        if (doors[i].IsAtPosition(x, y))
        {
            return true;
        }
    }

    return false;
}
void Level::AddWall(int x, int y)
{
    walls.push_back(Wall(x, y));
}
void Level::AddHole(int x, int y)
{
    holes.push_back(Hole(x, y));
}
void Level::AddKey(int x, int y)
{
    keys.push_back(Key(x, y));
}
void Level::RemoveKey(int x, int y)
{
    for (int i = 0; i < keys.size(); i++)
    {
        if (keys[i].GetX() == x && keys[i].GetY() == y)
        {
            keys.erase(keys.begin() + i);
        }
    }
}
void Level::AddDoor(int x, int y)
{
    doors.push_back(Door(x, y));

}
bool Level::IsHoleAtPosition(int x, int y)
{
    for (size_t i = 0; i < holes.size(); ++i)
    {
        if (holes[i].IsAtPosition(x, y))
        {
            return true;
        }
    }

    return false;
}
bool Level::IsKeyAtPosition(int x, int y)
{
    for (size_t i = 0; i < keys.size(); ++i)
    {
        if (keys[i].IsAtPosition(x, y))
        {
            return true;
        }
    }

    return false;
}