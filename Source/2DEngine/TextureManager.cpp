#include "stdafx.h"
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filePath)
{
	SDL_Surface* tmpSurface = IMG_Load(filePath);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(GameEngine::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tex;
}

void TextureManager::RenderTexture(SDL_Texture * texture, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(GameEngine::renderer, texture, &src, &dest);
}
