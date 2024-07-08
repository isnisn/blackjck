#include "../PlayerService.hpp"
#include "IGameStyle.hpp"
#include <memory>

class Game {
private:
  std::unique_ptr<IGameStyle> game_style;

  // We own the players
  PlayerService player_service;
  std::vector<std::shared_ptr<Player>> players;

public:
  /**
   * Transfer ownership of the ptr to the choosen game style.
   */
  explicit Game(std::unique_ptr<IGameStyle> &&game_style = {})
      : game_style(std::move(game_style)) {
    player_service.create_players(2, players);

    start_game();
  }

  /**
   * Start the game with the choose game style
   */
  void start_game() const {
    if (game_style) {
      game_style->play();
    }
  }
};
