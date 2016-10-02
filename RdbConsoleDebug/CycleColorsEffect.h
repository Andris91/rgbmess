#pragma once
#include "stdafx.h"

class CycleColorsEffect {
public:

	CycleColorsEffect(int angleOffset, DWORD delay);

	void start(KeyRegion keyRegion);
	void stop();

private:
	int angleOffset;
	DWORD delay;

	boost::thread effectThread;
	boolean shouldThreadStop = false;

	void loop(KeyRegion keyRegion);
};