#pragma once

#include <stdio.h>
#include <windows.h>
#include "point.h"

typedef struct __block 
{
	int id;
	int posX;
	int posY;
	int rotate;
} block;

void redrawFixBlock(block block);
void drawBlock(point pos, char block[][4]);
void eraseBlock(point pos, char block[][4]);