#include "stdafx.h"
#include "Time.h"

double Time::deltaTime = 0;

Time::Time()
{
	Update();
}

Time::~Time()
{
	
}

//Should be updated before frame rendered
void Time::Update()
{
	LAST = NOW;	
	NOW = SDL_GetPerformanceCounter();
	deltaTime = double(((NOW - LAST) * 1000 / double(SDL_GetPerformanceFrequency()))) * 0.001f;
}


double Time::GetDeltaTime()
{
	return  deltaTime;
}

