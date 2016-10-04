#include "ContinuousEffect.h"

void ContinuousEffect::setStopFlag(boolean stopFlag) {
	this->stopFlag = stopFlag;
}

void ContinuousEffect::stopWhenStateEq(COLOR_MATRIX targetState) {
	//TODO: make compare function on COLOR_MATRIX on given keyregion
}

ContinuousEffect::ContinuousEffect(KeyRegion keyRegion) {
	this->keyRegion = keyRegion;
}