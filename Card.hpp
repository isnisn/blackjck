#ifndef CARD_HPP
#define CARD_HPP
/**
 * @brief Card class
 *
 * @tparam T
 * @tparam U
 */
template <typename T, typename U> class Card {

public:
  T get_value() const { return value; }
  U get_suit() const { return suit; }

  Card(T value, U suit) : value(value), suit(suit) {
    value = 0;
    suit = ' ';
  }

  ~Card() {
    // std::cout << "Destruction of card\n";
  }

private:
  T value;
  U suit;
};
#endif
