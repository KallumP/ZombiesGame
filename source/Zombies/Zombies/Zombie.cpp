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

/// <summary>
/// Tracks what movement the zombie must take to get to the player
/// </summary>
/// <param name="p"></param>
/// <returns></returns>
Vector Zombie::Track(Player* p) {

	Vector toMove;

	//calculates the distance between the zombie and the player
	float xDistance = p->GetPosition().GetX() - position.GetX();
	float yDistance = p->GetPosition().GetY() - position.GetY();
	float distance = sqrt(pow(xDistance, 2) + pow(yDistance, 2));

	//finds the ratio between the zombie speed and the distance
	float ratio =   speed / distance;

	//sets how the zombie must move
	toMove.SetX(xDistance * ratio);
	toMove.SetY(yDistance * ratio);

	return toMove;
}

void Zombie::Move(Vector v) {

	//moves the zombie
	position.Add(&v);

}

void Zombie::Draw(olc::PixelGameEngine* pge) {

	pge->FillCircle(position.GetX(), position.GetY(), size / 2, olc::Pixel(0, 255, 0, 255));

}


