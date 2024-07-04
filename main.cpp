#include "include/Game/Game.hpp"
#include "include/GameStyles/European.hpp"
#include <memory>

int main() {

  Game game(std::make_unique<European>());
  game.start_game();
}
