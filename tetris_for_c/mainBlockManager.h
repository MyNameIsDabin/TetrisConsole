#pragma once
#include "block.h"
#include "point.h"

static block mainBlock;
static point mainBlockStartPos;

void initMainBlockWithPos(point startPos);
void setMainBlockStartPos(point pos);
void fixWithAddMainBlock();
BOOL blockMoveToBottom();
BOOL blockMoveToLeft();
BOOL blockMoveToRight();
void hardDropBlock();
void rotateMainBlock();
void drawMainBlock();
void eraseMainBlock();
BOOL collidedMainBlock();