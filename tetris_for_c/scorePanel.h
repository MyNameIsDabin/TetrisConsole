#pragma once
#include "point.h"

#define SCORE_PANEL_POS_X (24)
#define SCORE_PANEL_POS_Y (1)
#define SCORE_PANEL_POS ((point){SCORE_PANEL_POS_X, SCORE_PANEL_POS_Y})

static int score = 0;
static point scorePanelPos;

void initScorePanel(point pos);
void drawScorePanel();
void addScore(int clearLine);