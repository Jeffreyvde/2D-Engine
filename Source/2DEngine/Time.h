#pragma once
#include <SDL_hints.h>
#include <SDL.h>

class Time
{
public:

	Time();
	~Time();

	void Update();

	static double GetDeltaTime();
private:
	Uint64 LAST;
	Uint64 NOW;
	static double Time::deltaTime;


};

