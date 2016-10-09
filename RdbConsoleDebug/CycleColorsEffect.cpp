#include "stdafx.h"
#include "CycleColorsEffect.h"
using namespace std;

CycleColorsEffect::CycleColorsEffect(KeyRegion keyRegion) : ContinuousEffect(keyRegion) {};

COLOR_MATRIX CycleColorsEffect::applyStep(COLOR_MATRIX currentState) {
	return currentState;
}

/*
void start(KeyRegion keyRegion) {
	//start the looping thread and return
	effectThread = boost::thread(boost::bind(&CycleColorsEffect::loop, this, keyRegion));
}

void stop() {
	shouldThreadStop = true;
	effectThread.join();
}

void loop(KeyRegion keyregion) {

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
*/
