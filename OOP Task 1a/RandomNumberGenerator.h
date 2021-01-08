#pragma once

#include <stdlib.h>
#include <assert.h>
#include <time.h>

using namespace std;

class RandomNumberGenerator
{
    public:
        // constructors
        RandomNumberGenerator();

        // assessors
        int GetRandomValue(int) const;

    private:
        // supporting functions
        void Seed();
};