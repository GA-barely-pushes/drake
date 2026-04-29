#include "kbhit.h"
#include "main.h"

#include <stdio.h>

char handle_input() {
  while (kbhit()) {
    char ch = getchar();

    if (ch == 'q')
      return GET_OUT;

    if (ch == '\x1b')
      switch (getchar(), getchar()) {
        case 'A':
          change_direction(UP);
          break;
        case 'B':
          change_direction(DOWN);
          break;
        case 'C':
          change_direction(RIGHT);
          break;
        case 'D':
          change_direction(LEFT);
          break;
      }
  }
  return SUCC;
}
