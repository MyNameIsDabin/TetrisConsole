#include "main.h"
#include "common.h"
#include "gameUtil.h"
#include "board.h"
#include "scorePanel.h"
#include "mainBlockManager.h"
#include "nextBlockPanel.h"
#include "keyController.h"

//ȭ�� ũ��
#define SCREEN_WIDTH (39)
#define SCREEN_HEIGHT (22)

//���ο� ����� ����� ��ġ
#define BLOCK_START_POS ((point){8, 1})

int main(void)
{
	initGame("��Ʈ����", SCREEN_WIDTH, SCREEN_HEIGHT);

	initGameBoard(BOARD_POS, BOARD_SIZE);
	initScorePanel(SCORE_PANEL_POS);
	initNextBlockPanel(NEXT_PANEL_POS);
	initMainBlockWithPos(BLOCK_START_POS);

	while (1)
	{
		drawGameBoard();		//���� �� �׸���

		drawScorePanel();		//���� �� �׸���

		drawNextBlockPanel();	//���� ��� �׸���

		drawMainBlock();		//���� ��� �׸���

		if (isGameOver())
			break;
		
		checkInputKey();	//Ű���� �Է� ó��

		if (blockMoveToBottom() == FALSE)
		{
			fixWithAddMainBlock();
		}

		addScore(clearBlockLine());
	}

	drawGameOverScreen();

	flush();
	return 0;
}

BOOL isGameOver()
{
	return collidedMainBlock();
}