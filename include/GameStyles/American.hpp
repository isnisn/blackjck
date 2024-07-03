
#include "../Deck.hpp"
#include "../Game/IGameStyle.hpp"
#include <cstdint>
#include <memory>

/**
 * American style
 */
class American : public IGameStyle {
private:
  uint8_t num_decks = 6;
  std::shared_ptr<Deck<int, char>> deck;
  // .. other rules

public:
  American() { this->setup(); }
  void play() override { return; }

private:
  void setup() override {
    // Init deck and so on
    deck = std::make_shared<Deck<int, char>>(num_decks);
  }
};
