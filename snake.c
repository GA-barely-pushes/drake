#include "game.h"

#include <stdlib.h>
#include <time.h>

unsigned char generate_start_pos(const unsigned char axis_size) {
  return (rand() % (axis_size - SAFE_ZONE * 2)) + SAFE_ZONE;
}

void setup_snake() {
  srand(time(0));

  game.snake.length = 1;

  game.snake.position.x = generate_start_pos(game.size.x);
  game.snake.position.y = generate_start_pos(game.size.y);

  game.snake.direction = NONE;

  for (char i = 0; i < 5; i++)
    game.snake.direction_array
    [i][i < 2] = i & 1 ? -(i < 4) : i < 4;
}

void change_direction(char dir) {
  char uni_directional = game.snake.direction != NONE;
  char snake_long = game.snake.length > 1;
  char same_axis = (dir < 2) == (game.snake.direction < 2);

  if (uni_directional)
    if (snake_long)
      if (same_axis)
        return;

  game.snake.direction = dir;
}

unsigned char wrap(const short value, const unsigned char limit) {
  return value + 1 ? value % limit : limit - 1;
}

void update_snake() {
  _2D_* pp = &game.snake.position;
  char* dp = game.snake.direction_array[game.snake.direction];

  pp->x = wrap(pp->x + dp[0], game.size.x);
  pp->y = wrap(pp->y + dp[1], game.size.y);
}
