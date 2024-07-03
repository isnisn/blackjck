
#pragma once
#include "Deck.hpp"
#include <cstdint>
#include <memory>

class DeckFactory {
public:
  // Factory method to create a deck
  template <typename T, typename U>
  static std::shared_ptr<IDeck<T, U>> create_deck(uint8_t no_decks) {
    return std::make_shared<Deck<T, U>>(no_decks);
  }
};
