
#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp" // Assuming there's a Card header file
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

  // Destructor
  ~Deck() override { std::cout << "Destroyed deck" << std::endl; }

  // Delete copy constructor and copy assignment operator
  Deck(const Deck &other) = delete;
  Deck &operator=(const Deck &other) = delete;

  // Move constructor
  Deck(Deck &&other) noexcept : cards(std::move(other.cards)) {
    other.cards.clear(); // Ensure source is left in a valid state
    std::cout << "Deck moved" << std::endl;
  }

  // Move assignment operator
  Deck &operator=(Deck &&other) noexcept {
    if (this != &other) {
      // Free existing resources
      cards.clear();

      // Move resources from source to destination
      cards = std::move(other.cards);
      other.cards.clear();

      std::cout << "Deck moved via assignment" << std::endl;
    }
    return *this;
  }

  std::vector<std::unique_ptr<Card<T, U>>>
  generate_hand(const int &&n) override {
    std::vector<std::unique_ptr<Card<T, U>>> hand;
    for (int i = 0; i < n && !cards.empty(); ++i) {
      // Move card from deck to hand
      hand.emplace_back(std::move(cards.back()));
      // Remove card from deck
      cards.pop_back();
    }
    return hand;
  }

  void print_deck() override {
    if (cards.empty()) {
      std::cout << "Deck is empty" << std::endl;
      return;
    }

    std::cout << "Deck size: " << cards.size() << std::endl;
    for (const auto &c : cards) {
      std::cout << c->get_suit() << " " << c->get_value() << std::endl;
    }
  }

  void shuffle() override {
    // Obtain a time-based seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
  }

  std::unique_ptr<Card<T, U>> draw_card() override {
    std::unique_ptr<Card<T, U>> card = std::move(cards.back());
    cards.pop_back();
    return card;
  }

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

#endif // DECK_HPP
