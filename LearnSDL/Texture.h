#pragma once
#include "GameEntity.h"
#include "Graphics.h"
class Texture : public GameEntity
{
private:

	SDL_Texture* mTexture;
	Graphics* mGraphics;

public:

	Texture(const std::string& path);
	~Texture();

	virtual void Render();
};