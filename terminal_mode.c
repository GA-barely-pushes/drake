#include "terminal_mode.h"
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

struct termios old_t;

void setup_terminal_mode() {
  tcgetattr(STDOUT_FILENO, &old_t);
  struct termios new_t;
  cfmakeraw(&new_t);
  tcsetattr(STDOUT_FILENO, TCSANOW, &new_t);
  fputs("\e[?25l", stdout);
}

void reset_mode() {
  tcsetattr(STDOUT_FILENO, TCSANOW, &old_t);
  fputs("\e[?25h", stdout);
}
