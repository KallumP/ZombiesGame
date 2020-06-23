#include "olcPixelGameEngine.h"

#include "Player.h"


Player::Player() {

	size = 10;
	moveSpeed = 5;
	maxSpeed = 10;
}


Player::Player(int _x, int _y) {

	SetX(_x);
	SetY(_y);

	moveSpeed = 1;
	maxSpeed = 3;
	size = 10;
}

void Player::Move(Vector* toMove) {

	//sets the accelaration of the player
	accelaration = *toMove;

	accelaration.Multiply(moveSpeed);

	Decelarate();

	velocity.Add(&accelaration);

	velocity.Constrain(-maxSpeed, maxSpeed);

	position.Add(&velocity);
}

/// <summary>
/// Checks if and decelarates the player
/// </summary>
void Player::Decelarate() {

	float slowdown = 0.9;

	//checks if the x axis had any accelaration and had velocity
	if (accelaration.GetX() == 0 && velocity.GetX() != 0) 
		accelaration.SetX(velocity.GetX() * -slowdown);

	//checks if the y axis had any accelaration and had velocity
	if (accelaration.GetY() == 0 && velocity.GetY() != 0)
		accelaration.SetY(velocity.GetY() * -slowdown);
}

/// <summary>
/// Draws the player
/// </summary>
/// <param name="pge">Pointer to the pixel game engine</param>
void Player::Draw(olc::PixelGameEngine* pge) {

	pge->FillCircle(position.GetX(), position.GetY(), size / 2, olc::Pixel(255, 0, 0, 255));

}



//properties

void Player::SetX(int _x) {
	position.SetX(_x);
}


void Player::SetY(int _y) {
	position.SetY(_y);
}

int Player::GetMoveSpeed() {
	return moveSpeed;
}