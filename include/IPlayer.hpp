#ifndef IPLAYER_HPP
#define IPLAYER_HPP
#include "Hand.hpp"

class IPlayer {
public:
  virtual ~IPlayer() = default;
  virtual void print_player() = 0;
  virtual int get_hand_value() = 0;
  virtual void add_card(std::unique_ptr<Card<int, char>> &&card) = 0;
};
#endif
