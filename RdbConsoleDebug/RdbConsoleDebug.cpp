// RdbConsoleDebug.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "ColorUtil.h"
#include "CycleColorsEffect.h"
#include "RgbController.h"
#include "RandomColorFadeInEffect.h"
#include "StaticColorFadeInEffect.h"
#include "JenkinsRequestHelper.h"


DWORD pollSleep = 5000;

int main()
{

	BuildResult laskKnownResult = BuildResult::unknown;

	JenkinsRequestHelper jenkinsRequestHelper = JenkinsRequestHelper("http://localhost", "8080", "random");
	while (true) {
		pplx::task<BuildStatus> task = jenkinsRequestHelper.getCurrentStatus();
		task.wait();

		BuildStatus bs = task.get();
		if (bs.result != BuildResult::unknown) {
			laskKnownResult = bs.result;
		}

		std::cout << "Build status: " << bs.toString().c_str() << ", last known result: " << BuildStatus::toString(laskKnownResult) << "\n";
		Sleep(pollSleep);
	}

	/*
	KEY_COLOR keyColorRed = ColorUtil::rgbColorToKeyColor(RgbColor(1, 0, 0));
	KEY_COLOR keyColorGreen = ColorUtil::rgbColorToKeyColor(RgbColor(0, 1, 0));
	KEY_COLOR keyColorBlue = ColorUtil::rgbColorToKeyColor(RgbColor(0, 0, 1));

	RgbController& rgbController = RgbController::getInstance();

	vector<Effect*> effects = rgbController.getEffectQueue();

	//effects.push_back(new CycleColorsEffect(KeyRegion(Key(0, 0), Key(5, 5)), keyColorRed));
	//effects.push_back(new CycleColorsEffect(KeyRegion(Key(0, 6), Key(5, 10)), keyColorGreen));
	//effects.push_back(new RandomColorFadeInEffect(KeyRegion(Key(0, 6), Key(5, 10))));
	//effects.push_back(new RandomColorFadeInEffect(KeyRegion(Key(0, 11), Key(5, 17))));
	//effects.push_back(new RandomColorFadeInEffect(KeyRegion(Key(0, 0), Key(5, 17))));
	effects.push_back(new StaticColorFadeInEffect(KeyRegion(Key(0, 0), Key(5, 17)), RgbColor(0,1,0), 0.03));

	rgbController.setEffectQueue(effects);

	rgbController.setColorLoopSleepMillis(30);

	rgbController.startColorLoop();

	//ze end
	system("pause");
	rgbController.stopColorLoop();
	*/
}

