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

bool Board::PlayAt(const int &_x, const int &_y, Player *_player) {
  if (_x >= size || _y >= size || table[_x][_y]->GetOwner() != NULL)
    return false;
  table[_x][_y]->SetOwner(_player);
  return true;
}
