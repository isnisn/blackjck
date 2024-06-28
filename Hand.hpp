#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"
#include "Deck.hpp"
#include <iostream>
#include <memory>
#include <vector>

/**
 * @brief Hand class
 *
 * @tparam N size of the hand
 */
template <size_t N> class Hand {
public:
  Hand(std::unique_ptr<Deck<int, char>> &deck) {
    hand = deck->generate_hand(N);
  }
  ~Hand() { std::cout << "Destroyed hand" << std::endl; }

  size_t get_hand_size() const { return hand.size(); }
  Hand get_hand() const { return *this; }

  /**
   * @brief Get card from hand
   *
   * @param index
   * @return Card<int, char>
   */
  Card<int, char> get_card(const size_t &index) const { return *hand[index]; }

  /**
   * @brief Print hand
   *
   */
  void print_hand() const {
    for (const auto &c : hand) {
      std::cout << c->get_suit() << " " << c->get_value() << std::endl;
    }
  }

private:
  const size_t max_hand_size = N;
  std::vector<std::unique_ptr<Card<int, char>>> hand;
};
#endif
