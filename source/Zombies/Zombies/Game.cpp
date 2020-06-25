#include "olcPixelGameEngine.h"

#include <vector>
#include <iostream>
#include <stdlib.h>

#include "Game.h"


/// <summary>
/// Constructor
/// </summary>
/// <returns></returns>
Game::Game() {

	SetupDebugLevel();
	SpawnPlayer();

	round = 1;
}

/// <summary>
/// Keeps track of time
/// </summary>
/// <param name="">Pointer to the pixel game engine</param>
void Game::Tick(olc::PixelGameEngine* pge, float timeElapsed) {

	Inputs(pge);
	MovePlayer(timeElapsed);

	SpawnZombies(timeElapsed);
	MoveZombies(timeElapsed);
}

/// <summary>
/// Deals with inputs
/// </summary>
/// <param name="">Pointer to the pixel game engine</param>
void Game::Inputs(olc::PixelGameEngine* pge) {

	WPressed = pge->GetKey(olc::Key::W).bHeld;
	APressed = pge->GetKey(olc::Key::A).bHeld;
	SPressed = pge->GetKey(olc::Key::S).bHeld;
	DPressed = pge->GetKey(olc::Key::D).bHeld;
}

/// <summary>
/// Draws all contents in the game
/// </summary>
/// <param name="pge">Pointer to the pixel game engine</param>
void Game::Draw(olc::PixelGameEngine* pge) {

	//draws the player
	player->Draw(pge);

	//draws out each zombie
	for (int i = zombies.size() - 1; i >= 0; i--)
		zombies[i].Draw(pge);
}

/// <summary>
/// Sets up a level
/// </summary>
/// <param name="levelFilePath">The file path of the level</param>
void Game::SetupLevel(std::string levelFilePath) {

	//sets up a level using the passed in file
}

/// <summary>
/// sets up a debug level
/// </summary>
void Game::SetupDebugLevel() {

	//adds in one zombie spawn point
	zombieSpawnPoints.push_back(SpawnPoint(200, 200, 10, 3));
	zombieSpawnPoints.push_back(SpawnPoint(20, 200, 10, 3));

	//sets the player spawn position
	playerSpawnPoint = SpawnPoint(20, 20, 10, 10);

}

/// <summary>
/// Spawns in the player
/// </summary>
void Game::SpawnPlayer() {

	//spawns in the player at the spawn point (randomly within the spawn radius)
	player = new Player(rand() % playerSpawnPoint.GetSpawnRadius() + playerSpawnPoint.GetX(), rand() % playerSpawnPoint.GetSpawnRadius() + playerSpawnPoint.GetY());

}

/// <summary>
/// Moves the player
/// </summary>
void Game::MovePlayer(float timeElapsed) {

	Vector* toMove = new Vector();

	if (WPressed)
		toMove->SetY(toMove->GetY() - 1);
	if (SPressed)
		toMove->SetY(toMove->GetY() + 1);

	if (APressed)
		toMove->SetX(toMove->GetX() - 1);
	if (DPressed)
		toMove->SetX(toMove->GetX() + 1);

	player->Move(toMove, timeElapsed);

	delete(toMove);
}


void Game::SpawnZombies(float timeElapsed) {

	for (int i = zombieSpawnPoints.size() - 1; i >= 0; i--)

		if (zombieSpawnPoints[i].CheckToSpawn(timeElapsed))

			zombies.push_back(Zombie(zombieSpawnPoints[i].GetX(), zombieSpawnPoints[i].GetY(), round));
}

void Game::MoveZombies(float timeElapsed) {

	for (int i = zombies.size() - 1; i >= 0; i--)

		zombies[i].Tick(timeElapsed, player);
}