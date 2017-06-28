#include "common.h"

int random(int min, int max)
{
	int ret = (rand() % max) + min;
	return ret;
}

void flush()
{
	while (getchar() != '\n');
}