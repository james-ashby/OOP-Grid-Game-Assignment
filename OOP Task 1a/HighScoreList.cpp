#include "HighScoreList.h"

HighScoreList::HighScoreList()
{
}

void HighScoreList::quickSort(vector<pair<string, int>>& A, int p, int q)
{
    int r;
    if (p < q)
    {
        r = partition(A, p, q);
        quickSort(A, p, r);
        quickSort(A, r + 1, q);
    }
}

int HighScoreList::partition(vector<pair<string, int>>& A, int p, int q)
{
    int x = A[p].second;
    int i = p;
    int j;

    for (j = p + 1; j < q; j++)
    {
        if (A[j].second >= x)
        {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }

    swap(A[i], A[p]);
    return i;
}

const vector<pair<string, int>>& HighScoreList::GetHighScoreList()
{
    
    ifhighScoreFile.open("HighScores.txt");
    if (ifhighScoreFile.is_open())
    {
        while (getline(ifhighScoreFile,line))
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
    quickSort(highScores, 0, highScores.size());

    for (int i = 0; i < 5; i++)
    {
        shortList.push_back(make_pair(highScores[i].first, highScores[i].second)); // high score list is only so long so shouldnt need to pass the full list
    }

    return shortList;
}

void HighScoreList::AddToHighScoreList(string newName, int newScore)
{

    ofhighScoreFile.open("HighScores.txt", ofhighScoreFile.app);
    if (ofhighScoreFile.is_open())
    {
         ofhighScoreFile << "\n" << newName << newScore;
    }
    quickSort(highScores, 0, highScores.size());

}





