#pragma once
#include "ContinuousEffect.h"
#include "stdafx.h"

class RandomColorFadeInEffect : public ContinuousEffect {
public:
	struct KeyState {
		double value = 0;
		boolean fadeIn = true;
	};

	RandomColorFadeInEffect(KeyRegion keyRegion);
	COLOR_MATRIX applyStep(COLOR_MATRIX currentState);
private:
	KeyState state[KeyRegion::MAX_ROW+100][KeyRegion::MAX_COL+100];
};