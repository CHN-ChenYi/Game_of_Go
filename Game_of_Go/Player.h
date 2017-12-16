#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using std::string;

class Player {
  string name;

 public:
  Player();
  Player(const string _name);
  ~Player();

  string getName() const {
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
