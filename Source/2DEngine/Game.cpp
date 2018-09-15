#include "stdafx.h"
#include "Game.h"
#include "GameObject.h"

GameObject* player;

//Construct and initialize game class.
Game::Game(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	const int flags = (fullscreen) ? SDL_WINDOW_FULLSCREEN : 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL initialized succesfully" << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window) std::cout << "Window created!" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRuning = true;
	}

	player = new GameObject("Assets/Images/Player.png", renderer,0,0);
	time = Time();
}

//Deconstruct game class.
Game::~Game()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "SDL cleaned" << std::endl;
}

//Update current game class
void Game::Update()
{
	time.Update();
	player->Update();
}

void Game::Render()
{
	SDL_RenderClear(renderer);

	player->Render();
	
	SDL_RenderPresent(renderer);
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRuning = false;
		break;
	}
}