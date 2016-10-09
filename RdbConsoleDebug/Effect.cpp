#include "stdafx.h"
#include "Effect.h"

Effect::Effect() {};

boolean Effect::isStopped() {
	return this->stopFlag;
}