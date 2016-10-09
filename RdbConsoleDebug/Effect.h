#pragma once
#include "stdafx.h"
#include "KeyRegion.h"

class Effect {

public:

	//apply a step relative to the last state
	//hmm?? store last state or fetch it, fetching it is cleaner
	virtual COLOR_MATRIX applyStep(COLOR_MATRIX colorMatrix) = 0;
	boolean isStopped();

protected:
	KeyRegion keyRegion;
	boolean stopFlag;
	Effect();

};