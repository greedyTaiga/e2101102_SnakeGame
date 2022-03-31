#include <stdio.h>
#include "snake.h"

int main(void) {
	struct snake s = init_snake(15);
	
	while (1) {

		draw(s);
		int k = input_key();
		s = move(s, k);

		if (isDead(s)) {
			you_died();
			break;
		}
	}
}