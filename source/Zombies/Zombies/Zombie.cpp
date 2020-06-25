#include "olcPixelGameEngine.h"

#include "Zombie.h"
#include "Player.h"


Zombie::Zombie() {


}

Zombie::Zombie(int _x, int _y, int _speed) {

	position.SetX(_x);
	position.SetY(_y);

	speed = _speed;
	size = 10;

}

void Zombie::Tick(float timeElapsed, Player* p) {

	Move(Track(p));

}

Vector Zombie::Track(Player* p) {



	return Vector();
}

void Zombie::Move(Vector v) {

}

void Zombie::Draw(olc::PixelGameEngine* pge) {

	pge->FillCircle(position.GetX(), position.GetY(), size / 2, olc::Pixel(0, 255, 0, 255));
}