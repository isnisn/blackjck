#ifndef DEALER_SERVICE_HPP
#define DEALER_SERVICE_HPP
#include "IDealer.hpp"

class DealerService {
public:
  ~DealerService() = default;
  DealerService() = default;
  void deal_cards(const std::shared_ptr<Player> &players) { return; }
};
#endif
