#pragma once
#include <windows.h>
#include "point.h"

typedef struct __gameInfo 
{
	const char* title;
	int screenWidth;
	int screenHeight;
} gameInfo;

static gameInfo game;

void initGame(const char* title, int width, int height);
void clearScreen();
void setTitle(const char* title);
void setScreenSize(int width, int height);

void setCursorVisible(int visible);
void setCursorPos(int x, int y);
point getCursorPos();