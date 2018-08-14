#pragma once

#include "Display.h"

class Processing : public Display
{
private:
	float translateX = 0;
	float translateY = 0;

public:
	Processing() { Processing(10, 10, "Title"); };
	Processing(int _width, int _height, const std::string& _title);

	void background(float b);
	void background(float r, float g, float b);
	void background(float r, float g, float b, float a);

	void line(float x1, float y1, float x2, float y2);
};

