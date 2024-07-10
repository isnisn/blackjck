#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Hand.hpp"
#include "IPlayer.hpp"
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

class Player : public IPlayer {
public:
  /**
   * @brief Construct a new Player object
   *
   * @param name
   */
  Player(const std::string &name) : name(name) {
    std::cout << "Created player " << name << std::endl;

    // Create an empty hand
    hand = std::make_shared<Hand<2>>();
  }

  ~Player() { std::cout << "Destroyed player " << name << std::endl; }

  // Move constructor
  explicit Player(Player &&other) noexcept
      : name(std::move(other.name)), hand(std::move(other.hand)) {
    std::cout << "Moved player " << name << std::endl;
  }

  // Move assignment operator
  Player &operator=(Player &&other) noexcept {
    if (this != &other) {
      name = std::move(other.name);
      hand = std::move(other.hand);
      std::cout << "Moved assignment player " << name << std::endl;
    }
    return *this;
  }

  // Deleted copy constructor and copy assignment operator
  // to prevent copying of player objects
  Player(const Player &) = delete;
  Player &operator=(const Player &) = delete;

  void print_player() override {
    std::cout << "Player name: " << name << std::endl;
  }

  int get_hand_value() override {
    int val = 0;

    if (hand == nullptr) {
      std::cerr << "Hand is empty" << std::endl;
      return 0;
    }

    for (const auto &card : hand->get_cards()) {
      std::cout << "Card: " << card->get_value() << std::endl;
      val += card->get_value() > 10 ? 10 : card->get_value();
    }

    return val;
  }

  void add_card(std::unique_ptr<Card<int, char>> &&card) override {
    std::cout << "Adding card to player " << name << std::endl;
    hand->add_card(std::move(card));
  }

private:
  std::string name;
  std::shared_ptr<Hand<2>> hand;
};
#endif
