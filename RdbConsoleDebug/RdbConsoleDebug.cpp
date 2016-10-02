// RdbConsoleDebug.cpp : Defines the entry point for the console application.

#include "stdafx.h"
using namespace std;

//TODO refactor me
void transition(rgb fromColor, rgb toColor) {
	//At the start assume the whole thing is fromColor

	COLOR_MATRIX colorMatrix;
	for (int row = 0; row <= KeyRegion::MAX_ROW; row++) {
		for (int col = 0; col <= KeyRegion::MAX_COL; col++) {

			KEY_COLOR kc;
			kc.r = fromColor.r * 255;
			kc.g = fromColor.g * 255;
			kc.b = fromColor.b * 255;

			colorMatrix.KeyColor[row][col] = kc;
		}
	}

	//start progressively chainging colorMatrix and apply changes after each iteration

	//column by column
	for (int col = 0; col <= KeyRegion::MAX_COL; col++) {
		for (int row = 0; row <= KeyRegion::MAX_ROW; row++) {

			KEY_COLOR kc;
			kc.r = toColor.r * 255;
			kc.g = toColor.g * 255;
			kc.b = toColor.b * 255;

			colorMatrix.KeyColor[row][col] = kc;
		}
		//apply
		SetAllLedColor(colorMatrix);
		Sleep(200);
	}

};

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

	rgb rgbYellow(1, 1, 0);
	rgb rgbRed(1,0,0);
	rgb rgbGreen(0, 1, 0);
	hsv hsvRed = ColorUtil::rgb2hsv(rgbRed);
	hsv hsvYellow = ColorUtil::rgb2hsv(rgbYellow);
	hsv hsvGreen = ColorUtil::rgb2hsv(rgbGreen);

	FadeInOutEffect* fadeEffect1 = new FadeInOutEffect(hsvRed, 0.02, 50);
	fadeEffect1->start();
	Sleep(2500*3);
	fadeEffect1->stop();

	transition(rgbRed, rgbYellow);

	FadeInOutEffect* fadeEffect2 = new FadeInOutEffect(hsvYellow, 0.02, 50);
	fadeEffect2->start();
	Sleep(2500 * 3);
	fadeEffect2->stop();

	transition(rgbYellow, rgbGreen);

	FadeInOutEffect* fadeEffect3 = new FadeInOutEffect(hsvGreen, 0.02, 50);
	fadeEffect3->start();
	Sleep(2500 * 3);
	fadeEffect3->stop();

	delete fadeEffect1;
	delete fadeEffect2;
	delete fadeEffect3;
	
	EnableLedControl(false);
	return 0;
}

