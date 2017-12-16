#include "stdafx.h"
#include "Game.h"


Game::Game() { }

Game::Game(const int &_num_of_player, const short &_width_of_board) {
  board = new Board(_width_of_board);
  num_of_player = _num_of_player;
  vector<Player*> _players;
  vector<char> _player_icon;
  for (int i = 0; i < num_of_player; i++) {
    _players.push_back(new Player);
    _player_icon.push_back('k' + i);
  }
  printer = new Printer('.', num_of_player, _players, _player_icon);
  for (int i = 0; i < num_of_player; i++)
    players.push_back(new Player);
}

Game::~Game() { }

bool Game::ReadCommand(int &x, int &y) {
  string ope;
  cout << "Type you command:" << endl;
  cin >> ope;
  const int len = ope.length();
  switch (ope[0]) {
    case 'p' || 'P':
      if (len > 2 && isupper(ope[2])) {
        x = ope[2] - 'A';
      } else if (len > 2 && islower(ope[2])) {
        x = ope[2] - 'a';
      } else {
        cout << "Undefined command" << endl;
        return ReadCommand(x, y);
      }
      if (len > 3 && !isdigit(ope[3])) {
        cout << "Undefined command" << endl;
        return ReadCommand(x, y);
      }
      y = ope[3] & 0xf;
      if (len > 4 && isdigit(ope[4]))
        y = y * 10 + (ope[4] & 0xf);
      y--;
      break;
    default:
      return 0;
  }
  return 1;
}

Player* Game::Play() {
  int x, y;
  int now_player = -1;
  while (true) {
    cls();
    printer->Print(board);

    now_player++;
    if (now_player == num_of_player)
      now_player = 0;

    AskForMove:
    if (!ReadCommand(x, y))
      break;
    if (!board->PlayAt(y, x, players[now_player])) {
      cout << "Your movement is illegal." << endl;
      goto AskForMove;
    }
  }
  return players[now_player];
}