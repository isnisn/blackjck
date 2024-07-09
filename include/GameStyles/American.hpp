
// #include "../Deck/Deck.hpp"
// #include "../Game/IGameStyle.hpp"
// #include <cstdint>
// #include <memory>

// /**
//  * American style
//  */
// class American : public IGameStyle {
// private:
//   unsigned int num_decks = 6;
//   // std::shared_ptr<Deck<int, char>> deck;
//   // .. other rules

// public:
//   American() { this->setup(); }
//   void play(const std::vector<std::shared_ptr<IPlayer>> &players) override {
//     return;
//   }

//   unsigned int get_num_deck() override { return num_decks; }

// private:
//   void setup() override {
//     // Init deck and so on
//     deck = std::make_shared<Deck<int, char>>(num_decks);
//   }
// };
