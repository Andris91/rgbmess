#pragma once
#include "stdafx.h"

class FadeInOutEffect {
public:
	void start(KeyRegion keyRegion);
	void stop();
private:
	boost::thread effectThread;
	boolean shouldThreadStop = false;
	void loop(KeyRegion keyRegion);
};