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
    void sortList();


public:
    HighScoreList();
    vector<pair<string, int>> GetHighScoreList();
    void AddToHighScoreList(string name, int score);
};

