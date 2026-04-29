#include "kbhit.h"

#include <termios.h>
#include <sys/select.h>
#include <unistd.h>

char kbhit() {
  struct timeval tv = { 0, 0 };
  fd_set fds;

  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);

  return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
}
