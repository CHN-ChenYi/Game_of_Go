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

  Cell* GetCell(const int &x, const int &y) {
    return table[x][y];
  }

};


#endif  // !BOARD_H
