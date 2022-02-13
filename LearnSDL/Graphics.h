#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL.h>
#include <stdio.h>

class Graphics
{
public :
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

private:
	static Graphics* sInstance;
	static bool sInitialized; // true if init correctly

	SDL_Window* mWindow;
	SDL_Surface* mBackBuffer;

public:

	static Graphics* Instance(); // return the instance
	static void Release();
	static bool Initialize();

	void Render();

private:

	Graphics();
	~Graphics();

	bool Init();


};

#endif // !_GRAPHICS_H
