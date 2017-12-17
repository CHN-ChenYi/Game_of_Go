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

bool Board::CheckAlive(vector< vector<bool> > &_vis, const int &_x, const int _y) {
  bool ret = false;
  _vis[_x][_y] = true;
  Player * const owner = table[_x][_y]->GetOwner();
  for (int i = 0; i < 4; i++) {
    const int nxt_x = _x + dx[i];
    const int nxt_y = _y + dy[i];
    if (nxt_x < 0 || nxt_x >= size || nxt_y < 0 || nxt_y >= size || _vis[nxt_x][nxt_y])
      continue;
    Player * const nxt_owner = table[nxt_x][nxt_y]->GetOwner();
    if (nxt_owner == NULL)
      ret |= true;
    else if (*owner == *nxt_owner)
      ret |= CheckAlive(_vis, nxt_x, nxt_y);
  }
  return ret;
}

void Board::PutToDeath(const int &_dead_time, const int &_x, const int &_y) {
  table[_x][_y]->PutToDeath(_dead_time);
  Player * const owner = table[_x][_y]->GetOwner();
  for (int i = 0; i < 4; i++) {
    const int nxt_x = _x + dx[i];
    const int nxt_y = _y + dy[i];
    if (nxt_x < 0 || nxt_x >= size || nxt_y < 0 || nxt_y >= size || table[nxt_x][nxt_y]->IsDead())
      continue;
    Player * const nxt_owner = table[nxt_x][nxt_y]->GetOwner();
    if (nxt_owner != NULL && *owner == *nxt_owner)
      PutToDeath(_dead_time, nxt_x, nxt_y);
  }
}

void Board::Calculate(const int &_now_time, const int &_x, const int _y) {
  vector< vector<bool> > vis;
  for (int i = 0; i < size; i++) {
    vis.push_back(vector<bool>());
    for (int j = 0; j < size; j++)
      vis[i].push_back(false);
  }
  if (!CheckAlive(vis, _x, _y))
    PutToDeath(_now_time + 2, _x, _y);
  for (int i = 0; i < 4; i++) {
    const int nxt_x = _x + dx[i];
    const int nxt_y = _y + dy[i];
    if (nxt_x < 0 || nxt_x >= size || nxt_y < 0 || nxt_y >= size || vis[nxt_x][nxt_y])
      continue;
    if (table[nxt_x][nxt_y]->GetOwner() != NULL && !CheckAlive(vis, nxt_x, nxt_y))
      PutToDeath(_now_time + 2, nxt_x, nxt_y);
  }
}

void Board::Flash(const int &_now_time) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (table[i][j]->NeedToBeRemoved(_now_time)) {
        delete table[i][j];
        table[i][j] = new Cell;
      }
    }
  }
}

bool Board::PlayAt(const int &_now_time, const int &_x, const int &_y, Player *_player) {
  if (_x >= size || _y >= size || table[_x][_y]->GetOwner() != NULL)
    return false;
  table[_x][_y]->SetOwner(_player);
  Calculate(_now_time, _x, _y);
  Flash(_now_time);
  return true;
}
