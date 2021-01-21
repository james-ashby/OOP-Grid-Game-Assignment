#include "Game.h"

#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <stdexcept> 
#include <sstream> 

void Game::Setup()
{
    //read in the levels from csv files
    //levels can be created in the level editor i made in a spreadsheet
    LoadLevel(LoadLevelFromFile("./assets/LEVEL2.csv"));
    LoadLevel(LoadLevelFromFile("./assets/LEVEL1.csv"));
    LoadLevel(LoadLevelFromFile("./assets/LEVEL3.csv"));
    LoadLevel(LoadLevelFromFile("./assets/LEVEL4.csv"));
    LoadLevel(LoadLevelFromFile("./assets/LEVEL5.csv"));
    highscoreList.GetHighScoreList();
}

void Game::ProcessInput(int key, const vector<vector<char>>& currentGrid)
{
    levels[currentLevel].ToggleSpikes(); // Toggle whether the spikes are active or inactive for each player movement
    player.SetCurrentGrid(currentGrid);  // Updates the players reference to the map, so they can detect the correct blocks
    player.Move(key);
}

void Game::LoadLevel(vector<vector<char>> levelMap)
{
    vector<vector<char>> map = levelMap;
    Level newLevel;

    // Adds tiles to the returned level based on the const map it receives
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
            else if (level.IsHoleAtPosition(row, col)) 
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
        player.ResetCompleteFlag(); // Resets the complete variable for the player so that they do not have the next level completed
        return true;
    }
}

bool Game::IsRunning()
{
    if (player.GetLives() == 0) // If the player runs out of lives, the game stops running
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
    if (currentLevel < 4) // Stops the game crashing by reaching level 6 (level cap is 5)
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
    levels[currentLevel].RemoveKey(player.GetY(), player.GetX()); // If the player is standing on a key tile, remove the key from the level vector of keys
}

void Game::LevelRemoveCoin() {
    levels[currentLevel].RemoveCoin(player.GetY(), player.GetX()); // If the player is standing on a coin (non-descript metal) tile, remove the coin from the level vector of coins
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

vector<pair<string,int>> Game::GetHighscoreList()
{
    return highscoreList.GetHighScoreList();
}

void Game::AddToHighScoreList(string name, int score)
{
    highscoreList.AddToHighScoreList(name, score);
}

vector<vector<char>> Game::LoadLevelFromFile(string level)
{
    string line = "";
    ifstream input;
    vector<char> lines = {};
    vector<vector<char>> grid = {};
    input.open(level);

    while (getline(input, line))
    {
        for (char c : line) {
            if (c != ',') {
                lines.push_back(c);
            }
            if (lines.size() > 19) {
                grid.push_back(lines);
                lines.clear();
            }
        }
    }

    input.close();

    return grid;
}