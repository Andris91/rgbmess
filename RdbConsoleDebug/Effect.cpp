#include "stdafx.h"
#include "Effect.h"

Effect::Effect() {};

boolean Effect::shouldStop() {
	return this->stopFlag;
}

KeyRegion Effect::getRegion() {
	return this->keyRegion;
}