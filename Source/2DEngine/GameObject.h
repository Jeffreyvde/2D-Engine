#pragma once
#include "Game.h"
#include <cmath>

class GameObject
{
public:
	GameObject(const char* texturePath, SDL_Renderer* ren, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	float xPos;
	float yPos;

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

};

