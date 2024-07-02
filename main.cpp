
#include "Deck.hpp"
#include "Hand.hpp"
#include "Player.hpp"
#include <memory>
#include <vector>

int main() {
  std::vector<Player> players;
  Deck<int, char> deck(1);

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
