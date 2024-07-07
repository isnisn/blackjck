#ifndef UI_HPP
#define UI_HPP

#include "Colors.hpp"
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

  /**
   * @brief Print a message
   *
   * @param message
   * @param from
   * @param COLOR
   */
  void print(const std::string &message, const std::string &from,
             std::string COLOR = WHITE) const {
    std::cout << BOLD << "[" << from << "] >" << RESET << COLOR << message
              << RESET << std::endl;
  }
  /**
   * @brief Get input from the user
   *
   * @param prompt The prompt message
   * @return std::string The user input
   */
  std::string get_input(const std::string &prompt) const {
    std::cout << prompt;
    std::string input;
    std::getline(std::cin, input);
    return input;
  }

private:
  UI() = default;
  ~UI() = default;
};
#endif
