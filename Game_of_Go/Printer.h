#pragma once

#ifndef PRINTER_H
#define PRINTER_H

#include "Board.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Printer {
  char empty_icon;
  int num_of_player;
  vector<Player*> players;
  vector<char> player_icon;

  char GetIcon(Cell *_cell) {
    Player* owner = _cell->GetOwner();
    if (owner == NULL)
      return empty_icon;
    for (int i = 0; i < num_of_player; i++) {
      if (*owner == *players[i])
        return player_icon[i];
    }
    return '!';
  }

 public:
  Printer();
  Printer(const char _empty_icon, const int _num_of_player,
          const vector<Player*> _players, const vector<char> _player_icon);
  ~Printer();

  void Print(Board *_board);

};


#endif  // !PRINTER_H
