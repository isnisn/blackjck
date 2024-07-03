#include "include/Deck.hpp"
#include "include/Game/Game.hpp"
#include "include/GameStyles/European.hpp"
#include "include/Hand.hpp"
#include "include/Player.hpp"
#include <memory>
#include <vector>

#define NUM_DECKS 4

int main() {

  Game game(std::make_unique<European>());
  game.start_game();

  std::vector<Player> players;

  /**
   * Creating the deck here, should later on be in a strategy class
   */
  Deck<int, char> deck(NUM_DECKS);

  deck.shuffle();

  // Create some players
  Player player1("Player 1");
  players.emplace_back(std::move(player1));

  // Process players
  for (auto &p : players) {
    p.print_player();
    p.set_hand(std::make_shared<Hand<5>>(deck));
    p.get_hand();
    std::cout << std::endl;
  }

  deck.print_deck();

  return 0;
}
