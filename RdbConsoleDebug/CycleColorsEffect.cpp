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
	hsvColor.h = hsvColor.h + 10;

	KEY_COLOR newColor = ColorUtil::hsvColorToKeyColor(hsvColor);

	currentState = ColorUtil::setRegionColor(currentState, keyRegion, newColor);

	if (this->stopFlagState && ColorUtil::isEqualColorMatrixInRegion(currentState, stopState, keyRegion)) {
		this->stopFlag = true;
	}

	stepCount++;

	return currentState;
}