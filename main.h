#ifndef MAIN_H
#define MAIN_H

#define OOF 1
#define SUCC 0

#include "game.h"

// init.c
char setup_game();
char setup_sizes();
char populate_grid();

// input.c
#define GET_OUT 'q'
char handle_input();

// snake.c
void setup_snake();
void change_direction(char dir);
void update_snake();

// game.c
char update_grid();
void place_apple();

// render.c
extern char out_str[24];
void render_game();

#endif // !MAIN_H
