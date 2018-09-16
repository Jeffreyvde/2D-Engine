#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "TextureManager.h"
#include "Time.h"

class GameEngine
{
public:
	GameEngine(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	~GameEngine();

	void Update();
	void Render();

	void HandleEvents();

	bool IsRunning(){ return  isRuning; };

	static SDL_Renderer* renderer;
private:

	bool isRuning = false;

	SDL_Window* window;

	Time time;
	float cnt;

};

