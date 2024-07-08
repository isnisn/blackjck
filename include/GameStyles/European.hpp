
#include "../Dealer/DealerService.hpp"
#include "../Deck/Deck.hpp"
#include "../Game/IGameStyle.hpp"
#include "../PlayerService.hpp"
#include <cstdint>
#include <memory>

/**
 * European style
 */
class European : public IGameStyle {
private:
  uint8_t num_decks = 2;
  std::unique_ptr<Deck<int, char>> deck;

  PlayerService player_service;
  DealerService dealer_service;

public:
  European() { this->setup(); }

  void play() override {

    UI::getInstance().print(m_Rules, "Game", YELLOW);
    UI::getInstance().print("Starting a European style game of blackjack!",
                            "Dealer");
    deck->shuffle();
    // deck->print_deck();
    return;
  }

private:
  std::string m_Rules =
      "The European style of blackjack is played with 2 decks of cards. "
      "The dealer stands on a soft 17. The player can double down on any "
      "hand, and can split up to 3 times. The player can also take "
      "insurance if the dealer's face up card is an ace. The player can "
      "surrender at any time. The player wins if they have a higher hand "
      "than the dealer without going over 21.";

  void setup() override {
    // Init deck and so on
    deck = std::make_unique<Deck<int, char>>(num_decks);
  }
};
