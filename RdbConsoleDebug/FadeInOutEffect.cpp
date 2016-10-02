#include "stdafx.h"
using namespace std;

void FadeInOutEffect::start(KeyRegion keyRegion) {
	//start the looping thread and return
	effectThread = boost::thread(boost::bind(&FadeInOutEffect::loop, this, keyRegion));
}

void FadeInOutEffect::stop() {
	shouldThreadStop = true;
	effectThread.join();
}

void FadeInOutEffect::loop(KeyRegion keyregion) {
	cout << "region " << keyregion.bottomLeftCol << ", " << keyregion.topLeftCol << "\n";
	for (int i = 100000; i > 0; i++) {
		cout << i << "\n";
		Sleep(500);
		if (shouldThreadStop) {
			break;
		}
	}
}