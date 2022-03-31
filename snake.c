#include "snake.h"
#include "screen.h"
#include <conio.h>
#include <stdio.h>

struct snake init_snake(int len) {
	struct snake s;

	s.length = len;

	s.head.x = ARENA_WIDTH / 2;
	s.head.y = ARENA_HEIGHT / 2;

	for (int i = 0; i < len; i++) {
		s.body[i].x = ARENA_WIDTH / 2 - 1 - i;
		s.body[i].y = ARENA_HEIGHT / 2;
	}

	return s;
}

struct snake move(struct snake s, int dir) {
	struct snake ns;
	ns.length = s.length;
	ns.head = s.head;

	if (dir == UP) {
		ns.head.y--;
	}
	else if (dir == DOWN) {
		ns.head.y++;
	}
	else if (dir == LEFT) {
		ns.head.x--;
	}
	else if (dir == RIGHT) {
		ns.head.x++;
	}
	ns.body[0] = s.head;

	for (int i = 1; i < s.length; i++) {
		ns.body[i] = s.body[i - 1];
	}

	return ns;
}

int isDead(struct snake s) {

	for (int i = 0; i < s.length; i++) {
		if (s.head.x == s.body[i].x && s.head.y == s.body[i].y) {
			return 1;
		}
	}
	if (s.head.y <= 0 || s.head.y > ARENA_HEIGHT) {
		return 1;
	}
	if (s.head.x <= 0 || s.head.x > ARENA_WIDTH) {
		return 1;
	}
	return 0;
}

void draw(struct snake s) {
	clearScreen();

	//print head
	setBackground(RED);
	cursorGoTo(s.head.x, s.head.y);
	printf(" ");

	//print the rest of the body
	setBackground(YELLOW);

	for (int i = 0; i < s.length; i++) {
		cursorGoTo(s.body[i].x, s.body[i].y);
		printf(" ");
	}
	resetColors();
}

int input_key(void) {
	while (1) {
		int k = _getch();
		if (k == KEY_EXT) {
			k = _getch();
			if (k == UP || k == LEFT || k == RIGHT || k == DOWN) {
				return k;
			}
		}
	}
	return 0;
}

void you_died() {
	clearScreen();
	setForeground(RED);
	cursorGoTo(ARENA_WIDTH / 2, ARENA_HEIGHT / 2);
	printf("You died, what a loser!");
	resetColors();

}