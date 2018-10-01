#pragma once
#include "GameEngine.h"

class Map
{
public:

	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void RenderMap();

private:

	SDL_Rect src, dest;
	SDL_Texture* ground;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];
};

