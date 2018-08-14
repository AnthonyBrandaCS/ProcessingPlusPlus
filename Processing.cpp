#include "Processing.h"

#include <iostream>

#include <GL/glew.h>

using namespace std;

Processing::Processing(int _width, int _height, const std::string& _title)
	:Display(_width, _height, _title)
{
}

void Processing::background(float b) {
	glClearColor(b / 255.0f, b / 255.0f, b / 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Processing::background(float r, float g, float b) {
	glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Processing::background(float r, float g, float b, float a) {
	glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a);
	glClear(GL_COLOR_BUFFER_BIT);
}



void Processing::line(float x1, float y1, float x2, float y2)
{
	x1 = ((x1 + translateX) / (width / 2)) - 1;
	y1 = 1 - ((y1 + translateY) / (height / 2));

	x2 = ((x2 + translateX) / (width / 2)) - 1;
	y2 = 1 - ((y2 + translateY) / (height / 2));

	glLineWidth(3);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
}