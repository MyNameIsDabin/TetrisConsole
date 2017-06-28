#include "board.h"
#include "blockModel.h"
#include "gameUtil.h"
#include "common.h"
#include <windows.h>

void initGameBoard(point pos, size size)
{
	int x, y;

	gameBoardPos = pos;
	gameBoardSize = size;

	for (x = 0; x < gameBoardSize.width + 2; x++)
	{
		for (y = 0; y < gameBoardSize.height + 2; y++)
		{
			if (x == 0 || x == gameBoardSize.width + 1
				|| y == 0 || y == gameBoardSize.height + 1)
				gameBoard[x][y] = 1;
		}
	}
}

void drawGameBoard()
{
	int x, y;

	for (x = 0; x < gameBoardSize.width + 2; x++)
	{
		for (y = 0; y < gameBoardSize.height + 2; y++)
		{
			setCursorPos(gameBoardPos.x + (x*2), gameBoardPos.y + y);

			if (x == 0 && y == 0)
				printf("┌");
			else if (x == gameBoardSize.width+1 && y == 0)
				printf("┐");
			else if (y == gameBoardSize.height+1 && x == 0)
				printf("└");
			else if (x == gameBoardSize.width+1 && y == gameBoardSize.height+1)
				printf("┘");
			else if (x == 0 || x == gameBoardSize.width+1)
				printf("│");
			else if (y == 0 || y == gameBoardSize.height + 1)
				printf("─");
			else if (gameBoard[x][y] == 0)
				printf(" ");
			else if (gameBoard[x][y] == 2)
				printf("□");
		}
	}
}

void drawGameOverScreen()
{
	int x, y;
	int posX, posY;

	posX = gameBoardSize.width;
	posY = gameBoardSize.height / 2;

	for (y = gameBoardSize.height; y > 0; y--)
	{
		if (posY == y)
			continue;

		for (x = 1; x < gameBoardSize.width + 1; x++)
		{
			setCursorPos(gameBoardPos.x + (x*2), gameBoardPos.y + y);
			printf("■");
		}

		Sleep(50);
	}

	setCursorPos(posX - 2, posY);
	printf("GAME OVER");
}

BOOL checkEmptyPlaceOnBoard(block clone)
{
	int x, y;
	int piecePosX, piecePosY;

	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			piecePosX = (clone.posX)/2 - (gameBoardPos.x)/2 + x;
			piecePosY = clone.posY - gameBoardPos.y + y;

			if (blockModel[clone.id+clone.rotate][y][x] == 1)
			{
				if (gameBoard[piecePosX][piecePosY] != 0)
					return FALSE;
			}
		}
	}

	return TRUE;
}

void fixBlockOnBoard(block block)
{
	int x, y;
	int piecePosX, piecePosY;

	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			piecePosX = (block.posX) / 2 - (gameBoardPos.x) / 2 + x;
			piecePosY = block.posY - gameBoardPos.y + y;

			if (blockModel[block.id + block.rotate][y][x] == 1)
				gameBoard[piecePosX][piecePosY] = 2;
		}
	}

	redrawFixBlock(block);
}

int clearBlockLine()
{
	int y, x;
	int t;
	int numOfClearLine = 0;

	for (y = gameBoardSize.height; y > 1; y--)
	{
		for (x = 1; x < gameBoardSize.width + 1; x++)
		{
			if (gameBoard[x][y] == 0)
				break;
		}

		//비워진 라인 위에 블록들을 그대로 내린다.
		if (x == gameBoardSize.width + 1)
		{
			for (x = 1; x < gameBoardSize.width + 1; x++)
			{
				for (t = y; t > 1; t--)
				{
					gameBoard[x][t] = gameBoard[x][t - 1];
				}
			}

			y++;

			numOfClearLine++;
		}
	}

	return numOfClearLine;
}