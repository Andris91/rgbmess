#pragma once
#include "RgbColor.h"
#include "HsvColor.h"
#include "Key.h"
#include "KeyRegion.h"

class ColorUtil {
	public:
		
		static void setRegionFromHsv(KeyRegion keyregion, HsvColor color);
		static void setRegionFromRgb(KeyRegion keyregion, RgbColor color);

		static void setFullFromHsv(HsvColor color);
		static void setFullFromRgb(RgbColor color);
		
		static HsvColor rgb2hsv(RgbColor in);
		static RgbColor hsv2rgb(HsvColor in);

};