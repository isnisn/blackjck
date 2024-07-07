#include "Player.hpp"

class IPlayer {
public:
  virtual ~IPlayer() = default;
  virtual void
  create_players(int num_players,
                 std::vector<std::shared_ptr<Player>> &players) = 0;
  virtual std::shared_ptr<Player> create_player() = 0;
};
