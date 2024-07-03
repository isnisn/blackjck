#include "include/Deck/Deck.hpp"
#include "include/Deck/DeckService.hpp"
#include "include/Game/Game.hpp"
#include "include/GameStyles/European.hpp"
#include "include/Hand.hpp"
#include "include/Player.hpp"
#include <memory>
#include <vector>

int main() {

  Game game(std::make_unique<European>());
  DeckService deck_service;

  game.start_game();

  return 0;
}
