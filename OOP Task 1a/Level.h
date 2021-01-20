#pragma once
#include "Wall.h"
#include "Hole.h"
#include "Key.h"
#include "Coin.h"
#include "Door.h"
#include "Spike.h"
#include "Water.h"
#include <vector>
class Level
{
private:
    vector<Wall> walls;   
    vector<Hole> holes;
    vector<Key> keys;
    vector<Coin> coins;
    vector<Door> doors;
    vector<Spike> spikes;
    vector<Water> waters;
    bool spikesActive;
public:
    bool IsHoleAtPosition(int x, int y);
    bool IsKeyAtPosition(int x, int y);
    bool IsCoinAtPosition(int x, int y);
    bool IsWallAtPosition(int x, int y);
    bool IsDoorAtPosition(int x, int y);
    bool IsSpikeAtPosition(int x, int y);
    bool IsWaterAtPosition(int x, int y);
    void AddWall(int x, int y);
    void AddHole(int x, int y);
    void AddKey(int x, int y);
    void AddCoin(int x, int y);
    void AddWater(int x, int y);
    void AddSpike(int x, int y, char active);
    void RemoveKey(int x, int y);
    void RemoveCoin(int x, int y);
    vector<Spike> GetSpikes();
    void AddDoor(int x, int y);
    void ToggleSpikes();
    bool SpikesActive();

};

