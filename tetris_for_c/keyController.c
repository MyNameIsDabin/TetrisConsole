#include "keyController.h"
#include "mainBlockManager.h"
#include "common.h"
#include "key.h"
#include <conio.h>

#define INPUT_CHECK_PRECISION (100) //키를 입력받는 정밀도
#define BLOCK_DROP_DELAY (200)

void checkInputKey()
{
	int i, key;

	for (i = 0; i < BLOCK_DROP_DELAY; i++)
	{
		if (_kbhit() == TRUE)
		{
			key = _getch();

			switch (key)
			{
			case UP:
				rotateMainBlock();
				break;
			case LEFT:
				blockMoveToLeft();
				break;
			case RIGHT:
				blockMoveToRight();
				break;
			case DOWN:
				blockMoveToBottom();
				break;
			case SPACE:
				hardDropBlock();
				return;
			}
		}

		Sleep(BLOCK_DROP_DELAY / INPUT_CHECK_PRECISION);
	}
}