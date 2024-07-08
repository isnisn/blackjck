#include "../Player.hpp"
class IDealer {
public:
  virtual ~IDealer() = default;
  virtual void deal_cards(const std::shared_ptr<Player> &players) = 0;
};
