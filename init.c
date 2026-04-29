#include "main.h"

#include <stdio.h>
#include <stdlib.h>

#define ERR_X_SIZE -1
#define ERR_Y_SIZE -2
#define ERR_ALLOC_FAILED -3

char setup_game() {
  char
  result_of = setup_sizes();

  if (result_of == ERR_X_SIZE)
    return !!fputs("X axis too large or too small\n", stderr);

  if (result_of == ERR_Y_SIZE)
    return !!fputs("Y axis too large or too small\n", stderr);

  result_of = populate_grid();

  if (result_of == ERR_ALLOC_FAILED)
    return !!fputs("allocation failed!\n", stderr);

  setup_snake();

  game.grid
  [game.snake.position.y *
   game.size.x +
   game.snake.position.x] = game.snake.length;

  place_apple();

  return SUCC;
}

char setup_sizes() {
  short x, y;

  fputs("  What is the width of your game?\n    ~> ", stdout);
  scanf("%hi", &x);
  fputs("  What is the height of your game?\n    ~> ", stdout);
  scanf("%hi", &y);

  if (x > 255 || x <= SAFE_ZONE * 2)
    return ERR_X_SIZE;
  if (y > 255 || y <= SAFE_ZONE * 2)
    return ERR_Y_SIZE;

  game.size.x = x;
  game.size.y = y;

  return SUCC;
}

char populate_grid() {
  game.grid = calloc(game.size.x * game.size.y, sizeof(char));
  if (game.grid == NULL) return ERR_ALLOC_FAILED;
  return SUCC;
}

