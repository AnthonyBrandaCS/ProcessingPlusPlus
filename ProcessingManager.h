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

#pragma region size
	void size(int _width, int _height)
	{
		if(getP() == nullptr)
			p = new Processing(_width, _height, "");
	}
#pragma endregion

#pragma region background
	void background(int b)
	{
		checkP();
		p->background(b);
	}

	void background(int b, int a)
	{
		checkP();
		p->background(b, a);
	}

	void background(int r, int g, int b)
	{
		checkP();
		p->background(r, g, b);
	}

	void background(int r, int g, int b, int a)
	{
		checkP();
		p->background(r, g, b, a);
	}
#pragma endregion

#pragma region stroke 
	void stroke(int b)
	{
		checkP();
		p->stroke(b);
	}

	void stroke(int b, int a)
	{
		checkP();
		p->stroke(b, a);
	}

	void stroke(int r, int g, int b)
	{
		checkP();
		p->stroke(r, g, b);
	}

	void stroke(int r, int g, int b, int a)
	{
		checkP();
		p->stroke(r, g, b, a);
	}
#pragma endregion

#pragma region line
	void line(float x1, float y1, float x2, float y2)
	{
		checkP();
		p->line(x1, y1, x2, y2);
	}
#pragma endregion

	void setup();
	void draw();
};

