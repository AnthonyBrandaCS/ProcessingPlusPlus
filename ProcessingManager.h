#pragma once
#include "Processing.h"

class ProcessingManager
{
private:
	Processing *p;
	void checkP()
	{
		if (getP() == nullptr)
		{
			size(150, 150);
		}
	}

public:
	ProcessingManager() {  }

	Processing *getP() { return p; }

	void size(int _width, int _height)
	{
		if(getP() == nullptr)
			p = new Processing(_width, _height, "");
	}

	void background(float b)
	{
		checkP();
		p->background(b);
	}

	void background(float r, float g, float b)
	{
		checkP();
		p->background(r, g, b);
	}

	void background(float r, float g, float b, float a)
	{
		checkP();
		p->background(r, g, b, a);
	}


	void line(float x1, float y1, float x2, float y2)
	{
		checkP();
		p->line(x1, y1, x2, y2);
	}

	void setup();
	void draw();
};

