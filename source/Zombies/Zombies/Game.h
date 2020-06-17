#pragma once

#include <vector>
#include <iostream>

#include "SpawnPoint.h"
#include "Zombie.h"
#include "Player.h"

class Game {

public: 

	Game();

	void Inputs();
	void Tick();
	void Draw();

	


private:

	void SetupLevel(std::string);
	void SetupDebugLevel();

	void SpawnPlayer();

	std::vector<SpawnPoint> zombieSpawns;
	std::vector<Zombie> zombies;

	SpawnPoint playerSpawn;
	Player* player;

};

