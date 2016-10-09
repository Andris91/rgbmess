#pragma once
#include "stdafx.h"
#include "Effect.h"

class ContinuousEffect : public Effect {
public:
	virtual COLOR_MATRIX applyStep(COLOR_MATRIX colorMatrix) = 0;

	void setStopFlag(boolean stopFlag);
	void stopWhenStateEq(COLOR_MATRIX targetState);


protected:
	boolean stopFlagState = false;
	COLOR_MATRIX stopState;
	ContinuousEffect(KeyRegion keyRegion);
};