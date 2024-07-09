#ifndef PLAYER_SERVICE_HPP
#define PLAYER_SERVICE_HPP
#include "Player.hpp"

class PlayerService {
public:
  void create_players(int num_players,
                      std::vector<std::shared_ptr<IPlayer>> &players) {
    for (int i = 0; i < num_players; ++i) {
      std::shared_ptr<IPlayer> player = create_player();
      players.emplace_back(player);
    }
  }

  std::shared_ptr<IPlayer> create_player() {
    std::string name = UI::getInstance().get_input("Enter player name: ");
    return std::make_shared<Player>(name);
  }
};
#endif
