#pragma once
// *********************************************
// Game manager will init everything in the game
// *********************************************


#include "Timer.h"
#include "Texture.h"
class GameManager 
{
private:
	static GameManager* sInstance;

	bool mQuit;

	Graphics* mGraphics;

	SDL_Event mEvents; // pull all events in window

	Timer* mTimer;

	const int FRAME_RATE = 60;

	Texture* mTexture;
public:

	static GameManager* Instance();
	static void Release();

	void Run();

private:

	GameManager();
	~GameManager();
};
#pragma once