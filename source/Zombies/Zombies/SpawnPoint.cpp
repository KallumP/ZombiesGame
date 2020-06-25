#include "SpawnPoint.h"

SpawnPoint::SpawnPoint() {

}

SpawnPoint::SpawnPoint(int _x, int _y, int _spawnRadius, int _spawnRate) {
	SetX(_x);
	SetY(_y);
	SetSpawnRadius(_spawnRadius);

	spawnRate = _spawnRate;
	timeTillNextSpawn = 0;

}

bool SpawnPoint::CheckToSpawn(float timeElapsed) {

	timeTillNextSpawn += timeElapsed;

	if (timeTillNextSpawn >= spawnRate) {

		timeTillNextSpawn = 0;

		return true;
	}

	return false;
}



//properties

void SpawnPoint::SetX(int _x) {
	x = _x;
}
int SpawnPoint::GetX() {
	return x;
}

void SpawnPoint::SetY(int _y) {
	y = _y;
}
int SpawnPoint::GetY() {

	return y;
}

void SpawnPoint::SetSpawnRadius(int _spawnRadius) {
	spawnRadius = _spawnRadius;
}
int SpawnPoint::GetSpawnRadius() {
	return spawnRadius;
}