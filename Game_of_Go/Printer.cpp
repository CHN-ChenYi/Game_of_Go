#include "stdafx.h"
#include "Printer.h"


Printer::Printer() { }

Printer::Printer(const char _empty_icon, const int _num_of_player,
                 const vector<Player*> _players, const vector<char> _player_icon) {
  players = _players;
  empty_icon = _empty_icon;
  player_icon = _player_icon;
  num_of_player = _num_of_player;
}

Printer::~Printer() { }

void Printer::Print(Board *_board) {
  const int n = _board->GetSize();

  // printing header
  for (int i = 0; i < n / 10 + 2; i++)
    cout << " "; // print offset created by row numbering
  for (int i = 0; i < n; i++) cout << char('A' + i) << " ";
  cout.put(cout.widen('\n'));
  cout.flush();
  for (int i = 0; i < n / 10 + 1; i++)
    cout << " ";
  cout << "+";
  for (int i = 0; i < n; i++)
    cout << "--";
  cout << "+";
  cout.put(cout.widen('\n'));
  cout.flush();

  // printing each row
  for (int i = 0; i < n; i++) {

    // printing row numbering at left side
    for (int j = 0; j < n / 10 - (i + 1) / 10; j++)
      cout << " "; // print trailing spaces for formatting
    cout << i + 1 << "|";

    for (int j = 0; j < n; j++) {
      Cell *c = _board->GetCell(i, j);
      cout << GetIcon(c) << " ";
    }
    // printing row numbering at the right side
    cout << "|" << i + 1;
    cout.put(cout.widen('\n'));
    cout.flush();
  }

  // printing footer
  for (int i = 0; i < n / 10 + 1; i++)
    cout << " ";
  cout << "+";
  for (int i = 0; i < n; i++)
    cout << "--";
  cout << "+";
  cout.put(cout.widen('\n'));
  cout.flush();
  for (int i = 0; i < n / 10 + 2; i++)
    cout << " ";
  for (int i = 0; i < n; i++)
    cout << char('A' + i) << " ";
  cout.put(cout.widen('\n'));
  cout.flush();

}