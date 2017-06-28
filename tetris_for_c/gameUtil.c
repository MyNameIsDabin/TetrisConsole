#include "gameUtil.h"
#include "common.h"

void initGame(const char* title, int width, int height)
{
	game.title = title;
	game.screenWidth = width;
	game.screenHeight = height;

	//�ܼ� Ÿ��Ʋ ����
	setTitle(game.title);

	//�ܼ� ũ�� ����
	setScreenSize(game.screenWidth, game.screenHeight);

	//���� ���尪 ����
	srand((unsigned)time(NULL));

	//Ŀ���� ������ �ʰ� �Ѵ�
	setCursorVisible(FALSE);
}

void clearScreen()
{
	//system("cls"); ������ ������
	int i;
	char strBuf[10];

	for (i = 0; i < game.screenHeight; i++)
	{
		setCursorPos(0, i);
		sprintf(strBuf, "%%%dc", game.screenWidth);
		printf(strBuf, ' ');
	}
}

void setTitle(const char* title)
{
	char strBuf[30] = "title ";
	strcat(strBuf, title);
	system(strBuf);
}

void setScreenSize(int width, int height)
{
	char strBuf[30];
	sprintf(strBuf, "mode con cols=%d lines=%d", width, height);
	system(strBuf);
}

void setCursorVisible(int visible)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void setCursorPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

point getCursorPos()
{
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;

	return (point) { curPoint.X, curPoint.Y };
}