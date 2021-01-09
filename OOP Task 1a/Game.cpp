#include "Game.h"

void Game::Setup()
{
    //walls.push_back(Wall(1, 1)); // 
    //walls.push_back(Wall(20, 20)); // == grid[19][19]
    //walls.push_back(Wall(10, 9)); // == grid[9][8]
    //walls.push_back(Wall(9, 15)); // == grid[8][14]
    //walls.push_back(Wall(15, 4)); // == grid[14][3]
    
    SetMap();
}

void Game::ProcessInput(int key, const vector<vector<char>>& currentGrid)
{
    player.setCurrentGrid(currentGrid);
    player.Move(key);
}

void Game::SetMap()
{
    vector<vector<char>> map1;

    vector<vector<char>> map2 = MAP2;

    RandomNumberGenerator random;
    int randomNum;

    for (int row = 1; row <= SIZE; ++row)
    {
        // create the inner vector to add to the 2D grid
        vector<char> line;

        // for each column, work out what's in that position and add the relevant char to the 2D grid
        for (int col = 1; col <= SIZE; ++col)
        {
            if (row == player.GetY() && col == player.GetX())
            {
                line.push_back(player.GetSymbol());
            }
            else if (randomNum = random.GetRandomValue(10) == 1)
            {
                line.push_back(WALL);
            }
            else
            {
                line.push_back(FLOOR);
            }
        }

        // now that the row is full, add it to the 2D grid
        map1.push_back(line);
    }

    for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            if (map2[x][y] == WALL)
            {
                walls.push_back(Wall(x, y));
            }
            if (map2[x][y] == HOLE)
            {
                holes.push_back(Hole(x, y));
            }
            if (map2[x][y] == KEY)
            {
                keys.push_back(Key(x, y));
            }
            if (map2[x][y] == DOOR)
            {
                doors.push_back(Door(x, y));
            }
        }
    }

}

/// <summary>
/// This function builds up a 2D grid of characters representing the current state of the game.
/// The characters are later used to decide which colour sqaure to display, but you could display images instead.
/// </summary>
vector<vector<char>> Game::PrepareGrid()
{
    // create the 2D grid
    vector<vector<char>> grid;

    // for each row
    for (int row = 0; row <= SIZE; ++row)
    {
        // create the inner vector to add to the 2D grid
        vector<char> line;

        // for each column, work out what's in that position and add the relevant char to the 2D grid
        for (int col = 0; col <= SIZE; ++col)
        {
            if (row == player.GetY() && col == player.GetX())
            {
                line.push_back(player.GetSymbol());
            }
            else if (IsWallAtPosition(row, col)) 
            {
                line.push_back(WALL);
            }
            else if (IsHoleAtPosition(row, col)) // TODO -- Refactor into one function that receives row,col,symbol and push_back(symbol)
            {
                line.push_back(HOLE);
            }
            else if (IsKeyAtPosition(row, col))
            {
                line.push_back(KEY);
            }
            else if(IsDoorAtPosition(row, col))
            {
                line.push_back(DOOR);
            }
            else
            {
                line.push_back(FLOOR);
            }
        }

        // now that the row is full, add it to the 2D grid
        grid.push_back(line);
    }

    return grid;
}

bool Game::IsWallAtPosition(int x, int y)
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
bool Game::IsHoleAtPosition(int x, int y)
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
bool Game::IsKeyAtPosition(int x, int y)
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

bool Game::IsDoorAtPosition(int x, int y)
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

bool Game::IsRunning()
{
    // depending on your game you'll need to modify this to return false
    // maybe it's when the player runs out of moves, maybe it's when they get caught, it's up to you!
    if (player.GetLives() == 0)
    {
        return false;
    }

    return true;
}

int Game::getScore()
{
    return player.getScore();
}