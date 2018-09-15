#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(const char* texturePath, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	texture = TextureManager::LoadTexture(texturePath, renderer);
	xPos = x;
	yPos = y;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	const float addPos = 100 * Time::GetDeltaTime();
	xPos += addPos;
	yPos += addPos;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}


