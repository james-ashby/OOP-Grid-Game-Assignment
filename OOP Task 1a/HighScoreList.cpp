#include "HighScoreList.h"

HighScoreList::HighScoreList()
{
}

vector<pair<string, int>> HighScoreList::quickSort(vector<pair<string, int>> A, int p, int q)
{
    int r;
    if (p < q)
    {
        r = partition(A, p, q);
        quickSort(A, p, r);
        quickSort(A, r + 1, q);
    }
}

int HighScoreList::partition(vector<pair<string, int>> A, int p, int q)
{
    int x = A[p].second;
    int i = p;
    int j;

    for (j = p + 1; j < q; j++)
    {
        if (A[j].second <= x)
        {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }

    swap(A[i], A[j]);
    return i;
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
    return quickSort(highScores, 0, highScores.size() - 1);
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
    quickSort(highScores, 0, highScores.size() - 1);

}





