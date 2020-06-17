#include <vector>
#include <iostream>
#include <stdlib.h>

#include "Game.h"



Game::Game() {

	SetupDebugLevel();
	SpawnPlayer();

}




void Game::SetupLevel(std::string levelFilePath) {

	//sets up a level using the passed in file

}

//sets up a debut level
void Game::SetupDebugLevel() {
	

	//adds in one spawn point
	zombieSpawns.push_back(SpawnPoint(200, 200, 10));

	playerSpawn = SpawnPoint(20, 20, 10);

}

void Game::SpawnPlayer() {

	//spawns in the player at the spawn point (randomly within the spawn radius)
	player = new Player(rand() % playerSpawn.GetSpawnRadius() + playerSpawn.GetX(), rand() % playerSpawn.GetSpawnRadius() + playerSpawn.GetY());

}


void Game::Inputs() {

}

void Game::Tick() {

}

void Game::Draw() {





}


