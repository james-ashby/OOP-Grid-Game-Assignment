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
bool Level::IsSpikeAtPosition(int x, int y)
{
    for (size_t i = 0; i < spikes.size(); ++i)
    {
        if (spikes[i].IsAtPosition(x, y))
        {
            return true;
        }
    }

    return false;
}
bool Level::IsWaterAtPosition(int x, int y)
{
    for (size_t i = 0; i < waters.size(); ++i)
    {
        if (waters[i].IsAtPosition(x, y))
        {
            return true;
        }
    }
    return false;
}

void Level::AddTile(char tile, int x, int y)
{
    switch (tile) {
    case WALL:
        walls.push_back(Wall(x, y));
        break;
    case HOLE:
        holes.push_back(Hole(x, y));
        break;
    case KEY:
        keys.push_back(Key(x, y));
        break;
    case COIN:
        coins.push_back(Coin(x, y));
        break;
    case DOOR:
        doors.push_back(Door(x, y));
        break;
    case SPIKE:
        spikes.push_back(Spike(x, y, tile));
        break;
    case SPIKEDOWN:
        spikes.push_back(Spike(x, y, tile));
        break;
    case OCEAN:
        waters.push_back(Water(x, y));
        break;
    }
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

void Level::RemoveCoin(int x, int y)
{
    for (int i = 0; i < coins.size(); i++)
    {
        if (coins[i].GetX() == x && coins[i].GetY() == y)
        {
            coins.erase(coins.begin() + i);
        }
    }
}

vector<Spike> Level::GetSpikes()
{
    return spikes;
}

void Level::ToggleSpikes()
{
    spikesActive = !spikesActive;
}
bool Level::SpikesActive()
{
    return spikesActive;
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
bool Level::IsCoinAtPosition(int x, int y)
{
    for (size_t i = 0; i < coins.size(); ++i)
    {
        if (coins[i].IsAtPosition(x, y))
        {
            return true;
        }
    }

    return false;
}