#pragma once
#include "stdafx.h"
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

		static KEY_COLOR rgbColorToKeyColor(RgbColor color);
		static KEY_COLOR hsvColorToKeyColor(HsvColor color);

		static RgbColor keyColorToRgbColor(KEY_COLOR color);
		static HsvColor keyColorToHsvColor(KEY_COLOR color);

		static boolean isEqualKeyColor(KEY_COLOR colorOne, KEY_COLOR colorTwo);
		static boolean isEqualColorMatrix(COLOR_MATRIX colMatOne, COLOR_MATRIX colMatTwo);
		static boolean isEqualColorMatrixInRegion(COLOR_MATRIX colMatOne, COLOR_MATRIX colMatTwo, KeyRegion keyRegion);

		static COLOR_MATRIX setRegionColor(COLOR_MATRIX colorMatrix, KeyRegion keyRegion, KEY_COLOR colorOne);

};