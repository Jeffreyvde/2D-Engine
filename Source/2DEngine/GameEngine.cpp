#include "stdafx.h"
#include "GameEngine.h"
#include "Player.h"

GameObject* player;
GameObject* enemy;

SDL_Renderer* GameEngine::renderer = nullptr;

//Construct and initialize game class.
GameEngine::GameEngine(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
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

	player = new Player("Assets/Images/Player.png", 0,0);
	enemy = new Player("Assets/Images/Player.png", 100, 100);
	time = Time();
}

//Deconstruct game class.
GameEngine::~GameEngine()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "SDL cleaned" << std::endl;
}

//Update current game class
void GameEngine::Update()
{
	time.Update();
	player->Update();
	enemy->Update();
}

void GameEngine::Render()
{
	SDL_RenderClear(renderer);

	player->Render();
	enemy->Render();
	
	SDL_RenderPresent(renderer);
}

void GameEngine::HandleEvents()
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