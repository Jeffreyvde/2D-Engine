#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(const char* texturePath, int x, int y)
{
	texture = TextureManager::LoadTexture(texturePath);
	X = x;
	Y = y;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	std::cout << X << std::endl;
	std::cout << Y << std::endl;
}

void GameObject::Render()
{
	TextureManager::RenderTexture(texture, srcRect, destRect);
}

void GameObject::SetPosition(float x, float y)
{
	X = x;
	Y = y;
}


