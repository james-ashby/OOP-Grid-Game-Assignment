#include "HighScoreList.h"

HighScoreList::HighScoreList()
{
}

void HighScoreList::sortList()
{

}

vector<pair<string, int>> HighScoreList::GetHighScoreList()
{
    
    ifhighScoreFile.open("HighScores.txt");
    if (ifhighScoreFile.is_open())
    {
        while (getline(ifhighScoreFile,line)) // not a clue why this wont work, trying to google issue just gives 1000s pages of include string... it is included.
        {
            name = (line.substr(0, 4));
            score = stoi(line.substr(4, line.length()));
            highScores.push_back(make_pair(name, score));
        }
        ifhighScoreFile.close();
    }
    else
    {

    }
    sortList();
    return vector<pair<string, int>>();
}

void HighScoreList::AddToHighScoreList(string newName, int newScore)
{

    ofhighScoreFile.open("HighScores.txt", ofhighScoreFile.app);
    if (ofhighScoreFile.is_open())
    {
         ofhighScoreFile << "\n" << newName << newScore;
    }
    else
    {

    }
    sortList();

}





