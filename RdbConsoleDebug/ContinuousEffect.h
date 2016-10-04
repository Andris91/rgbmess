#pragma once
#include "stdafx.h"

class ContinuousEffect : public Effect {
public:
	void setStopFlag(boolean stopFlag);
	void stopWhenStateEq(COLOR_MATRIX targetState);

	virtual COLOR_MATRIX applyStep(COLOR_MATRIX currentState);
protected:
	ContinuousEffect(KeyRegion keyRegion);
};