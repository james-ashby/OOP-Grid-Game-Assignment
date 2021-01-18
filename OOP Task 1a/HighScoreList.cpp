#include "HighScoreList.h"

HighScoreList::HighScoreList()
{
}

vector<int> HighScoreList::GetHighScoreList()
{
    
    highScoreFile.open("HighScores.txt");
    if (highScoreFile.is_open())
    {
        while (getline(highScoreFile,line)) // not a clue why this wont work, trying to google issue just gives 1000s pages of include string... it is included.
        {
            name = (line.substr(0, 4));
            score = stoi(line.substr(5, line.length()));
            //highScores.push_back(name, score);
        }
        highScoreFile.close();
    }
    else
    {

    }

    return vector<int>();
}


