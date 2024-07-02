
#pragma once
#include "Hand.hpp"
#include <iostream>
#include <memory>
#include <string>

class Player {
public:
  /**
   * @brief Construct a new Player object
   *
   * @param name
   */
  Player(const std::string &name) : name(name) {
    std::cout << "Created player " << name << std::endl;
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

  void print_player() const {
    std::cout << "Player name: " << name << std::endl;
  }

  void get_hand() const {
    if (!hand) {
      return;
    }
    hand->print_hand();
  }

  void set_hand(std::shared_ptr<Hand<5>> hand) { this->hand = std::move(hand); }

private:
  std::string name;
  std::shared_ptr<Hand<5>> hand;
};
