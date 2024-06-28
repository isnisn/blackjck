
#include "Deck.hpp"
#include "Hand.hpp"

int main() {

  std::unique_ptr<Deck<int, char>> deck = std::make_unique<Deck<int, char>>();
  deck->print_deck();
  deck->shuffle();
  deck->print_deck();
  Hand<5> hand(deck);
  std::cout << "Printing hand" << std::endl;
  std::cout << "Hand size: " << hand.get_hand_size() << std::endl;
  hand.print_hand();

  return 0;
}
