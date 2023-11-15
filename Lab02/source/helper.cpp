#include "helper.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 720;

void initWindow() {
    int argc = 1;
    char* argv[1] = { (char*)"Something" };
    glutInit(&argc, argv);
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Lab 2");
    glClearColor(0, 0, 0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(Render::defautView);
    Menu::createMenu();
    glutMainLoop();
}

Shape* shapeFactory(int type) {
    int par = type / 10;
    switch (par) {
    case 0:
		return new Line();
    case 2:
		return new Triangle();
    case 3:
        return new Quadrilateral();
    case 4:
        return new Oval();
    case 5:
        return new Polygon();
	case 6:
		return new Other();
	case 7:
		return new Math();
    default:
        return nullptr;
    }
}

RGBColor* getPixel(int x, int y) {
    GLfloat ptr[3]{};
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, ptr);
    RGBColor* color = new RGBColor(ptr[0], ptr[1], ptr[2]);
	return color;
}

int getPosPixel(int x, int y) {
	return (y * SCREEN_WIDTH + x) * 3;
}