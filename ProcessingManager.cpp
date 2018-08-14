#include "ProcessingManager.h"

#include <iostream>

using namespace std;

void ProcessingManager::setup()
{
	size(300, 300);
}

float i = 150;
float j = 100;
int h = 250;
float b = 2;

void ProcessingManager::draw()
{
	background(0, 66, 99);
	
	if (i >= 280) b *= -1;
	else if (j <= 20) b *= -1;
	line(0, h, 20, h);
	line(280, h, 300, h);
	line(j += b, h, i += b, h);
}