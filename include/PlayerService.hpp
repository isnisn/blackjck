#include "IPlayer.hpp"

class PlayerService : public IPlayer {
public:
  std::vector<std::shared_ptr<Player>>
  create_players(int num_players) override {
    std::vector<std::shared_ptr<Player>> players;

    for (int i = 0; i < num_players; ++i) {
      std::shared_ptr<Player> player = std::make_shared<Player>("Player");

      players.emplace_back(player);
    }

    return players;
  }

  std::shared_ptr<Player> create_player() override {
    // Prompt for name

    return std::make_shared<Player>();
  }
};
