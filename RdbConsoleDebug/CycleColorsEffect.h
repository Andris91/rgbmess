#pragma once
#include "stdafx.h"

class CycleColorsEffect : public ContinuousEffect{
public:
	CycleColorsEffect(KeyRegion keyRegion);
	COLOR_MATRIX applyStep(COLOR_MATRIX currentState);
private:
	int angleOffset;
	DWORD delay;
};