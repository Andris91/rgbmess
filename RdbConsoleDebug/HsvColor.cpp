#include "stdafx.h"
#include "HsvColor.h"

HsvColor::HsvColor() {}

HsvColor::HsvColor(double h, double s, double v) {
	this->h = h;
	this->s = s;
	this->v = v;
}