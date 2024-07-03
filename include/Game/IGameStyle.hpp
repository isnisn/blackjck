#pragma once
/**
 * Our interface to choose what game style of blackjack we want.
 */
class IGameStyle {
public:
  virtual ~IGameStyle() = default;
  virtual void play() = 0;

private:
  virtual void setup() = 0;
};
