#ifndef _TIMER_H
#define _TIMER_H

#include <windows.h>

class Timer
{
	public:
		// Timer ctor
		Timer();
		// Timer dtor
		~Timer();

		// Init the game time
		void								InitGameTime();
		// Gets the current game time
		float								GetGameTime();
		// Gets the FPS
		float								GetFramesPerSecond();
		// Gets the DT
		float								GetDeltaTime();

	private:
		float								timeAtGameStart;
		UINT64								ticksPerSecond;

		float								lastUpdate;
		float								fpsUpdateInterval;
		unsigned int						numFrames;
		float								fps;

		float								lastGameTime;
};

#endif//_TIMER_H
