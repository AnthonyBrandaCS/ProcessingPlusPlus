#pragma once

#include "Display.hpp"

class ProcessingManager : public Display
{
private:
	float translateX = 0;
	float translateY = 0;

	int strokeR;
	int strokeG;
	int strokeB;
	int strokeA;

	int strokeW;

public:
	float width;
	float height;

	ProcessingManager() { ProcessingManager(150, 150, ""); width = height = 150; };
	ProcessingManager(const int _width, const int _height, const char* _title);

	void background(int b, int a);
	void background(int r, int g, int b, int a);

	void stroke(int b, int a);
	void stroke(int r, int g, int b, int a);

	void strokeWeight(int w);

	void point(float x, float y);

	void line(float x1, float y1, float x2, float y2);

	int sec();
	int min();
	int hour();
	int day();
	int month();
	int year();

	float map(float v, float a, float b, float c, float d);

	float min(float a, float b);

	float max(float a, float b);

	float random(float a);
	float random(float a, float b);

	float radians(float a);

	float _sin(float a);
	float _cos(float a);
	float _tan(float a);

	float _asin(float a);
	float _acos(float a);
	float _atan(float a);
};