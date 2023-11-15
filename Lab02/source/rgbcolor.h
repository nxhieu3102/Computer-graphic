#pragma once
#include <GL/glut.h>

class RGBColor {
private:
	float red;
	float green;
	float blue;
public:
	bool static isSameColor(RGBColor*, RGBColor*);
public:
	RGBColor(float red, float green, float blue);
	float getRed();
	float getGreen();
	float getBlue();
};