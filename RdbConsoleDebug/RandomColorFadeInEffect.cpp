#include "stdafx.h"
#include "RandomColorFadeInEffect.h"
#include "ColorUtil.h"
using namespace std;

RandomColorFadeInEffect::RandomColorFadeInEffect(KeyRegion keyRegion) : ContinuousEffect(keyRegion) {

	//random fade in start value
	for (int col = keyRegion.topLeftKey.col; col <= keyRegion.bottomRightKey.col; col++) {
		for (int row = keyRegion.topLeftKey.row; row <= keyRegion.bottomRightKey.row; row++) {
			state[row][col].value = ((rand() % 100 + 1) / 100.0);
		}
	}

};

COLOR_MATRIX RandomColorFadeInEffect::applyStep(COLOR_MATRIX currentState) {
 
	for (int col = keyRegion.topLeftKey.col; col <= keyRegion.bottomRightKey.col; col++) {
		for (int row = keyRegion.topLeftKey.row; row <= keyRegion.bottomRightKey.row; row++) {

			double hue = 0;
			
			//new color every fade out
			if (this->state[row][col].value <= 0.1) {
				state[row][col].fadeIn = true;
				state[row][col].value = 0.1;
				hue = rand() % 359;
			}
			else {
				hue = ColorUtil::keyColorToHsvColor(currentState.KeyColor[row][col]).h;
			}


			double diff = ((rand() % 3 + 1)  / 100.0);

			//Decide wether to inc or dec the val
			if(state[row][col].fadeIn){
				state[row][col].value = state[row][col].value + diff;
			}
			else {
				state[row][col].value = state[row][col].value - diff;
			}

			//switch on 100
			if (state[row][col].value >= 1.0) {
				state[row][col].fadeIn = false;
				state[row][col].value = 1.0;
			}

			char* fadeIn = "fadeIn";
			if (!state[row][col].fadeIn) {
				fadeIn = "fadeOut";
			}
			
			//cout << "hue: " << hue << ", v: " << state[row][col].value << " diff: " << diff << " fadeIn: " << fadeIn << "\n";

			HsvColor hsvColor = HsvColor(hue, 1.0, state[row][col].value);
			
			currentState.KeyColor[row][col] = ColorUtil::hsvColorToKeyColor(hsvColor);
		}
	}

	if (this->stopFlagState && ColorUtil::isEqualColorMatrixInRegion(currentState, stopState, keyRegion)) {
		this->stopFlag = true;
	}

	return currentState;
}