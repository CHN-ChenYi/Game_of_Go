#pragma once

#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"

#include <vector>
using std::vector;

class Board {
  int size;
  vector< vector<Cell*> > table;

 public:
  Board();
  Board(const int &_size);
  ~Board();

};


#endif  // !BOARD_H
