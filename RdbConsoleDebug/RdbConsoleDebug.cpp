// RdbConsoleDebug.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "ColorUtil.h"
#include "CycleColorsEffect.h"
#include "RgbController.h"
#include "RandomColorFadeInEffect.h"
#include "StaticColorFadeInEffect.h"
#include "JenkinsRequestHelper.h"

boolean shouldStop = false;
DWORD pollSleep = 5000;

void setStopFlag() {
	system("pause");
	std::cout << "\n";
	shouldStop = true;
}

int main()
{
	//spaghetti!
	std::thread stopme(setStopFlag);

	//Colors
	RgbController& rgbController = RgbController::getInstance();
	std::vector<Effect*> effects = rgbController.getEffectQueue();
	Effect* buildEffect = new StaticColorFadeInEffect(KeyRegion(Key(0, 0), Key(5, 17)), RgbColor(1, 1, 1), 0.02);
	effects.push_back(buildEffect);
	rgbController.setEffectQueue(effects);
	rgbController.setColorLoopSleepMillis(35);
	rgbController.startColorLoop();

	BuildResult laskKnownResult = BuildResult::unknown;

	JenkinsRequestHelper jenkinsRequestHelper = JenkinsRequestHelper("http://localhost", "8080", "random");
	while (!shouldStop) {
		pplx::task<BuildStatus> task = jenkinsRequestHelper.getCurrentStatus();
		task.wait();

		BuildStatus bs = task.get();
		if (bs.result != BuildResult::unknown) {
			laskKnownResult = bs.result;
		}

		std::cout << "Build status: " << bs.toString().c_str() << ", last known result: " << BuildStatus::toString(laskKnownResult) << "\n";

		BuildResult br;
		if (bs.isBuilding) {
			br = laskKnownResult;
			((StaticColorFadeInEffect*)buildEffect)->unpause();
		}
		else {
			br = bs.result;
			((StaticColorFadeInEffect*)buildEffect)->pause();
		}

		switch (br)
		{
		case success:
			((StaticColorFadeInEffect*)buildEffect)->setTargetColor(RgbColor(0, 1, 0));
			break;
		case unstable:
			((StaticColorFadeInEffect*)buildEffect)->setTargetColor(RgbColor(1, 1, 0));
			break;
		case failed:
			((StaticColorFadeInEffect*)buildEffect)->setTargetColor(RgbColor(1, 0, 0));
			break;
		default:
			((StaticColorFadeInEffect*)buildEffect)->setTargetColor(RgbColor(1, 1, 1));
			break;
		}

		Sleep(pollSleep);
	}

	rgbController.stopColorLoop();
	stopme.join();
	return 0;
}

