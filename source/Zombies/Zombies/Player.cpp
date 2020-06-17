#include "Player.h"


Player::Player() {
}

Player::Player(int _x, int _y) {

	SetX(_x);
	SetY(_y);
}

void Player::SetX(int _x) {
	x = _x;
}


void Player::SetY(int _y) {
	y = _y;
}