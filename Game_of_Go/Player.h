#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <cstdlib>
using std::string;

class Player {
  int id;

 public:
  Player();
  Player(const int &_id);
  ~Player();

  int GetId() const {
    return id;
  }

  bool operator==(const Player &rhs) {
    return id == rhs.id;
  }
  bool operator!=(const Player &rhs) {
    return !(id == rhs.id);
  }
  /*
  bool operator==(const Player &rhs) {
    return this == &rhs;
  }
  bool operator!=(const Player &rhs) {
    return !(*this == rhs);
  }
  */

};

#endif  // PLAYER_H
