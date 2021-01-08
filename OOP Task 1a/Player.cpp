#include "Player.h"
#include <vector>

Player::Player() : symbol(PLAYER), x(0), y(0), alive(true), escaped(false), dx(0), dy(0), score(100)
{
    PositionInMiddleOfGrid();
}

int Player::GetX()
{
    return x;
}

int Player::GetY()
{
    return y;
}

char Player::GetSymbol() const
{
    return symbol;
}
bool Player::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}

void Player::setCurrentGrid(const vector<vector<char>>& currentGrid)
{
    this->currentGrid = currentGrid;
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
    if (((x + dx) >= 1) && ((x + dx) <= SIZE) && ((y + dy) >= 1) && ((y + dy) <= SIZE))
    {
        if (this->currentGrid[y + dy - 1 ][x + dx - 1] != WALL) { // Vector subscript out of range because right and down keys add to vector, reaching 20 which is out of vector bounds
            if(this->currentGrid[y + dy - 1][x + dx - 1] == KEY)
            {
                score.Add100();
            }
            if (!(score.getScore() <= 0))
            {
                UpdatePosition(dx, dy);
                score.Drop1();
            }
        }
    }

}


void Player::UpdatePosition(int dx, int dy)
{
	x += dx;
	y += dy;
}

void Player::PositionInMiddleOfGrid()
{
    x = SIZE / 2;
    y = SIZE / 2;
}

int Player::getScore()
{
    return score.getScore();
}