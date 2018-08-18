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

public:
	Processing() { Processing(150, 150, ""); };
	Processing(int _width, int _height, const std::string& _title);

#pragma region background
	void background(int b);
	void background(int b, int a);
	void background(int r, int g, int b);
	void background(int r, int g, int b, int a);
#pragma endregion

#pragma region stroke
	void stroke(int b);
	void stroke(int b, int a);
	void stroke(int r, int g, int b);
	void stroke(int r, int g, int b, int a);
#pragma endregion

#pragma region line
	void line(float x1, float y1, float x2, float y2);
#pragma endregion
};