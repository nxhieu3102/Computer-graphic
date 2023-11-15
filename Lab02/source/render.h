#pragma once
#include <GL/glut.h>
#include "shape.h"
#include "helper.h"
#include "rgbcolor.h"
#include <chrono>
#include <stack>
class Render{
private:
	float* frameBuffer;
private:
	Render();
private:
	static Render* instance;
public:
	void static defautView();
	void static shapeView(int);
	void static boundaryFill(RGBColor*, RGBColor*, int, int);
	static void clear();
	static Render* getRenderInstance();
};