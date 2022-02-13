#pragma once
// *********************************************
// Game manager will init everything in the game
// *********************************************

#include "Graphics.h"
#include "Timer.h"
#include "GameEntity.h"
class GameManager 
{
private:
	static GameManager* sInstance;

	bool mQuit;

	Graphics* mGraphics;

	SDL_Event mEvents; // pull all events in window

	Timer* mTimer;

	const int FRAME_RATE = 60;

	GameEntity* mParent;
	GameEntity* mChild;

public:

	static GameManager* Instance();
	static void Release();

	void Run();

private:

	GameManager();
	~GameManager();
};
#pragma once