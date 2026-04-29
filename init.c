#include "main.h"

#include <stdio.h>
#include <stdlib.h>

#define ERR_X_SIZE_TOO_SMALL -1
#define ERR_X_SIZE_TOO_LARGE -2
#define ERR_Y_SIZE_TOO_SMALL -3
#define ERR_Y_SIZE_TOO_LARGE -4
#define ERR_ALLOC_FAILED -5

#define RESET "\e[0m"
#define RED "\e[31m"

char setup_game() {
  char
  result_of = setup_sizes();

  if (result_of == ERR_X_SIZE_TOO_SMALL)
    return !!fputs(RED"\n  X axis too small\n"RESET, stderr);
  if (result_of == ERR_X_SIZE_TOO_LARGE)
    return !!fputs(RED"\n  X axis too large\n"RESET, stderr);

  if (result_of == ERR_Y_SIZE_TOO_SMALL)
    return !!fputs(RED"\n  Y axis too small\n"RESET, stderr);
  if (result_of == ERR_Y_SIZE_TOO_LARGE)
    return !!fputs(RED"\n  Y axis too large\n"RESET, stderr);

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

  if (x <= SAFE_ZONE * 2)
    return ERR_X_SIZE_TOO_SMALL;
  if (x > 255)
    return ERR_X_SIZE_TOO_LARGE;

  fputs("  What is the height of your game?\n    ~> ", stdout);
  scanf("%hi", &y);

  if (y <= SAFE_ZONE * 2)
    return ERR_Y_SIZE_TOO_SMALL;
  if (y > 255)
    return ERR_Y_SIZE_TOO_LARGE;

  game.size.x = x;
  game.size.y = y;

  return SUCC;
}

char populate_grid() {
  game.grid = calloc(game.size.x * game.size.y, sizeof(char));
  if (game.grid == NULL) return ERR_ALLOC_FAILED;
  return SUCC;
}

