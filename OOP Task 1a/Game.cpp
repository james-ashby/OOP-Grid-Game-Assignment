#include "Game.h"

void Game::Setup()
{
    walls.push_back(Wall(1, 1)); // 
    walls.push_back(Wall(20, 20)); // == grid[19][19]
    walls.push_back(Wall(10, 9)); // == grid[9][8]
    walls.push_back(Wall(9, 15)); // == grid[8][14]
    walls.push_back(Wall(15, 4)); // == grid[14][3]
}

void Game::ProcessInput(int key, const vector<vector<char>>& currentGrid)
{
    player.setCurrentGrid(currentGrid);
    player.Move(key);
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
            else if (IsWallAtPosition(row, col)) // Switched to row-col for correct?/easier translation to grid
            {
                line.push_back(WALL);
            }
            else if (row == 6 && col == 10) // == hole at grid[5][9]
            {
                line.push_back(HOLE);
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

bool Game::IsRunning()
{
    // depending on your game you'll need to modify this to return false
    // maybe it's when the player runs out of moves, maybe it's when they get caught, it's up to you!
    return true;
}