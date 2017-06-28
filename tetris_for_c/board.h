#pragma once
#include "block.h"
#include "point.h"
#include "size.h"

#define BOARD_POS_X (0)
#define BOARD_POS_Y (0)
#define BOARD_SIZE_WIDTH (10)
#define BOARD_SIZE_HEIGHT (20)

#define BOARD_POS ((point){BOARD_POS_X, BOARD_POS_Y})
#define BOARD_SIZE ((size){BOARD_SIZE_WIDTH, BOARD_SIZE_HEIGHT})

static point gameBoardPos;
static size gameBoardSize;
static int gameBoard[BOARD_SIZE_WIDTH+2][BOARD_SIZE_HEIGHT+2] = { 0, };

void initGameBoard(point pos, size size);
void drawGameBoard();
void drawGameOverScreen();
BOOL checkEmptyPlaceOnBoard(block clone);
void fixBlockOnBoard(block block);
int clearBlockLine();