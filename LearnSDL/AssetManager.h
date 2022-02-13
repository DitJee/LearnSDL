#pragma once
#include "Graphics.h"
#include <map>

class AssetManager
{
private:
	static AssetManager* sInstance;

	std::map<std::string, SDL_Texture*> mTextures;

public:

	static AssetManager* Instance();
	static void Release();

	SDL_Texture* GetTexture(const std::string& filename);

private:
	AssetManager();
	~AssetManager();
};