#include "Score.h"

Score::Score(int initScore)
    : score(initScore)
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
