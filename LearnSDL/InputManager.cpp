#include "InputManager.h"

InputManager* InputManager::sInstance = NULL;

InputManager* InputManager::Instance()
{
	if (sInstance == NULL)
	{
		sInstance = new InputManager();

	}

	return sInstance;
}

void InputManager::Release()
{
	delete sInstance;
	sInstance = NULL;
}

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

bool InputManager::KeyDown(SDL_Scancode scanCode)
{
	return mKeyBoardStates[scanCode];
}

void InputManager::Update()
{
	// fill up the array with all the KB states
	mKeyBoardStates = SDL_GetKeyboardState(NULL);
}