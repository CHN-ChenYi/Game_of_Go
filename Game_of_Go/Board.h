#pragma once

#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"

#include <vector>
using std::vector;

class Board {
  short size;
  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};
  vector< vector<Cell*> > table;

  void Flash(const int &_now_time);

  void Calculate(const int &_now_time, const int &_x, const int _y);

  void PutToDeath(const int &_dead_time, const int &_x, const int &_y);

  bool CheckAlive(vector< vector<bool> > &_vis, const int &_x, const int _y);

 public:
  Board();
  Board(const short &_size);
  ~Board();

  int GetSize() {
    return size;
  }

  Cell* GetCell(const int &_x, const int &_y) {
    return table[_x][_y];
  }

  bool PlayAt(const int &_now_time, const int &_x, const int &_y, Player *_player);

};


#endif  // !BOARD_H
