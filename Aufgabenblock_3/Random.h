#pragma once
#include <stdlib.h>

/*
iRandom function creates a random integer value between the fed minumum and maximum value arguments.
*/
int iRandom(int min = 1, int max = 10)
{
	return min + (rand() % (max - min + 1));
}