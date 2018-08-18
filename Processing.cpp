#include "Processing.h"

#include <iostream>

#include <GL/glew.h>

using namespace std;

#pragma region constructor
Processing::Processing(int _width, int _height, const std::string& _title)
	:Display(_width, _height, _title)
{
}
#pragma endregion

#pragma region background
void Processing::background(int b) {
	glClearColor((float)b / 255.0f, (float)b / 255.0f, (float)b / 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Processing::background(int b, int a) {
	glClearColor((float)b / 255.0f, (float)b / 255.0f, (float)b / 255.0f, (float)a / 255.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Processing::background(int r, int g, int b) {
	glClearColor((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Processing::background(int r, int g, int b, int a) {
	glClearColor((float)r / 255, (float)g / 255, (float)b / 255, (float)a / 255);
	glClear(GL_COLOR_BUFFER_BIT);
}
#pragma endregion

#pragma region stroke
void Processing::stroke(int b) {
	strokeR = b;
	strokeG = b;
	strokeB = b;
	strokeA = b;
}

void Processing::stroke(int b, int a) {
	strokeR = b;
	strokeG = b;
	strokeB = b;
	strokeA = a;
}

void Processing::stroke(int r, int g, int b) {
	strokeR = r;
	strokeG = g;
	strokeB = b;
	strokeA = 255;
}

void Processing::stroke(int r, int g, int b, int a) {
	strokeR = r;
	strokeG = g;
	strokeB = b;
	strokeA = a;
}
#pragma endregion

#pragma region line
void Processing::line(float x1, float y1, float x2, float y2)
{
	x1 = ((x1 + translateX) / (width / 2)) - 1;
	y1 = 1 - ((y1 + translateY) / (height / 2));

	x2 = ((x2 + translateX) / (width / 2)) - 1;
	y2 = 1 - ((y2 + translateY) / (height / 2));

	glLineWidth(1);
	glColor4f((float)strokeR / 255, (float)strokeG / 255, (float)strokeB / 255, (float)strokeA / 255);
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
}
#pragma endregion