#include "stdafx.h"
using namespace std;

/*
FadeInOutEffect::FadeInOutEffect(hsv color, double step, DWORD delay){
	this->color = color;
	this->step = step;
	this->delay = delay;
}

void FadeInOutEffect::start() {
	//start the looping thread and return

	KeyRegion* krp = NULL;

	effectThread = boost::thread(boost::bind(&FadeInOutEffect::loop, this, krp));
}

void FadeInOutEffect::start(KeyRegion keyRegion) {
	//start the looping thread and return
	effectThread = boost::thread(boost::bind(&FadeInOutEffect::loop, this, &keyRegion));
}

void FadeInOutEffect::stop() {
	shouldThreadStop = true;
	effectThread.join();
}

void FadeInOutEffect::loop(KeyRegion* keyregion) {

	double v = 0;

	while (true) {
		//in
		for (v; v <= 1; v = v + step) {
			color.v = v;
			//cout << "current: hue: " << color.h << ", saturation: " << color.s << ", value: " << color.v << "\n";

			if (keyregion == NULL) {
				ColorUtil::setFullFromHsv(color);
			}
			else {
				ColorUtil::setRegionFromHsv(*keyregion, color);
			}


			Sleep(delay);
		}

		if (shouldThreadStop) {
			return;
		}

		//out
		for (v = 1; v >= 0; v = v - step) {
			color.v = v;
			if (keyregion == NULL) {
				ColorUtil::setFullFromHsv(color);
			}
			else {
				ColorUtil::setRegionFromHsv(*keyregion, color);
			}
			Sleep(delay);
		}

		if (shouldThreadStop) {
			return;
		}
	}

}
*/