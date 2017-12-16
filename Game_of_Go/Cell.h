#pragma once

#ifndef CELL_H
#define CELL_H

#include "Player.h"

class Cell {
  Player *owner;
  short dead_time;

 public:
  Cell();
  Cell(Player* const _owner);
  ~Cell();

  bool IsDead() {
    return dead_time != -1;
  }

  bool PutToDeath(const int &_dead_time) {
    if (dead_time != -1)
      return false;
    dead_time = _dead_time;
    return true;
  }

  bool NeedToBeRemoved(const int &_now_time) {
    return dead_time <= _now_time;
  }

  Player* GetOwner() {
    return owner;
  }

};


#endif  // !CELL_H
