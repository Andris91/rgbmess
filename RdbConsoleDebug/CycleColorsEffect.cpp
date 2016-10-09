#include "stdafx.h"
#include "ColorUtil.h"
#include "CycleColorsEffect.h"
using namespace std;

CycleColorsEffect::CycleColorsEffect(KeyRegion keyRegion, KEY_COLOR startColor) : ContinuousEffect(keyRegion) {
	this->startColor = startColor;
};

COLOR_MATRIX CycleColorsEffect::applyStep(COLOR_MATRIX currentState) {

	if (stepCount == 0) {
		currentState = ColorUtil::setRegionColor(currentState, keyRegion, startColor);
	}

	//Get current region color
	KEY_COLOR regionColor = currentState.KeyColor[keyRegion.topLeftKey.row][keyRegion.topLeftKey.col];

	HsvColor hsvColor = ColorUtil::keyColorToHsvColor(regionColor);
	hsvColor.h = hsvColor.h + 2;

	KEY_COLOR newColor = ColorUtil::hsvColorToKeyColor(hsvColor);

	currentState = ColorUtil::setRegionColor(currentState, keyRegion, newColor);

	if (this->stopFlagState && ColorUtil::isEqualColorMatrixInRegion(currentState, stopState, keyRegion)) {
		this->stopFlag = true;
	}

	stepCount++;

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
