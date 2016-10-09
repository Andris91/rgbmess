#pragma once

class HsvColor {
public:
	HsvColor();
	HsvColor(double h, double s, double v);

	double h;       // angle in degrees
	double s;       // percent
	double v;       // percent
};