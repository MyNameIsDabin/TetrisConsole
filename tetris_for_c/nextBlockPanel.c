#include "nextBlockPanel.h"
#include "blockModel.h"
#include "block.h"
#include "gameUtil.h"
#include "common.h"

void initNextBlockPanel(point pos)
{
	nextPanelPos = pos;

	updateRandomNextBlock();
}

void updateRandomNextBlock()
{
	eraseBlock((point) { nextPanelPos.x + 4, nextPanelPos.y + 2 }, blockModel[nextBlockId]);
	nextBlockId = random(0, 7) * 4;
}

void drawNextBlockPanel()
{
	int x = nextPanelPos.x;
	int y = nextPanelPos.y;

	setCursorPos(x, y);
	printf("NEXT");

	setCursorPos(x, y + 1);
	printf("式式式式式式式");

	drawBlock((point) { x + 4, y + 2 }, blockModel[nextBlockId]);

	setCursorPos(x, y + 5);
	printf("式式式式式式式");
}

int getNextBlockId()
{
	return nextBlockId;
}