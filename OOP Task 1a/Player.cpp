#include "Player.h"
#include <vector>

Player::Player() : symbol(PLAYER), x(0), y(0), alive(true), escaped(false), dx(0), dy(0), score(100), lives(3), levelComplete(false), currentLevel(1)
{
    MoveToSpawn();
    direction = 3; // Reset the player sprite direction facing downward
}

int Player::GetX()
{
    return x;
}

int Player::GetY()
{
    return y;
}
int Player::GetLives()
{
    return lives;
}
char Player::GetSymbol() const
{
    return symbol;
}
bool Player::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}

void Player::SetCurrentGrid(const vector<vector<char>>& currentGrid)
{
    this->currentGrid = currentGrid;
}
void Player::RemoveLife() {
    lives--;
}
void Player::Move(int key)
{
    switch (key)
    {
    case KEY_LEFT:
        dx = -1;
        dy = 0;
        ChangeDirection(4);
        break;
    case KEY_RIGHT:
        dx = +1;
        dy = 0;
        ChangeDirection(2);
        break;
    case KEY_UP:
        dx = 0;
        dy = -1;
        ChangeDirection(1);
        break;
    case KEY_DOWN:
        dx = 0;
        dy = +1;
        ChangeDirection(3);
        break;
    default:
        // not a key we care about, so do nothing
        break;
    }

    // update player coordinates if move is possible
    if (((x + dx) >= 0) && ((x + dx) < SIZE) && ((y + dy) >= 0) && ((y + dy) < SIZE))
    {
        int nextY = y + dy;  
        int nextX = x + dx; 

        if (this->currentGrid[nextY][nextX] != WALL && this->currentGrid[nextY][nextX] != DOOR && this->currentGrid[nextY][nextX] != OCEAN) { // Update position if the next tile is not a wall, to avoid players walking through walls
            UpdatePosition(dx, dy);                    // Only updates position if the next tile is a valid tile (not locked door/wall/water)
        }

		if (this->currentGrid[nextY][nextX] == KEY)  
		{
			score.Add(100);
            score.addKey();
            this->currentGrid[nextY][nextX] = FLOOR; // Set the key on the next tile to be a floor tile, to update the map when it is picked up
		}
        if (this->currentGrid[nextY][nextX] == COIN)  
        {
            score.Add(50);
            this->currentGrid[nextY][nextX] = FLOOR; // Set the coin on the next tile to be a floor tile, to update the map when it is picked up
        }
		if (this->currentGrid[nextY][nextX] == HOLE || this->currentGrid[nextY][nextX] == SPIKEDOWN) // If the player moves onto a hole, remove a life and respawn them
		{
			RemoveLife();
			MoveToSpawn();
		}
        if (this->currentGrid[nextY][nextX] == DOOR && this->GetKeys() == this->currentLevel) // One key per level, therefore if the player amount of keys matches the level, allow them to complete the level
        {
           this->LevelCompleted();
        }

        if (!(score.getScore() <= 0))
        {
            score.Drop1();
        }

    }
}

void Player::ChangeDirection(int _direction)
{
    direction = _direction;
}

int Player::GetDirection() 
{
    return direction;
}

bool Player::CheckComplete()
{
    return this->levelComplete;
}

void Player::ResetCompleteFlag()
{
    this->levelComplete = false;
}

void Player::LevelCompleted()
{
    currentLevel++;
    this->levelComplete = true;
}


void Player::UpdatePosition(int dx, int dy)
{
	x += dx;
	y += dy;
}

void Player::MoveToSpawn()
{
    x = SIZE / 2;
    y = SIZE / 2;
}

int Player::GetKeys()
{
    return this->score.getKeysHeld();
}

int Player::GetScore()
{
    return score.getScore();
}