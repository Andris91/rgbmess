// RdbConsoleDebug.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "ColorUtil.h"
#include "CycleColorsEffect.h"
#include "RgbController.h"
#include "RandomColorFadeInEffect.h"
using namespace std;

int main()
{

	KEY_COLOR keyColorRed = ColorUtil::rgbColorToKeyColor(RgbColor(1, 0, 0));
	KEY_COLOR keyColorGreen = ColorUtil::rgbColorToKeyColor(RgbColor(0, 1, 0));
	KEY_COLOR keyColorBlue = ColorUtil::rgbColorToKeyColor(RgbColor(0, 0, 1));

	RgbController& rgbController = RgbController::getInstance();

	vector<Effect*> effects = rgbController.getEffectQueue();

	//effects.push_back(new CycleColorsEffect(KeyRegion(Key(0, 0), Key(5, 5)), keyColorRed));
	//effects.push_back(new CycleColorsEffect(KeyRegion(Key(0, 6), Key(5, 10)), keyColorGreen));
	//effects.push_back(new RandomColorFadeInEffect(KeyRegion(Key(0, 6), Key(5, 10))));
	//effects.push_back(new RandomColorFadeInEffect(KeyRegion(Key(0, 11), Key(5, 17))));

	effects.push_back(new RandomColorFadeInEffect(KeyRegion(Key(0, 0), Key(5, 17))));

	rgbController.setEffectQueue(effects);

	rgbController.setColorLoopSleepMillis(30);

	rgbController.startColorLoop();

	//ze end
	system("pause");
	rgbController.stopColorLoop();
	return 0;
}

