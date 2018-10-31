#pragma once

#include "Display.h"

class Processing : public Display
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

	Processing() { Processing(150, 150, ""); width = height = 150; };
	Processing(const int _width, const int _height, const std::string& _title);

	void background(int b);
	void background(int b, int a);
	void background(int r, int g, int b);
	void background(int r, int g, int b, int a);

	void stroke(int b);
	void stroke(int b, int a);
	void stroke(int r, int g, int b);
	void stroke(int r, int g, int b, int a);

	void strokeWeight(int w);

	void line(float x1, float y1, float x2, float y2);

	float map(float v, float a, float b, float c, float d);

	float random(float a);
	float random(float a, float b);
};