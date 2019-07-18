#pragma once
#include "ProcessingManager.hpp"

#define width instance()->getWidth()
#define height instance()->getHeight()

class Processing
{
private:
	ProcessingManager* p;

	void checkP()
	{
		if (p == nullptr)
		{
			size(150, 150);
		}
	}

public:
	int key;

// Manager Functions
	Processing();
	ProcessingManager* instance();
	~Processing();
// Processing Functions
	void size(int _width, int _height);

	void background(int b, int a = 255);
	void background(int r, int g, int b, int a = 255);

	void stroke(int b, int a = 255);
	void stroke(int r, int g, int b, int a = 255);

	void strokeWeight(int w);

	void point(float x, float y);

	void line(float x1, float y1, float x2, float y2);

	int second();
	int minute();
	int hour();
	int day();
	int month();
	int year();

	float map(float v, float a, float b, float c, float d);

	float norm(float v, float a, float b);

	float min(float a, float b);

	float max(float a, float b);
	
	float random(float a);
	float random(float a, float b);

	float radians(float a);

	float sin(float a);
	float cos(float a);
	float tan(float a);
	
	float asin(float a);
	float acos(float a);
	float atan(float a);

	void exit();

// Sketch Functions
	void setup(void (*f)(Processing*));
	void draw(void (*f)(Processing*));
	void end(void (*f)(Processing*));
	void keyPressed(void(*f)(Processing*), int key);
	void keyReleased(void(*f)(Processing*), int key);
};