#pragma once
#include "olcPixelGameEngine.h"

#include "Vector.h"

class Player {

public:


	Player();
	Player(int, int);

	void Move(Vector*);
	void Draw(olc::PixelGameEngine*);

	void SetX(int);
	void SetY(int);

	int GetMoveSpeed();

private:

	void Decelarate();


	Vector position;
	Vector velocity;
	Vector accelaration;

	int size;
	int moveSpeed;
	int maxSpeed;
};

