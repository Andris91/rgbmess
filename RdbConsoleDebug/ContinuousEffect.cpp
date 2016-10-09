#include "stdafx.h"
#include "ContinuousEffect.h"

void ContinuousEffect::setStopFlag(boolean stopFlag) {
	this->stopFlag = stopFlag;
}

void ContinuousEffect::stopWhenStateEq(COLOR_MATRIX targetState) {
	this->stopFlagState = true;
	this->stopState = targetState;
}

ContinuousEffect::ContinuousEffect(KeyRegion keyRegion) {
	this->keyRegion = keyRegion;
}