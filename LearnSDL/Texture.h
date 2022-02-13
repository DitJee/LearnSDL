#pragma once
#include "GameEntity.h"
#include "AssetManager.h"
class Texture : public GameEntity
{
private:

	SDL_Texture* mTexture;
	Graphics* mGraphics;

	int mHeight;
	int mWidth;

public:

	Texture(const std::string& filename);
	~Texture();

	virtual void Render();
};