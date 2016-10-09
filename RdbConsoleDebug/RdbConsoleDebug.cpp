// RdbConsoleDebug.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <string>
#include <iostream>
#include "ColorUtil.h"
#include "CycleColorsEffect.h"
using namespace std;

void colorLoop(vector<Effect*> effects) {

	//init state
	COLOR_MATRIX currentState;

	int i = 0;
	while (true) {

		for (auto &effect : effects){
			currentState = effect->applyStep(currentState);
		}

		SetAllLedColor(currentState);

		Sleep(50);
		i++;

		for (auto &effect : effects) {
			if (effect->shouldStop()) {
				return;
			}
		}

	}

}

int main()
{
	SetControlDevice(DEVICE_INDEX::DEV_MKeys_S);

	if (!IsDevicePlug()) {
		cout << "Device not plugged in, exiting\n";
		return 1;
	}
	else {
		cout << "DEVICE_INDEX::DEV_MKeys_S keboard detected\n";
	}

	if (!EnableLedControl(true)) {
		cout << "Unable to EnableLedControl, exiting";
		return 1;
	};

	KEY_COLOR keyColorRed = ColorUtil::rgbColorToKeyColor(RgbColor(1, 0, 0));
	KEY_COLOR keyColorGreen = ColorUtil::rgbColorToKeyColor(RgbColor(0, 1, 0));
	KEY_COLOR keyColorBlue = ColorUtil::rgbColorToKeyColor(RgbColor(0, 0, 1));

	vector<Effect*> effects;
	effects.push_back(new CycleColorsEffect(KeyRegion(Key(0, 0), Key(5, 5)), keyColorRed));
	effects.push_back(new CycleColorsEffect(KeyRegion(Key(0, 6), Key(5, 10)), keyColorGreen));
	effects.push_back(new CycleColorsEffect(KeyRegion(Key(0, 11), Key(5, 17)), keyColorBlue));

	//start thread
	std::thread rgbThread(colorLoop, effects);
	
	Sleep(10000);

	((CycleColorsEffect*)effects.at(0))->setStopFlag(true);
	rgbThread.join();
	EnableLedControl(false);

	//useless but nice
	for (auto &effect : effects) {
		delete effect;
	}

	return 0;
}

