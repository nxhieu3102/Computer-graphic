#include "shape.h"

void Quadrilateral::draw(int type) {
	switch (type%10) {
	case Type::Rectangle: {
		glBegin(GL_LINE_LOOP);
		glVertex2f(512 - 50, 360 - 30);  
		glVertex2f(512 - 50, 360 + 30);
		glVertex2f(512 + 50, 360 + 30);
		glVertex2f(512 + 50, 360 - 30);
		glEnd();
		break;
	}
	case Type::Square: {
		glBegin(GL_LINE_LOOP);
		glVertex2f(512 - 50, 360 - 50);
		glVertex2f(512 - 50, 360 + 50);
		glVertex2f(512 + 50, 360 + 50);
		glVertex2f(512 + 50, 360 - 50);
		glEnd();
		break;
	}
	default:
		break;
	}

}