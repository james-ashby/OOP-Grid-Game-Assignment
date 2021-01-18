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
    vector<pair<string, int>> quickSort(vector<pair<string, int>> A, int p, int q);
    int partition(vector<pair<string, int>> A, int p, int q);


public:
    HighScoreList();
    vector<pair<string, int>> GetHighScoreList();
    void AddToHighScoreList(string name, int score);
};

