#include "shape.h"

void Math::draw(int type) {
	switch (type%10) {
	case 0: {
		glBegin(GL_LINE_LOOP);
		glVertex2i(500, 390);
		glVertex2i(520, 390);
		glVertex2i(520, 370);
		glVertex2i(540, 370);
		glVertex2i(540, 350);
		glVertex2i(520, 350);
		glVertex2i(520, 330);
		glVertex2i(500, 330);
		glVertex2i(500, 350);
		glVertex2i(480, 350);
		glVertex2i(480, 370);
		glVertex2i(500, 370);
		glVertex2i(500, 390);
		glEnd();
		break;
	}
	case 1: {
		glBegin(GL_LINE_LOOP);
		glVertex2f(512 - 25, 360 - 10);
		glVertex2f(512 - 25, 360 + 10);
		glVertex2f(512 + 25, 360 + 10);
		glVertex2f(512 + 25, 360 - 10);
		glEnd();
		break;
	}
	case 2: {
		glBegin(GL_LINE_LOOP);
		glVertex2f(460, 380);
		glVertex2f(500, 380);
		glVertex2f(520, 355);
		glVertex2f(540, 380);
		glVertex2f(580, 380);
		glVertex2f(540, 330);
		glVertex2f(580, 280);
		glVertex2f(540, 280);
		glVertex2f(520, 305);
		glVertex2f(500, 280);
		glVertex2f(460, 280);
		glVertex2f(500, 330);
		glVertex2f(460, 380);
		glEnd();
		break;
	}
	case 3: {
		glBegin(GL_LINE_LOOP);
		glVertex2i(440, 400);
		glVertex2i(520, 400);
		glVertex2i(580, 280);
		glVertex2i(500, 280);
		glVertex2i(430, 400);
		glEnd();
	}
	default:
		break;
	}
}