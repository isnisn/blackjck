#ifndef IDECK_HPP
#define IDECK_HPP
#include "Card.hpp"
#include <memory>
#include <vector>

/**
 * @brief IDeck class
 *
 * @tparam T
 * @tparam U
 */

template <typename T, typename U> class IDeck {
public:
  virtual ~IDeck() = default;
  virtual std::vector<std::unique_ptr<Card<T, U>>>
  generate_hand(const int &n) = 0;
  virtual void print_deck() = 0;
  virtual void shuffle() = 0;

private:
  virtual void create_cards() = 0;
  const size_t deck_size = 52;
};
#endif
