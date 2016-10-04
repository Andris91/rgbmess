#pragma once
#include "stdafx.h"

class FiniteEffect : public Effect {
public:
	virtual COLOR_MATRIX applyStep(COLOR_MATRIX currentState);
protected:
	COLOR_MATRIX targetState;
	FiniteEffect(KeyRegion keyRegion, COLOR_MATRIX targetState);
};