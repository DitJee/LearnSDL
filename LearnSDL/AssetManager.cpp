#include "AssetManager.h"

AssetManager* AssetManager::sInstance = NULL;

AssetManager* AssetManager::Instance()
{
	if (sInstance == NULL)
	{
		sInstance = new AssetManager();
		return sInstance;
	}
	return sInstance;
}

void AssetManager::Release()
{
	delete sInstance;
	sInstance = NULL;
}

AssetManager::AssetManager()
{

}

AssetManager::~AssetManager()
{
	// iterate through map of textures and destroy it
	for (auto texture: mTextures)
	{
		if (texture.second != NULL)
		{
			SDL_DestroyTexture(texture.second);
		}
	}

	mTextures.clear();
}

SDL_Texture* AssetManager::GetTexture(const std::string& filename)
{
	std::string FullPath = SDL_GetBasePath();
	FullPath.append("Assets/" + filename);

	if (mTextures[FullPath] == nullptr)
	{
		mTextures[FullPath] = Graphics::Instance()->LoadTexture(FullPath);
	}
	
	return mTextures[FullPath];
}