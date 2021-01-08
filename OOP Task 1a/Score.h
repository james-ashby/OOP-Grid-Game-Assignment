#pragma once
class Score
{
private:
    int score;
public:
    Score(int initScore);
    int getScore();
    void Add100();
    void Drop1();
    bool IsNull();

};

