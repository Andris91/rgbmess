#pragma once
#include "rgb.h"
#include "hsv.h"
#include "Key.h"
#include "KeyRegion.h"

class ColorUtil {
	public:
		
		static void setRegionFromHsv(KeyRegion keyregion, hsv color);
		static void setRegionFromRgb(KeyRegion keyregion, rgb color);

		static void setFullFromHsv(hsv color);
		static void setFullFromRgb(rgb color);
		
		static hsv rgb2hsv(rgb in);
		static rgb hsv2rgb(hsv in);

};