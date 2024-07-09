#pragma once
#include "../IPlayer.hpp"

/**
 * Our interface to choose what game style of blackjack we want.
 */
class IGameStyle {
public:
  virtual ~IGameStyle() = default;
  virtual void play(const std::vector<std::shared_ptr<IPlayer>> &players,
                    std::shared_ptr<IDeck<int, char>> &deck) = 0;
  virtual unsigned int get_num_deck() = 0;

private:
  virtual void setup() = 0;
};
