#include "SpawnPoint.h"

SpawnPoint::SpawnPoint() {

}

SpawnPoint::SpawnPoint(int _x, int _y, int _spawnRadius) {
	SetX(_x);
	SetY(_y);
	SetSpawnRadius(_spawnRadius);

}

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