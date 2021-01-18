#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

class HighScoreList
{
private:
    ifstream ifhighScoreFile;
    ofstream ofhighScoreFile;
    string line;
    vector<pair<string, int>> highScores;
    string name;
    int score;
    void quickSort(vector<pair<string, int>>& A, int p, int q);
    int partition(vector<pair<string, int>>& A, int p, int q);


public:
    HighScoreList();
    const vector<pair<string, int>>& GetHighScoreList();
    void AddToHighScoreList(string name, int score);
};

