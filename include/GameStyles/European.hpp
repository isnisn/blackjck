
#include "../Dealer/DealerService.hpp"
#include "../Game/IGameStyle.hpp"
#include <memory>

/**
 * European style
 */
class European : public IGameStyle {

private:
  unsigned int num_decks = 2;
  // std::unique_ptr<Deck<int, char>> deck;

  std::string m_Rules =
      "The European style of blackjack is played with 2 decks of cards. "
      "The dealer stands on a soft 17. The player can double down on any "
      "hand, and can split up to 3 times. The player can also take "
      "insurance if the dealer's face up card is an ace. The player can "
      "surrender at any time. The player wins if they have a higher hand "
      "than the dealer without going over 21.";

  void setup() override {
    // Init deck and so on
    // deck = std::make_unique<Deck<int, char>>(num_decks);
  }

public:
  European() { this->setup(); }
  unsigned int get_num_deck() override { return num_decks; }
  void play(const std::vector<std::shared_ptr<IPlayer>> &players,
            std::shared_ptr<IDeck<int, char>> &deck) override {

    UI::getInstance().print(m_Rules, "Game", YELLOW);
    UI::getInstance().print("Starting a European style game of blackjack!",
                            "Dealer");

    deck->shuffle();

    for (auto &player : players) {
      std::cout << "Player: " << player->get_hand_value() << std::endl;
    }
    // deck->print_deck();
    return;
  }
};
