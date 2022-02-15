#pragma once

#include <SDL.h>
class InputManager
{
private:
	static InputManager* sInstance;

	const Uint8* mKeyBoardStates;

public:
	static InputManager* Instance();
	static void Release();

	bool KeyDown(SDL_Scancode scanCode);

	void Update();

private:
	InputManager();
	~InputManager();

};