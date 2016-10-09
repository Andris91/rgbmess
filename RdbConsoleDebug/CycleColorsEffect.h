#pragma once
#include "ContinuousEffect.h"
#include "stdafx.h"

class CycleColorsEffect : public ContinuousEffect{
public:
	CycleColorsEffect(KeyRegion keyRegion, KEY_COLOR startColor);
	COLOR_MATRIX applyStep(COLOR_MATRIX currentState);
private:
	KEY_COLOR startColor;
	int angleOffset;
	DWORD delay;
};