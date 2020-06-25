#pragma once
#include "olcPixelGameEngine.h"

#include <vector>
#include <iostream>

#include "SpawnPoint.h"
#include "Zombie.h"
#include "Player.h"

class Game {

public: 

	Game();

	
	void Tick(olc::PixelGameEngine*, float);
	
	void Draw(olc::PixelGameEngine*);

	


private:

	void SetupLevel(std::string);
	void SetupDebugLevel();

	void SpawnPlayer();
	void SpawnZombies(float);


	void Inputs(olc::PixelGameEngine*);
	void MovePlayer(float);
	void MoveZombies(float);

	std::vector<SpawnPoint> zombieSpawnPoints;
	std::vector<Zombie> zombies;

	SpawnPoint playerSpawnPoint;
	Player* player;

	int round;

	//inputs
	bool WPressed;
	bool APressed;
	bool SPressed;
	bool DPressed;
};

