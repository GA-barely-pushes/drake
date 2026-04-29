#include "game.h"
#include "main.h"

#include <stdlib.h>

char update_grid() {
  if (game.snake.direction == NONE)
    return SUCC;

  char* p = game.grid;
  char* end = p + game.size.x * game.size.y;

  while (p < end)
    *p -= !!*p, p++;

  p = game.grid +
      game.snake.position.y *
      game.size.x +
      game.snake.position.x;

  if (*p > 0) return OOF;
  else if (*p < 0) {
    game.snake.length++;
    place_apple();
  };

  *p = game.snake.length;

  return SUCC;
}

void place_apple() {
  unsigned char x = rand() % game.size.x;
  unsigned char y = rand() % game.size.y;

  char* p = game.grid + y * game.size.x + x;

  if (*p)
    return place_apple();

  *p = -1;
}
