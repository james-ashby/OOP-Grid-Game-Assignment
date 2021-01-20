#include "Game.h"

void Game::Setup()
{
    LoadLevel(LEVELMAP1);
    LoadLevel(LEVELMAP2);
    LoadLevel(LEVELMAP3);
    LoadLevel(LEVELMAP4);
    LoadLevel(LEVELMAP5);
    highscoreList.GetHighScoreList();
}

void Game::ProcessInput(int key, const vector<vector<char>>& currentGrid)
{
    levels[currentLevel].ToggleSpikes(); // Better to do this with a timer
    player.SetCurrentGrid(currentGrid);
    player.Move(key);
}

void Game::LoadLevel(vector<vector<char>> levelMap)
{
    vector<vector<char>> map = levelMap;
    Level newLevel;

    for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            char currentTile = map[x][y];
            switch (currentTile) {
            case WALL:
                newLevel.AddTile(currentTile, x, y);
                break;
            case HOLE:
                newLevel.AddTile(currentTile, x, y);
                break;
            case KEY:
                newLevel.AddTile(currentTile, x, y);
                break;
            case COIN:
                newLevel.AddTile(currentTile, x, y);
                break;
            case DOOR:
                newLevel.AddTile(currentTile, x, y);
                break;
            case SPIKE:
                newLevel.AddTile(currentTile, x, y);
                break;
            case SPIKEDOWN:
                newLevel.AddTile(currentTile, x, y);
                break;
            case OCEAN:
                newLevel.AddTile(currentTile, x, y);
                break;
            }
        }
    }
    levels.push_back(newLevel);
}

/// <summary>
/// This function builds up a 2D grid of characters representing the current state of the game.
/// The characters are later used to decide which colour sqaure to display, but you could display images instead.
/// </summary>
vector<vector<char>> Game::PrepareGrid(Level level)
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
            else if (level.IsWallAtPosition(row, col))
            {
                line.push_back(WALL);
            }
            else if (level.IsHoleAtPosition(row, col)) // TODO -- Refactor into one function that receives row,col,symbol and push_back(symbol)
            {
                line.push_back(HOLE);
            }
            else if (level.IsKeyAtPosition(row, col))
            {
                line.push_back(KEY);
            }
            else if (level.IsCoinAtPosition(row, col)) {
                line.push_back(COIN);
            }
            else if (level.IsDoorAtPosition(row, col))
            {
                line.push_back(DOOR);
            }
            else if (level.IsWaterAtPosition(row, col))
            {
                line.push_back(OCEAN);
            }
            else if (level.IsSpikeAtPosition(row, col))
            {
                for each (Spike spike in level.GetSpikes())
                {
                    if (spike.GetX() == row && spike.GetY() == col)
                    {
                        if (level.SpikesActive() && spike.GetSymbol() == SPIKE)
                        {
                            line.push_back(SPIKEDOWN);

                        }
                        else if (level.SpikesActive() && spike.GetSymbol() == SPIKEDOWN)
                        {
                            line.push_back(SPIKE);
                        }
                        else
                        {
                            line.push_back(spike.GetSymbol());
                        }
                    }
                }
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

Level Game::CurrentLevelMap()
{
    return levels[currentLevel];
}

bool Game::LevelComplete()
{
    if (player.CheckComplete())
    {
        player.ResetCompleteFlag();
        return true;
    }
}

bool Game::IsRunning()
{
    // depending on your game you'll need to modify this to return false
    // maybe it's when the player runs out of moves, maybe it's when they get caught, it's up to you!
    if (player.GetLives() == 0)
    {
        return false;
    }
    else
    {
        return this->HasStarted();

    }
}

void Game::ChangeLevel()
{
    if (currentLevel < 4)
    {
        currentLevel++;
        player.MoveToSpawn();
    }
    else
    {
        started = false;
    }
}

void Game::LevelRemoveKey() {
    levels[currentLevel].RemoveKey(player.GetY(), player.GetX());
}

void Game::LevelRemoveCoin() {
    levels[currentLevel].RemoveCoin(player.GetY(), player.GetX());
}
int Game::GetScore()
{
    return player.GetScore();
}

int Game::GetCurrentLevel()
{
    return this->currentLevel + 1;
}

int Game::GetPlayerDirection()
{
    return player.GetDirection();
}

bool Game::HasStarted()
{
    return started;
}

void Game::StartGame()
{
    this->started = true;
}

Player Game::GetPlayer() 
{
    return this->player;
}