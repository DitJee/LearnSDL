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

	// init input manager
	mInputManager = InputManager::Instance();

	mAnimatedTexture = new AnimatedTexture("SpriteSheet.png", 34, 16, 27, 32, 3, 0.2f, AnimatedTexture::ANIM_DIR::horizontal);
	
	mAnimatedTexture->WrapMode(AnimatedTexture::WRAP_MODE::loop);

	mAnimatedTexture->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
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

	// delete input manager
	mInputManager->Release();
	mInputManager = NULL;

	// delete texture
	delete mAnimatedTexture;
	mAnimatedTexture = NULL;
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
			// update KB input
			mInputManager->Update();

			mAnimatedTexture->Update();

			//printf("Delta time: %f \n", mTimer->DeltaTime());
			mGraphics->ClearBackBuffer();

			// draw texture
			mAnimatedTexture->Render();

			mGraphics->Render();	

			mTimer->Reset();

		}
	}
}