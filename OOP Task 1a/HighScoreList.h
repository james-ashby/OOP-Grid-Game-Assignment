#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class HighScoreList
{
private:
    ofstream highScoreFile;
    string line;
    vector<int> highScores;

public:
    HighScoreList();
    vector<int> GetHighScoreList();
};

