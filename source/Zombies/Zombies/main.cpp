#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "Game.h"

// Override base class with your custom functionality
class PixelGameEngine : public olc::PixelGameEngine {
public:
	PixelGameEngine() {
		// Name you application
		sAppName = "Example";
	}

public:
	bool OnUserCreate() override {
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {


		//keeps track of how much time has passed
		timeSinceLastFrame += fElapsedTime;

		if (timeSinceLastFrame > targetFrameTime) {

			timeSinceLastFrame -= targetFrameTime;
			fElapsedTime = targetFrameTime;

			Clear(olc::DARK_BLUE);

			game.Tick(this, fElapsedTime);
			game.Draw(this);
		}


		return true;
	}

private:

	Game game;

	float frameRate = 60;

	float targetFrameTime = 1 / frameRate;

	float timeSinceLastFrame;
};

int main() {

	PixelGameEngine engine;

	if (engine.Construct(256, 240, 4, 4))
		engine.Start();

	return 0;
}
