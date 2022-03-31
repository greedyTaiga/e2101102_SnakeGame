#pragma once

enum COLORS { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

void cursorGoTo(int x, int y);
void clearScreen();
void resetColors();
void setForeground(int color);
void printSpaces(int x);