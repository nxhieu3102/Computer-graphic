#include "render.h"

Render* Render::instance = nullptr;

Render::Render() {
	this->frameBuffer = new float[1024 * 720 * 3] {0};
}

void Render::defautView() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glFlush();
}

void Render::shapeView(int id) {
	if (id >= 80) {
		RGBColor* color = nullptr;
		int type = id%10;
		switch (type) {
		case 0:
			color = new RGBColor(0, 1.0, 0);
			break;
		case 1:
			color = new RGBColor(1.0, 0, 0);
			break;
		case 2:
			color = new RGBColor(1.0, 1.0, 0);
			break;
		default:
			break;
		}
		if (color != nullptr) {
			int start = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
			std::cout << "Start boundary fill\n";
			boundaryFill(new RGBColor(1.0, 1.0, 1.0), color, 512, 360);
			Render* render = getRenderInstance();
			glDrawPixels(1024, 720, GL_RGB, GL_FLOAT, render->frameBuffer);
			glFlush();
			std::cout << "End boundary fill\n";
			int end = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
			std::cout << "Time: " << end - start << "ms\n";
		}
	}
	else {
		glClear(GL_COLOR_BUFFER_BIT);
		Shape* shape = shapeFactory(id);
		shape->draw(id);
		glFlush();
	}
}

void Render::boundaryFill(RGBColor* line, RGBColor* wanted, int startX, int startY) {
	Render* render = getRenderInstance();
	std::stack<std::pair<int, int>> pixelStack;
	pixelStack.push(std::make_pair(startX, startY));
	vector< vector<bool> > visited(1025, vector<bool>(721, false));

	clear();
	while (!pixelStack.empty()) {
		pair<int, int> top = pixelStack.top();
		pixelStack.pop();

		int x = top.first;
		int y = top.second;
		
		visited[x][y] = true;

		int pos = getPosPixel(x, y);
		
		RGBColor* currentPixelColor = new RGBColor(render->frameBuffer[pos], render->frameBuffer[pos + 1], render->frameBuffer[pos + 2]);
		RGBColor* currentPixelColor2 = getPixel(x, y);

		if (currentPixelColor != nullptr && !RGBColor::isSameColor(currentPixelColor2, line) && !RGBColor::isSameColor(currentPixelColor, wanted) && x > 0 && x < 1024 && y > 0 && y < 720) {
			render->frameBuffer[pos] = wanted->getRed();
			render->frameBuffer[pos + 1] = wanted->getGreen();
			render->frameBuffer[pos + 2] = wanted->getBlue();

			if (visited[x + 1][y] == false) {
				pixelStack.push(std::make_pair(x + 1, y));
			}
			if (visited[x - 1][y] == false) {
				pixelStack.push(std::make_pair(x - 1, y));
			}
			if (visited[x][y + 1] == false) {
				pixelStack.push(std::make_pair(x, y + 1));
			}
			if (visited[x][y - 1] == false) {
				pixelStack.push(std::make_pair(x, y - 1));
			}
		}
	}
}

Render* Render::getRenderInstance() {
	if(instance == nullptr)
		instance = new Render();
	return instance;
}

void Render::clear() {
	Render* render = getRenderInstance();
	for (int i = 0; i < 1024 * 720 * 3; ++i) {
		render->frameBuffer[i] = 0;
	}
}