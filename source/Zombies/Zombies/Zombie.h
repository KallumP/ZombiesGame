#pragma once
#include "olcPixelGameEngine.h"

#include "Vector.h"
#include "Player.h"

class Zombie {

public:

	Zombie();
	Zombie(int, int, int);


	void Tick(float, Player*);

	void Draw(olc::PixelGameEngine*);

private:

	Vector Track(Player*);
	void Move(Vector);

	Vector position;
	int speed;
	int size;
};

