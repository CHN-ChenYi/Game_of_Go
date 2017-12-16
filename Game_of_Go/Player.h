#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
  std::string name;

 public:
  Player();
  Player(const std::string _name);
  ~Player();

  std::string getName() const {
    return this->name;
  }

  bool operator==(const Player &rhs) {
    return this == &rhs;
  }
  bool operator!=(const Player &rhs) {
    return !(*this == rhs);
  }

};

#endif  // PLAYER_H
