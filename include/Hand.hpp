#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"
#include "Deck/Deck.hpp"
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>
#include <vector>

/**
 * @brief Hand class
 *
 * @tparam N size of the hand
 */
template <size_t N> class Hand {
public:
  // Default constructor
  Hand() {}

  Hand(const std::unique_ptr<IDeck<int, char>> &deck) {
    hand = deck->generate_hand(N);
  }

  Hand(const std::shared_ptr<IDeck<int, char>> &deck) {
    std::cout << "Creating hand" << std::endl;
    hand = deck->generate_hand(N);
  }

  ~Hand() { std::cout << "Destroyed hand" << std::endl; }

  // Move constructor
  Hand(Hand &&other) noexcept : hand(std::move(other.hand)) {
    std::cout << "Moved hand" << std::endl;
  }

  /**
   * @brief Move assignment operator
   *
   * @param other
   * @return Hand&
   */
  Hand &operator=(Hand &&other) noexcept {
    std::cout << "Moved assignment hand" << std::endl;
    if (this != &other) {
      hand = std::exchange(other.hand, nullptr);
    }
  }

  const std::vector<std::unique_ptr<Card<int, char>>> &get_cards() const {
    return hand;
  }

  /**
   * @brief Get card from hand
   *
   * @param index
   * @return const Card<int, char>
   */
  const Card<int, char> &get_card(const size_t &index) const {
    return *hand[index];
  }

  void add_card(std::unique_ptr<Card<int, char>> &&card) {

    std::cout << "Adding card to hand" << " Card " << card->get_suit()
              << std::endl;

    hand.push_back(std::move(card));

    std::cout << "Hand size: " << hand.size() << std::endl;
  }

  /**
   * @brief Print hand
   *
   */
  void print_hand() {
    for (const auto &c : hand) {
      std::cout << c->get_suit() << " " << c->get_value() << std::endl;
    }
  }
  size_t get_hand_size() const { return hand.size(); }

private:
  const size_t max_hand_size = 12;
  std::vector<std::unique_ptr<Card<int, char>>> hand;
};

#endif // HAND_HPP
