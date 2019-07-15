#include "Sketch.hpp"

Drop* drops = new Drop[500];

void setup(Processing* p) {
	p->size(640, 360);

	for(int i = 0; i < 500; i++)
	{
		drops[i].init(p);
	}
}

void draw(Processing* p) {
	p->background(230, 230, 250);
	for (int i = 0; i < 500; i++)
	{
		drops[i].fall();
		drops[i].show();
	}
}

void end(Processing* p)
{
	delete[] drops;
}