#pragma once
#include "GameEntity.h"
#include "AssetManager.h"
class Texture : public GameEntity
{
protected:

	SDL_Texture* mTexture;
	Graphics* mGraphics;

	int mHeight;
	int mWidth;

	SDL_Rect mRenderRect;

	bool mClipped;
	SDL_Rect mClippedRect;

public:

	Texture(const std::string& filename);
	Texture(const std::string& filename, int x, int y, int w, int h);
	~Texture();

	virtual void Render();
};