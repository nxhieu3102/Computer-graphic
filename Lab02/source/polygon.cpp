#include "shape.h"

void Polygon::draw(int type) {
	switch (type % 10) {
	case 1: {
		glBegin(GL_LINE_LOOP);
		glVertex2f(487, 360);
		glVertex2f(499, 339);
		glVertex2f(524, 339);
		glVertex2f(537, 360);
		glVertex2f(524, 381);
		glVertex2f(499, 381);
		glEnd();
		break;
	}
	case 0: {
		glBegin(GL_LINE_LOOP);
		glVertex2f(550, 395);
		glVertex2f(592.8, 363.91);
		glVertex2f(576.45, 313.59);
		glVertex2f(523.55, 313.59);
		glVertex2f(507.2, 363.91);
		glEnd();
		break;
	}
	default:
		break;
	}
}