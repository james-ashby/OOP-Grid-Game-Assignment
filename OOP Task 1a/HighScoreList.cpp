#include "HighScoreList.h"

HighScoreList::HighScoreList()
{
}

vector<int> HighScoreList::GetHighScoreList()
{
    
    highScoreFile.open("HighScores.txt");
    if (highScoreFile.is_open())
    {
        while (getline(highScoreFile,line))
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


