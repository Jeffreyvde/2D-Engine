#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(const char* texturePath, int x, int y) : GameObject(texturePath, x, y) {};
	~Player();

	void Update() override;
};

