#include "GameManager.h"


GameManager* GameManager::sInstance = NULL;

GameManager* GameManager::Instance()
{
	if (sInstance == NULL)
	{
		sInstance = new GameManager();
	}

	return sInstance;
}

void GameManager::Release()
{
	delete sInstance;
	sInstance = NULL;

}

GameManager::GameManager()
{
	mQuit = false;
	mGraphics = Graphics::Instance();

	if (!Graphics::Initialize())
	{
		mQuit = true;
	}

	mTimer = Timer::Instance();

	// get path at .exe
	std::string path = SDL_GetBasePath();
	path.append("Assets/me.png");

	mTexture = new Texture(path);
}

GameManager::~GameManager()
{
	Graphics::Release();
	mGraphics = NULL;

	// release timer
	mTimer->Release();
	mTimer = NULL;

	// delete texture
	delete mTexture;
	mTexture = NULL;
}

void GameManager::Run()
{
	while (!mQuit)
	{

		mTimer->Update();

		while (SDL_PollEvent(&mEvents) != 0)
		{
			if (mEvents.type == SDL_QUIT)
			{
				mQuit = true;
			}
			
		}

		if (mTimer->DeltaTime() >= (1.0f / FRAME_RATE))
		{
			//printf("Delta time: %f \n", mTimer->DeltaTime());
			mGraphics->ClearBackBuffer();

			// draw texture
			mTexture->Render();

			mGraphics->Render();	

			mTimer->Reset();

		}
	}
}