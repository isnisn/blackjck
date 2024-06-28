#ifndef DECK_HPP
#define DECK_HPP
#include "IDeck.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

/**
 * @brief Deck class
 *
 * @tparam T
 * @tparam U
 */
template <typename T, typename U> class Deck : public IDeck<T, U> {
public:
  Deck() { create_cards(); }

  std::vector<std::unique_ptr<Card<T, U>>>
  generate_hand(const int &n) override {
    std::vector<std::unique_ptr<Card<T, U>>> hand;
    for (int i = 0; i < n && !cards.empty(); ++i) {
      hand.push_back(std::move(cards.back()));
      cards.pop_back();
    }
    return hand;
  }
  void print_deck() override {
    for (const auto &c : cards) {
      std::cout << c->get_suit() << " " << c->get_value() << std::endl;
    }
  }

  void shuffle() override {
    // Obtain a time-based seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
  }

  ~Deck() override { std::cout << "Destroyed deck" << std::endl; }

private:
  std::vector<std::unique_ptr<Card<int, char>>> cards;
  char suits[4] = {'S', 'H', 'D', 'C'};

  void create_cards() override {
    for (int i = 0; i < 4; ++i) {
      for (int j = 2; j <= 14; ++j) {
        cards.push_back(std::make_unique<Card<T, U>>(j, suits[i]));
      }
    }
  }
};
#endif
