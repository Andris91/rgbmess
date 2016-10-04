#include "KeyRegion.h"

KeyRegion::KeyRegion() {}

KeyRegion::KeyRegion(Key topLeftKey, Key bottomRightKey) {
	this->topLeftKey = topLeftKey;
	this->bottomRightKey = bottomRightKey;
}