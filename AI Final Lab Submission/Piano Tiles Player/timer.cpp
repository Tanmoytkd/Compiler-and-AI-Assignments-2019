#include "Timer.h"

Timer::Timer()
{
	this->lastUpdate        = 0;
	this->fpsUpdateInterval = 1.0f;
	this->numFrames         = 0;
	this->fps               = 0;
	this->lastGameTime      = 0;
	this->timeAtGameStart   = 0;

	this->InitGameTime();
}
Timer::~Timer()
{
}

// Init The Game Timer
void Timer::InitGameTime()
{
	// We need to know how often the clock is updated
	QueryPerformanceFrequency((LARGE_INTEGER *)&ticksPerSecond);

	//Gets the time at the start of the game
	timeAtGameStart = GetGameTime();
}

// Gets The Game Time
float Timer::GetGameTime()
{
	UINT64 ticks;
	float time;

	QueryPerformanceCounter((LARGE_INTEGER *)&ticks);

	time = (float)(__int64)ticks/(float)(__int64)ticksPerSecond;

	time -= timeAtGameStart;
	return time;
}

// Get Frames Per Second
float Timer::GetFramesPerSecond()
{
	numFrames++;
	float currentUpdate = GetGameTime();
	if( currentUpdate - lastUpdate > fpsUpdateInterval )
	{
		fps = numFrames / (currentUpdate - lastUpdate);
		lastUpdate = currentUpdate;
		numFrames = 0;
	}
	return fps;
}

// Get Delta Time
float Timer::GetDeltaTime()
{
	float dt = GetGameTime() - lastGameTime;
	lastGameTime += dt;
	return dt;
}
