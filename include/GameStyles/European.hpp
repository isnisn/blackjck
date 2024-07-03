
#include "../Deck.hpp"
#include "../Game/IGameStyle.hpp"
#include <cstdint>
#include <memory>

/**
 * European style
 */
class European : public IGameStyle {
private:
  uint8_t num_decks = 2;
  std::shared_ptr<Deck<int, char>> deck;
  // .. other rules

public:
  European() { this->setup(); }
  void play() override {
    std::cout << "Starting a European style game of blackjack!" << std::endl;
    return;
  }

private:
  void setup() override {
    // Init deck and so on
    deck = std::make_shared<Deck<int, char>>(num_decks);
  }
};
