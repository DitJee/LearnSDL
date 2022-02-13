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

	// init timer
	mTimer = Timer::Instance();

	// init asset manager
	mAssetManager = AssetManager::Instance();

	mTexture = new Texture("SpriteSheet.png", 32,16,60-32,50-16);
	
	mTexture->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
}

GameManager::~GameManager()
{
	Graphics::Release();
	mGraphics = NULL;

	// release timer
	mTimer->Release();
	mTimer = NULL;

	// delete asset manager
	mAssetManager->Release();
	mAssetManager = NULL;

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