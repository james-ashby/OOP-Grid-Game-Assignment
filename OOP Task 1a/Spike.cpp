#include "Spike.h"

Spike::Spike(int x, int y, char active) : Tile(x, y, active)
{
	if (active == SPIKE)
	{
		this->symbol = SPIKE;
	}
	else if (active == SPIKEDOWN)
	{
		this->symbol = SPIKEDOWN;
	}
}

