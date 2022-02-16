#pragma once
#include "Graphics.h"
#include <map>

// *******************************************
// ******* serve as a cache for assets *******
// *******************************************

class AssetManager 
{
private:
	static AssetManager* sInstance;

	std::map<std::string, SDL_Texture*> mTextures;
	std::map<std::string, SDL_Texture*> mTexts;
	std::map<std::string, TTF_Font*>    mFonts;

public:

	static AssetManager* Instance();
	static void Release();

	SDL_Texture* GetTexture(const std::string& filename);
	SDL_Texture* GetText(const std::string& text, const std::string& filename, int size, SDL_Color color);
private:
	AssetManager();
	~AssetManager();

	TTF_Font* GetFont(const std::string& filename, int size);
};