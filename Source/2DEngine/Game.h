#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "TextureManager.h"
#include "Time.h"

class Game
{
public:
	Game(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	~Game();

	void Update();
	void Render();

	void HandleEvents();

	bool IsRunning(){ return  isRuning; };
private:

	bool isRuning = false;

	SDL_Window* window;
	SDL_Renderer* renderer;

	Time time;
	float cnt;

};

