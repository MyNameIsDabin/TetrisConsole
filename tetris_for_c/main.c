#include "main.h"
#include "common.h"
#include "gameUtil.h"
#include "board.h"
#include "scorePanel.h"
#include "mainBlockManager.h"
#include "nextBlockPanel.h"
#include "keyController.h"

//화면 크기
#define SCREEN_WIDTH (39)
#define SCREEN_HEIGHT (22)

//새로운 블록이 생기는 위치
#define BLOCK_START_POS ((point){8, 1})

int main(void)
{
	initGame("테트리스", SCREEN_WIDTH, SCREEN_HEIGHT);

	initGameBoard(BOARD_POS, BOARD_SIZE);
	initScorePanel(SCORE_PANEL_POS);
	initNextBlockPanel(NEXT_PANEL_POS);
	initMainBlockWithPos(BLOCK_START_POS);

	while (1)
	{
		drawGameBoard();		//게임 판 그리기

		drawScorePanel();		//점수 판 그리기

		drawNextBlockPanel();	//다음 블록 그리기

		drawMainBlock();		//현재 블록 그리기

		if (isGameOver())
			break;
		
		checkInputKey();	//키보드 입력 처리

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