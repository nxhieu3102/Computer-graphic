#include "shape.h"

void Other::draw(int type) {
	switch (type % 10) {
	case 1: {
		glBegin(GL_LINE_LOOP);
		glVertex2i(450, 385);
		glVertex2i(539, 385);
		glVertex2i(565, 469);
		glVertex2i(591, 385);
		glVertex2i(680, 385);
		glVertex2i(609, 334);
		glVertex2i(636, 250);
		glVertex2i(565, 302);
		glVertex2i(494, 250);
		glVertex2i(521, 334);
		glVertex2i(450, 385);
		glEnd();
		break;
	}
	case 0: {
		glBegin(GL_LINE_LOOP);
		glVertex2i(460, 430);
		glVertex2i(520, 490);
		glVertex2i(580, 430);
		glVertex2i(540, 430);
		glVertex2i(540, 320);
		glVertex2i(500, 320);
		glVertex2i(500, 430);
		glVertex2i(460, 430);

		glEnd();
		break;
	}
	default:
		break;
	}
}