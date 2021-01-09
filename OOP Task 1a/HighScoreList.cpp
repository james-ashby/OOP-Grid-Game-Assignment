#include "HighScoreList.h"


HighScoreList::HighScoreList()
{
}

vector<int> HighScoreList::GetHighScoreList()
{

    highScoreFile.open("HighScores.txt");
    if (highScoreFile.is_open())
    {
        while (getLine(highScoreFile,line)) // not a clue why this wont work, trying to google issue just gives 1000s pages of include string... it is included.
        {
            highScores.push_back(stoi(line));
        }
        highScoreFile.close();
    }
    else
    {

    }

    return vector<int>();
}


