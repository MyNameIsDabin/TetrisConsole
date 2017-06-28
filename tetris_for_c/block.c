#include "block.h"
#include "blockModel.h"
#include "gameUtil.h"

void redrawFixBlock(block block)
{
	int x, y;

	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			setCursorPos(block.posX + (x * 2), block.posY + y);

			if (blockModel[block.id+block.rotate][y][x] == 1)
				printf("бр");
		}
	}
}

void drawBlock(point pos, char model[][4])
{
	int x, y;

	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			setCursorPos(pos.x + (x * 2), pos.y + y);

			if (model[y][x] == 1)
				printf("бс");
		}
	}
}

void eraseBlock(point pos, char model[][4])
{
	int x, y;

	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			setCursorPos(pos.x + (x * 2), pos.y + y);

			if (model[y][x] == 1)
				printf(" ");
		}
	}
}