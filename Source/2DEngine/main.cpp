// 2Dengine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

Game* game = nullptr;

int main(int argc, char *args[])
{
	game = new Game("2DEngine",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800,660, false);

	while(game->IsRunning())
	{
		game->HandleEvents();
		game->Update();
		game->Render();
	}
	game->~Game();
    return 0;
}

