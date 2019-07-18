#include "ProcessingManager.hpp"

#include <iostream>
#include <time.h>
#include <random>
#include <math.h>

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

struct tm* getTime()
{
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	return timeinfo;
}

int ProcessingManager::sec()
{
	struct tm* t = getTime();
	int sec = t->tm_sec;
	//delete t;
	return sec;
}
int ProcessingManager::min()
{
	struct tm* t = getTime();
	int min = t->tm_min;
	//delete t;
	return min;
}
int ProcessingManager::hour()
{
	struct tm* t = getTime();
	int hour = t->tm_hour;
	//delete t;
	return hour;
}
int ProcessingManager::day()
{
	struct tm* t = getTime();
	int day = t->tm_mday;
	//delete t;
	return day;
}
int ProcessingManager::month()
{
	struct tm* t = getTime();
	int month = t->tm_mon;
	//delete t;
	return month;
}
int ProcessingManager::year()
{
	struct tm* t = getTime();
	int year = t->tm_year;
	//delete t;
	return year;
}

float ProcessingManager::map(float v, float a, float b, float c, float d)
{
	return (v - a) / (b - a) * (d - c) + c;
}

float ProcessingManager::min(float a, float b)
{
	return a < b ? a : b;
}

float ProcessingManager::max(float a, float b)
{
	return a > b ? a : b;
}

float ProcessingManager::random(float a)
{
	return random(0, a);
}

float ProcessingManager::random(float a, float b)
{
	return a + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(b-a)));
}

float ProcessingManager::radians(float a)
{
	return a * 3.141592f / 180.f;
}

float ProcessingManager::_sin(float a)
{
	return std::sin(a);
}

float ProcessingManager::_cos(float a)
{
	return std::cos(a);
}

float ProcessingManager::_tan(float a)
{
	return std::tan(a);
}
	
float ProcessingManager::_asin(float a)
{
	return std::asin(a);
}

float ProcessingManager::_acos(float a)
{
	return std::acos(a);
}

float ProcessingManager::_atan(float a)
{
	return std::atan(a);
}