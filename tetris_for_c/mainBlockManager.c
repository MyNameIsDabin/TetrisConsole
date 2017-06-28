#include "mainBlockManager.h"
#include "board.h"
#include "blockModel.h"
#include "nextBlockPanel.h"
#include "common.h"

void initMainBlockWithPos(point startPos)
{
	mainBlock.id = random(0, 7) * 4;
	mainBlock.posX = startPos.x;
	mainBlock.posY = startPos.y;
	mainBlock.rotate = 0;

	setMainBlockStartPos(startPos);
}

void setMainBlockStartPos(point pos)
{
	mainBlockStartPos.x = pos.x;
	mainBlockStartPos.y = pos.y;
}

void fixWithAddMainBlock()
{
	fixBlockOnBoard(mainBlock);

	mainBlock.id = getNextBlockId();
	mainBlock.posX = mainBlockStartPos.x;
	mainBlock.posY = mainBlockStartPos.y;
	mainBlock.rotate = 0;

	updateRandomNextBlock();
}

BOOL blockMoveToLeft()
{
	BOOL isMoved = FALSE;
	block clone = mainBlock;
	clone.posX -= 2;

	eraseMainBlock();

	if (checkEmptyPlaceOnBoard(clone))
	{
		mainBlock.posX = clone.posX;
		isMoved = TRUE;
	}

	drawMainBlock();

	return isMoved;
}

BOOL blockMoveToRight()
{
	BOOL isMoved = FALSE;
	block clone = mainBlock;
	clone.posX += 2;

	eraseMainBlock();

	if (checkEmptyPlaceOnBoard(clone))
	{
		mainBlock.posX = clone.posX;
		isMoved = TRUE;
	}

	drawMainBlock();

	return isMoved;
}

BOOL blockMoveToBottom()
{
	BOOL isMoved = FALSE;
	block clone = mainBlock;
	clone.posY += 1;

	eraseMainBlock();

	if (checkEmptyPlaceOnBoard(clone))
	{
		mainBlock.posY = clone.posY;
		isMoved = TRUE;
	}

	drawMainBlock();

	return isMoved;
}

void hardDropBlock()
{
	while (blockMoveToBottom());
}

void rotateMainBlock()
{
	block clone = mainBlock;
	clone.rotate += 1;
	clone.rotate %= 4;

	eraseMainBlock();

	if (checkEmptyPlaceOnBoard(clone))
		mainBlock.rotate = clone.rotate;

	drawMainBlock();
}

void drawMainBlock()
{
	drawBlock((point){mainBlock.posX, mainBlock.posY}, blockModel[mainBlock.id + mainBlock.rotate]);
}

void eraseMainBlock()
{
	eraseBlock((point) { mainBlock.posX, mainBlock.posY }, blockModel[mainBlock.id + mainBlock.rotate]);
}

BOOL collidedMainBlock()
{
	return !checkEmptyPlaceOnBoard(mainBlock);
}