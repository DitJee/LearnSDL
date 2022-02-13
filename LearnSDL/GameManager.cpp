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

	// init game entities
	mParent = new GameEntity(100.0f, 400.0f);
	mChild = new GameEntity(100.0f, 500.0f);

	printf("child local pos %f , %f \n", mChild->Pos(GameEntity::SPACE::world).x, mChild->Pos(GameEntity::SPACE::world).y);
	// set parent
	mChild->Parent(mParent);

	printf("child relative pos %f , %f \n", mChild->Pos(GameEntity::SPACE::world).x, mChild->Pos(GameEntity::SPACE::world).y);

}

GameManager::~GameManager()
{
	Graphics::Release();
	mGraphics = NULL;

	// release timer
	mTimer->Release();
	mTimer = NULL;

	delete mParent;
	delete mChild;
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

			// rotation the parent
			mParent->Rotation(mParent->Rotation(GameEntity::SPACE::local) + 0.1f);

			printf("parent rotation: %f \n", mParent->Rotation(GameEntity::SPACE::local));
			printf("child relative pos: %f, %f \n", mChild->Pos(GameEntity::SPACE::world).x, mChild->Pos(GameEntity::SPACE::world).y);
			mGraphics->Render();	

			mTimer->Reset();

		}
	}
}