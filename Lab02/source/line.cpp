#include "shape.h"

void Line::draw(int) {
    glBegin(GL_LINES);
    glVertex2f(100, 360);  
    glVertex2f(924, 360);
    glEnd();
}   