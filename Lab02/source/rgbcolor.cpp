#include "rgbcolor.h"

bool RGBColor::isSameColor(RGBColor* color1, RGBColor* color2) {
	return color1->red == color2->red && color1->green == color2->green && color1->blue == color2->blue;
}

RGBColor::RGBColor(float red, float green, float blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}

float RGBColor::getRed() {
	return this->red;
}

float RGBColor::getGreen() {
	return this->green;
}

float RGBColor::getBlue() {
	return this->blue;
}