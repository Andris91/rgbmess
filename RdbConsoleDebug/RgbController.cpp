#include "stdafx.h"
#include "RgbController.h"
using namespace std;


RgbController::RgbController() {
	SetControlDevice(DEVICE_INDEX::DEV_MKeys_S);

	if (!IsDevicePlug()) {
		cout << "Device not plugged in, exiting\n";
	}
	else {
		cout << "DEVICE_INDEX::DEV_MKeys_S keboard detected\n";
	}

	if (!EnableLedControl(true)) {
		cout << "Unable to EnableLedControl";
	};
}

RgbController::~RgbController() {
	cout << "RgbController destructor called, bye bye!";
	if (colorLoopThread.joinable()) {
		colorLoopThread.join();
	}
	EnableLedControl(false);
}


RgbController& RgbController::getInstance()
{
	static RgbController instance;
	return instance;
}

vector<Effect*> RgbController::getEffectQueue() {
	return this->effectQueue;
}

void RgbController::setEffectQueue(vector<Effect*> effects) {
	this->effectQueue = effects;
}

void RgbController::setColorLoopSleepMillis(DWORD colorLoopSleep) {
	this->colorLoopSleep = colorLoopSleep;
}

void RgbController::startColorLoop() {
	colorLoopStopFlag = false;
	colorLoopThread = std::thread([this] { this->loop(); });
}

void RgbController::stopColorLoop() {
	colorLoopStopFlag = true;
	if(colorLoopThread.joinable()){
		colorLoopThread.join();
	}
}

void RgbController::loop() {
	//init state
	COLOR_MATRIX currentState;

	int i = 0;
	while (true) {

		cout << "Effect queue size: " << effectQueue.size() << "\n";

		for (auto &effect : this->effectQueue) {
			currentState = effect->applyStep(currentState);
		}

		SetAllLedColor(currentState);

		Sleep(this->colorLoopSleep);
		i++;

		//Effect management
		for (auto &effect : this->effectQueue) {
			if (effect->shouldStop()) {
				return;
			}
		}

		//stop no matter what
		if (colorLoopStopFlag) {
			return;
		}

	}

}