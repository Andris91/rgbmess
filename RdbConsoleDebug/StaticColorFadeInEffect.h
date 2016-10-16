#pragma once
#include "ContinuousEffect.h"
#include "stdafx.h"
#include "RgbColor.h"
#include "HsvColor.h"

class StaticColorFadeInEffect : public ContinuousEffect {
public:
	StaticColorFadeInEffect(KeyRegion keyRegion, RgbColor targetColor, double valueStep);
	COLOR_MATRIX applyStep(COLOR_MATRIX currentState);
	void setTargetColor(RgbColor targetColor);
	void pause();
	void unpause();
private:
	HsvColor targetColor;
	double valueStep = 0.05;
	boolean fadeIn = true;
	boolean isPaused = false;
	boolean isReallyPaused = false; //leave me alone
};