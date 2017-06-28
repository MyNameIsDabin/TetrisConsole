#pragma once
#include "point.h"

#define NEXT_PANEL_POS_X (24)
#define NEXT_PANEL_POS_Y (4)
#define NEXT_PANEL_POS ((point){NEXT_PANEL_POS_X, NEXT_PANEL_POS_Y})

static int nextBlockId;
static point nextPanelPos;

void initNextBlockPanel(point pos);
void updateRandomNextBlock();
void drawNextBlockPanel();
int getNextBlockId();