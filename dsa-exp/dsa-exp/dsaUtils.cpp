#include <cstdlib>
#include "dsaUtils.h"

void RandomizeData(int* a, int cnt, unsigned int seed, int minValue, int maxValue)
{
	srand(seed);
	int u = rand();
	for (int i = 0; i < cnt; i++)
	{
		u = (int)((double)rand() / (double)(RAND_MAX + 1) * (maxValue - minValue)) + minValue;
		*(a + i) = u;
	}
}