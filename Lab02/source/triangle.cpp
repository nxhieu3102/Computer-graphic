#include "shape.h"
//center (512, 360)
void Triangle::draw(int type) {
	switch (type % 10){
	case Type::Isosceles :{
		glBegin(GL_LINE_LOOP);
		glVertex2f(612, 358);
		glVertex2f(512, 460);
		glVertex2f(412, 358);
		glEnd();
		break;
	}
	case Type::Equilateral: {
		glBegin(GL_LINE_LOOP);
		glVertex2f(512, 273);  
		glVertex2f(412, 447);
		glVertex2f(612, 447);
		glEnd();
		break;
	}
	default:
		break;
	}
}