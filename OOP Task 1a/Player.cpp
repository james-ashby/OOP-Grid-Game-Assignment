#include "Player.h"
#include <vector>

Player::Player() : symbol(PLAYER), x(0), y(0), alive(true), escaped(false), dx(0), dy(0), score(100), lives(3), levelComplete(false)
{
    MoveToSpawn();
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
        break;
    case KEY_RIGHT:
        dx = +1;
        dy = 0;
        break;
    case KEY_UP:
        dx = 0;
        dy = -1;
        break;
    case KEY_DOWN:
        dx = 0;
        dy = +1;
        break;
    default:
        // not a key we care about, so do nothing
        break;
    }

    // update mouse coordinates if move is possible
    if (((x + dx) >= 0) && ((x + dx) < SIZE) && ((y + dy) >= 0) && ((y + dy) < SIZE))
    {
        int nextY = y + dy;  // Had to save the next values to stop vector errors
        int nextX = x + dx; 

        if (this->currentGrid[nextY][nextX] != WALL) { // Update position if the next tile is not a wall, to avoid players walking through walls
            UpdatePosition(dx, dy);                    // Only update position here to avoid double movement
        }

		if (this->currentGrid[nextY][nextX] == KEY)  // TODO -- Add key to player class (vector of keys -- reset on level change
		{
            this->LevelCompleted();
			score.Add100();
		}
		if (!(score.getScore() <= 0))
		{
			score.Drop1();
		}

		if (this->currentGrid[nextY][nextX] == HOLE) // If the player moves onto a hole, remove a life and respawn them
		{
			RemoveLife();
			MoveToSpawn();
		}

    }
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

int Player::GetScore()
{
    return score.getScore();
}