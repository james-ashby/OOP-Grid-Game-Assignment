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
    ifstream highScoreFile;
    string line;
    vector<string, int> highScores;
    int score;
    string name;

public:
    HighScoreList();
    vector<int> GetHighScoreList();
};

