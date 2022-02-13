#include "Texture.h"

Texture::Texture(const std::string& filename)
{
	mGraphics = Graphics::Instance();

	mTexture = AssetManager::Instance()->GetTexture(filename);

	SDL_QueryTexture(mTexture, NULL, NULL, &mHeight, &mWidth);
}

Texture::~Texture()
{
	mTexture = NULL;
	mGraphics = NULL;
}

void Texture::Render()
{
	mGraphics->DrawTexture(mTexture);
}
