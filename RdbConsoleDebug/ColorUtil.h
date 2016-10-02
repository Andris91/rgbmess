#pragma once
#include "rgb.h"
#include "hsv.h"

class ColorUtil {
	public:
		static hsv rgb2hsv(rgb in);
		static rgb hsv2rgb(hsv in);
};