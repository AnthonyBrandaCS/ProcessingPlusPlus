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

	float map(float v, float a, float b, float c, float d);

	float random(float a);
	float random(float a, float b);
};