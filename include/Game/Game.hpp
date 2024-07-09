#include "../Deck/DeckService.hpp"
#include "../PlayerService.hpp"
#include "IGameStyle.hpp"
#include <memory>
#include <ostream>

class Game {
private:
  std::unique_ptr<IGameStyle> game_style;

  PlayerService player_service;
  DeckService deck_service;

  std::vector<std::shared_ptr<IPlayer>> players;
  std::shared_ptr<Deck<int, char>> deck;

public:
  /**
   * Transfer ownership of the ptr to the choosen game style.
   */
  explicit Game(std::unique_ptr<IGameStyle> &&game_style = {})
      : game_style(std::move(game_style)) {

    start_game();
  }

  /**
   * Start the game with the choose game style
   */
  void start_game() {
    if (game_style) {

      // Create players
      player_service.create_players(2, players);

      // Create the deck
      deck = std::make_shared<Deck<int, char>>(game_style->get_num_deck());

      // Start the game with our deck, dealer and players.
      game_style->play(players);
    }
  }
};
