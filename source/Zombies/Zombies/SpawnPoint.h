#pragma once
class SpawnPoint {


public:

	SpawnPoint();
	SpawnPoint(int, int, int);

	void SetX(int);
	int GetX();

	void SetY(int);
	int GetY();

	void SetSpawnRadius(int);
	int GetSpawnRadius();


private:

	int x;
	int y;
	int spawnRadius;
};

