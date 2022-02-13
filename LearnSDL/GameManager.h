#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H
// *********************************************
// Game manager will init everything in the game
// *********************************************

#include "Graphics.h"
#include "Timer.h"
class GameManager 
{
private:
	static GameManager* sInstance;

	bool mQuit;

	Graphics* mGraphics;

	SDL_Event mEvents; // pull all events in window

	Timer* mTimer;

	const int FRAME_RATE = 60;

public:

	static GameManager* Instance();
	static void Release();

	void Run();

private:

	GameManager();
	~GameManager();
};
#endif // !_GAMEMANAGER_H
