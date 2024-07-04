#include "include/Game/Game.hpp"
#include "include/GameStyles/American.hpp"
#include "include/GameStyles/European.hpp"
#include "include/UI.hpp"
#include <memory>

int main() {

  UI::getInstance().print("Welcome to the game!", "Dealer");

  std::unique_ptr<IGameStyle> game_style = std::make_unique<European>();
  Game game(std::move(game_style));
}
