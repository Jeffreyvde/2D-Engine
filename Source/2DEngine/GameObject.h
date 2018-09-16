#pragma once
#include "GameEngine.h"

class GameObject
{
public:
	GameObject(const char* texturePath, int x, int y);
	~GameObject();

	virtual void Update();
	void Render();

	void SetPosition(float xPos, float yPos);

protected:
	float X;
	float Y;

	SDL_Rect srcRect, destRect;

private:
	SDL_Texture* texture;

};

