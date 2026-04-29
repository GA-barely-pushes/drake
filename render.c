#include "game.h"

#include <stdio.h>

#define RESET "\e[0m"
#define GREEN "\e[32m"


void render_game() {
  // clear screen
  fputs("\e[H\e[2J", stdout);

  for (short y = game.size.y - 1; y + 1; y--) {
    for (short x = 0; x < game.size.x; x++) {
      char p = game.grid[y * game.size.x + x];
      if (p == game.snake.length)
        putchar('0');
      else if (p < 0)
        fputs(GREEN"@", stdout);
      else
        putchar(p ? 'o' : '.');

      fputs(RESET" ", stdout);
    }
    putchar('\n');
    putchar('\r');
  }
}
