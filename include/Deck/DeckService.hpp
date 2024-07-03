
#pragma once
#include "DeckFactory.hpp"
#include <cstdint>
#include <memory>

class DeckService {
public:
  template <typename T, typename U>
  std::shared_ptr<IDeck<T, U>> get_deck(uint8_t no_decks) {
    return DeckFactory::create_deck<T, U>(no_decks);
  }
};
