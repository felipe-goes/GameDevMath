#include "Game.hpp"

int main()
{
  // Init game engine
  Game game = Game();

  // Functions
  game.update();
  game.render();

  return 0;
}
