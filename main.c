#include <stdlib.h>
#include <unistd.h>

#include "terminal_mode.h"
#include "main.h"

gameContext game;

int main() {
  if (setup_game() == OOF)
    return OOF;
  setup_terminal_mode();

run_game:
  if (handle_input() == GET_OUT)
    goto exit;

  update_snake();

  if (update_grid() == OOF)
    goto exit;

  render_game();

  usleep(125000);
  goto run_game;

exit:
  reset_mode();
  free(game.grid);
  return 0;
}
