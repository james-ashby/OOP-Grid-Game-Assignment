#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

class HighScoreList
{

public:
    HighScoreList();
    const vector<pair<string, int>>& HighScoreList::GetHighScoreList();
    void AddToHighScoreList(string name, int score);
private:
    int score;
    ifstream ifhighScoreFile;
    ofstream ofhighScoreFile;
    string line;
    vector<pair<string, int>> highScores;
    vector<pair<string, int>> shortList;
    string name;

    void quickSort(vector<pair<string, int>>& A, int p, int q);
    int partition(vector<pair<string, int>>& A, int p, int q);


};

