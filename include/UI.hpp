#include <iostream>
#include <ostream>
#include <string>

class UI {
public:
  UI(const UI &) = delete;
  UI &operator=(const UI &) = delete;

  static UI &getInstance() {
    static UI *instance;
    return *instance;
  }

  void print(const std::string &message, const std::string &from) const {
    std::cout << "[" << from << "] >" << message << std::endl;
  }

private:
  UI() = default;
  ~UI() = default;
};
