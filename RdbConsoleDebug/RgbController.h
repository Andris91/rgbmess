#pragma once
#include "ColorUtil.h"
#include "CycleColorsEffect.h"
#include "stdafx.h"

class RgbController {

private:

	// Private Constructor
	RgbController();
	~RgbController();
	// Stop the compiler generating methods of copy the object
	RgbController(RgbController const& copy);            // Not Implemented
	RgbController& operator=(RgbController const& copy); // Not Implemented

	std::vector<Effect*> effectQueue;
	DWORD colorLoopSleep = 10;
	std::thread colorLoopThread;
	void loop();
	boolean colorLoopStopFlag = false;

public:

	static RgbController& getInstance();

	std::vector<Effect*> getEffectQueue();
	void setEffectQueue(std::vector<Effect*> effects);
	void setColorLoopSleepMillis(DWORD colorLoopSleep);

	void startColorLoop();
	void stopColorLoop();

};