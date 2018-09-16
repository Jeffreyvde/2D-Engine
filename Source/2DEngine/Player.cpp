#include "stdafx.h"
#include "Player.h"

void Player::Update()
{
	const float addPos = 100 * Time::GetDeltaTime();
	X += addPos;
	Y += addPos;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = X;
	destRect.y = Y;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}
