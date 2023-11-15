#pragma once
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

#include "render.h"
#include "menu.h"
#include "shape.h"
#include "rgbcolor.h"
void initWindow();
Shape* shapeFactory(int);
RGBColor* getPixel(int, int);
int getPosPixel(int, int);