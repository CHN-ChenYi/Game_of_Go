#pragma once

#ifndef GAME_H
#define GAME_H

#include "Printer.h"

class Game {
  Board *board;
  Printer* printer;
  int num_of_player;
  vector<Player*> players;
  bool ReadCommand(int &x, int &y);
  void cls() {
    if (system("CLS"))
      system("clear");
  }

 public:
  Game();
  Game(const int &_num_of_player, const short &_width_of_board);
  ~Game();
  Player* Play();
};

#endif  // !GAME_H
