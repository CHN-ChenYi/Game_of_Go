#pragma once

#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"

#include <vector>
using std::vector;

class Board {
  short size;
  vector< vector<Cell*> > table;

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

  bool PlayAt(const int &_x, const int &_y, Player *_player);

};


#endif  // !BOARD_H
