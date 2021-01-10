#include "Score.h"

Score::Score(int initScore)
    : score(initScore), keysHeld(0)
{
}

int Score::getScore()
{
    return score;
}

void Score::Add100()
{
    score = score + 100;
}

void Score::Drop1()
{
    if (!(score <= 0))
    {
        score--;
    }
}

bool Score::IsNull()
{
    if (score <= 0) {
        return true;
    }
    else {
        return false;
    }
}

int Score::getKeysHeld()
{
    return keysHeld;
}

void Score::addKey()
{
    keysHeld++;
}
