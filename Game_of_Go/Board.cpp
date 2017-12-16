#include "stdafx.h"
#include "Board.h"


Board::Board() {
  size = 0;
}

Board::Board(const short &_size) {
  size = _size;
  
  table = vector< vector<Cell*> >();
  for (int i = 0; i < size; i++) {
    table.push_back(vector<Cell*>());
    for (int j = 0; j < size; j++)
      table[i].push_back(new Cell);
  }

}

Board::~Board() { }

bool PlayAt(const int &_x, const int &_y, const Player const * _player) {
  if (_x >= _size)
}
