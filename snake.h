#pragma once
#define _CRT_SECURE_NO_WARNINGS

//constant definitions
#define ARENA_HEIGHT 30
#define ARENA_WIDTH 120

#define INIT_SNAKE_LENGTH 5

#define KEY_EXT 224
enum ARROW {UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80};



//struct definitions
struct coord {
	int x, y;
};

struct snake {
	int length;
	struct coord head;
	struct coord body[ARENA_HEIGHT * ARENA_WIDTH];
};


//function declarations
struct snake init_snake(int len);
int input_ley(void);
struct snake move(struct snake s, int k);
int isDead(struct snake s);
void you_died();
