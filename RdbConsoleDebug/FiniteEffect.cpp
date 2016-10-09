#include "stdafx.h"
#include "FiniteEffect.h"

FiniteEffect::FiniteEffect(KeyRegion keyRegion, COLOR_MATRIX targetState) {
	this->keyRegion = keyRegion;
	this->targetState = targetState;
}

COLOR_MATRIX FiniteEffect::applyStep(COLOR_MATRIX currentState) {
	return currentState;
}
