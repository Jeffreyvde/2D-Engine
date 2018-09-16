#pragma once
#include  "GameEngine.h"

class Map
{
public:

	Map();
	~Map();

	void LoadMap();
	void RenderMap();

private:

	SDL_Rect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

};

