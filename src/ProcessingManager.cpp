#include "ProcessingManager.hpp"

#include <iostream>
#include <random>

#include <GL/glew.h>

using namespace std;

ProcessingManager::ProcessingManager(int _width, int _height, const char* _title)
	:Display(_width, _height, _title)
{
	width = _width;
	height = _height;
}

void ProcessingManager::background(int b, int a) {
	glClearColor((float)b / 255.0f, (float)b / 255.0f, (float)b / 255.0f, (float)a / 255.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void ProcessingManager::background(int r, int g, int b, int a) {
	glClearColor((float)r / 255, (float)g / 255, (float)b / 255, (float)a / 255);
	glClear(GL_COLOR_BUFFER_BIT);
}

void ProcessingManager::stroke(int b, int a) {
	strokeR = b;
	strokeG = b;
	strokeB = b;
	strokeA = a;
}

void ProcessingManager::stroke(int r, int g, int b, int a) {
	strokeR = r;
	strokeG = g;
	strokeB = b;
	strokeA = a;
}

void ProcessingManager::strokeWeight(int w)
{
	strokeW = w;
}

void ProcessingManager::point(float x, float y)
{
	x = ((x + translateX) / (width / 2)) - 1;
	y = 1 - ((y + translateY) / (height / 2));

	glPointSize((float)strokeW);
	glColor4f((float)strokeR / 255, (float)strokeG / 255, (float)strokeB / 255, (float)strokeA / 255);
	glBegin (GL_POINTS);
    glVertex2f (x, y);
    glEnd ();
}

void ProcessingManager::line(float x1, float y1, float x2, float y2)
{
	x1 = ((x1 + translateX) / (width / 2)) - 1;
	y1 = 1 - ((y1 + translateY) / (height / 2));

	x2 = ((x2 + translateX) / (width / 2)) - 1;
	y2 = 1 - ((y2 + translateY) / (height / 2));

	GLfloat lineWidthRange[2];
	glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, lineWidthRange);
    
	glLineWidth((float)strokeW);
	glColor4f((float)strokeR / 255, (float)strokeG / 255, (float)strokeB / 255, (float)strokeA / 255);
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
}

float ProcessingManager::map(float v, float a, float b, float c, float d)
{
	return (v - a) / (b - a) * (d - c) + c;
}

float ProcessingManager::random(float a)
{
	return random(0, a);
}

float ProcessingManager::random(float a, float b)
{
	return a + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(b-a)));
}