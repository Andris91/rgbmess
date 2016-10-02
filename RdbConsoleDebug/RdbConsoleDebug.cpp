// RdbConsoleDebug.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "boost\thread.hpp"

using namespace std;

boolean stopThreads = false;


void setFullFromHsv(hsv color) {
	rgb rgbcolor = ColorUtil::hsv2rgb(color);
	SetFullLedColor(rgbcolor.r * 255, rgbcolor.g * 255, rgbcolor.b * 255);
}

void setFullFromRgb(rgb color) {
	SetFullLedColor(color.r * 255, color.g * 255, color.b * 255);
}

void cycleColors(int angleOffset, DWORD deplay) {

	//Start color
	hsv color;
	color.h = 0;
	color.s = 1;
	color.v = 1;

	//hue goes from 0 to 359
	while (true) {

		color.h = color.h + angleOffset;

		//Reset if needed
		if (color.h > 359) {
			color.h = 0;
		}

		setFullFromHsv(color);
		Sleep(deplay);

		if (stopThreads) {
			return;
		}

	}

}

void fadeInOut(hsv color, double step, DWORD deplay) {
	double v = 0;

	while(true){	
		//in
		for (v; v <= 1; v = v + step) {
			color.v = v;
			//cout << "current: hue: " << color.h << ", saturation: " << color.s << ", value: " << color.v << "\n";
			setFullFromHsv(color);
			Sleep(deplay);

			if (stopThreads) {
				return;
			}
		}
		//out
		for (v = 1; v >= 0.2; v = v - step) {
			color.v = v;
			setFullFromHsv(color);
			Sleep(deplay);

			if (stopThreads) {
				return;
			}
		}
	}
}

int main()
{

	FadeInOutEffect* effect = new FadeInOutEffect();
	KeyRegion keyRegion;
	keyRegion.bottomLeftCol = 0;
	keyRegion.topLeftCol = 10;

	effect->start(keyRegion);

	Sleep(5000);

	effect->stop();

	delete effect;

	/*
	hsv hsvColor;
	hsvColor.h = 1;
	hsvColor.s = 1;
	hsvColor.v = 1;

	ColorUtil::hsv2rgb(hsvColor);
	
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

	
	rgb rgbRed;
	rgbRed.r = 1;
	rgbRed.g = 0;
	rgbRed.b = 0;

	hsv hsvRed = ColorUtil::rgb2hsv(rgbRed);

	thread cycler(cycleColors, 1, 100);
	//thread fader (fadeInOut, hsvRed, 0.03, 100);

	system("pause");
	stopThreads = true;
	cout << "shouldStop = " << stopThreads;
	//fader.join();
	cycler.join();

	EnableLedControl(false);
    return 0;
	*/
}