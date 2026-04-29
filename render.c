#include "game.h"

#include <stdio.h>

#define RESET "\e[0m"
#define GREEN "\e[32m"


void render_game() {
  // clear screen
  printf("\e[H\e[2J");

  printf("╭");
  for (unsigned char i = 0; i < game.size.x; i++)
    printf("──");
  printf("╮\r\n");

  // draw borders
  for (short y = game.size.y - 1; y + 1; y--) {
    printf("│");
    for (short x = 0; x < game.size.x; x++) {
      char p = game.grid[y * game.size.x + x];
      printf("%s%s"RESET, p < 0 ? GREEN : "", p ? "██" : "  ");
    }
    printf("│\n\r");
  }

  printf("╰");
  for (unsigned char i = 0; i < game.size.x; i++)
    printf("──");
  printf("╯\r\n");

  printf("\e[%dC", game.size.x - 4);
  printf("\nscore: %03d\n", game.snake.length - 1);
  printf("\e[13DPress [Q] to Quit\n\r");
}
