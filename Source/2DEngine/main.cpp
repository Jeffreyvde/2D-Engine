// 2Dengine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameEngine.h"

GameEngine* game = nullptr;

int main(int argc, char *args[])
{
	game = new GameEngine("2DEngine",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800,640, false);

	while(game->IsRunning())
	{
		game->HandleEvents();
		game->Update();
		game->Render();
	}
	game->~GameEngine();
    return 0;
}

