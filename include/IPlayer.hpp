#include "Player.hpp"

class IPlayer {
public:
  virtual std::vector<std::shared_ptr<Player>>
  create_players(int num_players) = 0;
  virtual std::shared_ptr<Player> create_player() = 0;
  virtual ~IPlayer() = default;
};
