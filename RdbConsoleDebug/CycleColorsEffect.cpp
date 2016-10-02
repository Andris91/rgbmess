#include "stdafx.h"
using namespace std;

CycleColorsEffect::CycleColorsEffect(int angleOffset, DWORD delay) {
	this->angleOffset = angleOffset;
	this->delay = delay;
}

void CycleColorsEffect::start(KeyRegion keyRegion) {
	//start the looping thread and return
	effectThread = boost::thread(boost::bind(&CycleColorsEffect::loop, this, keyRegion));
}

void CycleColorsEffect::stop() {
	shouldThreadStop = true;
	effectThread.join();
}

void CycleColorsEffect::loop(KeyRegion keyregion) {

	//Start color
	hsv color;
	color.h = 0;
	color.s = 1;
	color.v = 1;

	//hue goes from 0 to 359
	while (true) {

		color.h = color.h + angleOffset;

		//Reset if needed
		if (color.h > 359) {
			color.h = 0;
		}

		ColorUtil::setRegionFromHsv(keyregion, color);
		Sleep(delay);

		if (shouldThreadStop) {
			return;
		}

	}

}