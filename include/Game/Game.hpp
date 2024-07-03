#include "IGameStyle.hpp"
#include <memory>

class Game {
private:
  std::unique_ptr<IGameStyle> game_style;

public:
  /**
   * Transfer ownership of the ptr to the choosen game style.
   */
  explicit Game(std::unique_ptr<IGameStyle> &&game_style = {})
      : game_style(std::move(game_style)) {}

  /**
   * Start the game with the choose game style
   */
  void start_game() const {
    if (game_style) {
      game_style->play();
    }
  }
};
