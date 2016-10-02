#pragma once
#include "Key.h"

class KeyRegion {
public:
	static const int MAX_ROW = 5;
	static const int MAX_COL = 17;

	Key topLeftKey;
	Key bottomRightKey;

	KeyRegion(Key topLeftKey, Key bottomRightKey);
};