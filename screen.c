#include "screen.h"
#include <stdio.h>

void cursorGoTo(int x, int y) {
    printf("\033[%d;%dH", y, x);
    fflush(stdout);
}

void clearScreen() {
    printf("\033[2J");
    fflush(stdout);
}

void resetColors() {
    printf("\033[0m");
    fflush(stdout);
}

void setForeground(int color) {
    color = (color % 8) + 30;
    printf("\033[%dm", color);
    fflush(stdout);
}

void setBackground(int color) {
    color = (color % 8) + 40;
    printf("\033[%dm", color);
    fflush(stdout);
}

void printSpaces(int x) {
    for (int i = 0; i < x; i++) {
        printf(" ");
    }
}
