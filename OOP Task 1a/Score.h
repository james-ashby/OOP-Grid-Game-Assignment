#pragma once
class Score
{
private:
    int score;
    int keysHeld;
public:
    Score(int initScore);
    int getScore();
    void Add(int howMuch);
    void Drop1();
    bool IsNull();
    int getKeysHeld();
    void addKey();

};

