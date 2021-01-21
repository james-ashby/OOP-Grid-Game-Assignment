#pragma once
class Score
{
public:
    Score(int initScore);
    int getScore();
    void Add(int howMuch);
    void Drop1();
    bool IsNull();
    int getKeysHeld();
    void addKey();
private:
    int score;
    int keysHeld;
};

