#include "stdafx.h"
#include "Player.h"


Player::Player() {
  id = rand();
}

Player::Player(const int &_id) {
  id = _id;
}

Player::~Player() { }
