#include "stdafx.h"
#include "Player.h"


Player::Player() {
  name = "";
}

Player::Player(const std::string _name) {
  name = _name;
}

Player::~Player() { }
