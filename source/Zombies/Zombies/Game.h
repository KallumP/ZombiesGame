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

	void Inputs(olc::PixelGameEngine*);
	void MovePlayer(float);

	std::vector<SpawnPoint> zombieSpawnPoints;
	std::vector<Zombie> zombies;

	SpawnPoint playerSpawnPoint;
	Player* player;


	//inputs
	bool WPressed;
	bool APressed;
	bool SPressed;
	bool DPressed;
};

