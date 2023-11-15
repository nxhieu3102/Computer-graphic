#include "shape.h"

void Oval::draw(int type) {
	switch (type % 10) {
	case 1: {
		float centerX = 512, centerY = 360, radiusX = 25, radiusY = 50;
		int numSegments = 180;
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < numSegments; i++) {
			float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
			float x = radiusX * cosf(theta);
			float y = radiusY * sinf(theta);

			glVertex2f(x + centerX, y + centerY);
		}
		glEnd();
		break;
	}
	case 0: {
		float centerX = 512, centerY = 360, radiusX = 25, radiusY = 25;
		int numSegments = 180;
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < numSegments; i++) {
			float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
			float x = radiusX * cosf(theta);
			float y = radiusY * sinf(theta);

			glVertex2f(x + centerX, y + centerY);
		}
		glEnd();
		break;
	}
	default:
		break;
	}
}