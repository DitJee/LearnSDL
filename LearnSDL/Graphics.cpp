#include "Graphics.h"

Graphics* Graphics::sInstance = NULL;
bool Graphics::sInitialized = false;

Graphics* Graphics::Instance()
{
	if (sInstance == NULL)
	{
		sInstance = new Graphics();

	}

	return sInstance;
}

void Graphics::Release()
{
	delete sInstance;
	sInstance = NULL;
	sInitialized = false;
}

bool Graphics::Initialize()
{
	return sInitialized;
}

Graphics::Graphics()
{
	mBackBuffer = NULL;

	sInitialized = Init();
}

Graphics::~Graphics()
{
	// TODO: clear all vars
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;

	SDL_Quit();
}

bool Graphics::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL init error %s \n", SDL_GetError());

		return false;
	}

	// if no error, create window
	mWindow = SDL_CreateWindow("LEARNSDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (mWindow == NULL)
	{
		printf("Window creation error %s \n", SDL_GetError());
		return false;
	}

	// get back buffer
	mBackBuffer = SDL_GetWindowSurface(mWindow);

	return true;
}

void Graphics::Render()
{
	SDL_UpdateWindowSurface(mWindow);
}