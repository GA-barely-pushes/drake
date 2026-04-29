#ifndef GAME_H
#define GAME_H

typedef struct {
  unsigned char x;
  unsigned char y;
} _2D_;

typedef struct {
  unsigned short length;
  _2D_ position;
  enum : char {UP, DOWN, RIGHT, LEFT, NONE} direction;
  char direction_array[5][2];
} snake;

#define SAFE_ZONE 3
typedef struct {
  char* grid;
  _2D_ size;
  snake snake;
} gameContext;

extern gameContext game;

#endif // !GAME_H
