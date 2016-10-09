#pragma once
#include "Effect.h"
#include "stdafx.h"


class FiniteEffect : public Effect {
public:
	virtual COLOR_MATRIX applyStep(COLOR_MATRIX currentState) = 0;
protected:
	COLOR_MATRIX targetState;
	FiniteEffect(KeyRegion keyRegion, COLOR_MATRIX targetState);
};
