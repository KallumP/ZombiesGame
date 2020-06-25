#pragma once
#include "olcPixelGameEngine.h"

#include "Vector.h"

class Player {

public:


	Player();
	Player(int, int);

	void Move(Vector*, float);
	void Draw(olc::PixelGameEngine*);

	Vector GetPosition();
	void SetX(int);
	void SetY(int);

	int GetMoveSpeed();

private:

	void Decelarate();


	Vector position;
	Vector velocity;
	Vector accelaration;

	int size;

	//per second
	int moveSpeed;
	int maxSpeed;
};

