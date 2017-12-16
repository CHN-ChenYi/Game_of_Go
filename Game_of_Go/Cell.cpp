#include "stdafx.h"
#include "Cell.h"


Cell::Cell() {
  owner = NULL;
  dead_time = -1;
}

Cell::Cell(Player* const _owner) {
  owner = _owner;
  dead_time = -1;
}

Cell::~Cell() {
}
