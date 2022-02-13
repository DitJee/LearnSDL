#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

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

	SDL_Renderer* mRenderer;

public:

	static Graphics* Instance(); // return the instance
	static void Release();
	static bool Initialize();

	void Render();

	SDL_Texture* LoadTexture(const std::string& path);

	void ClearBackBuffer(); // called every frame to clear the canvas

	void DrawTexture(SDL_Texture* texture);

private:

	Graphics();
	~Graphics();

	bool Init();


};

