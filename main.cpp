
#include "Deck.hpp"
#include "IDeck.hpp"

int main() {

  std::unique_ptr<IDeck<int, char>> deck = std::make_unique<Deck<int, char>>();
  deck->print_deck();

  return 0;
}
