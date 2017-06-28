#include "scorePanel.h"
#include "gameUtil.h"
#include "common.h"

void initScorePanel(point pos)
{
	scorePanelPos = pos;
}

void drawScorePanel()
{
	char strBuf[30];

	setCursorPos(scorePanelPos.x, scorePanelPos.y);

	sprintf(strBuf, "SCORE %8d", score);
	printf(strBuf);
	setCursorPos(scorePanelPos.x, scorePanelPos.y + 1);

	printf("式式式式式式式"); 
	setCursorPos(scorePanelPos.x, scorePanelPos.y + 2);
}

void addScore(int clearLine)
{
	if (clearLine == 0)
		return;

	if (clearLine == 4) 
		score += 100;
	else if (clearLine == 3)
		score += 50;
	else
		score += 10;
}