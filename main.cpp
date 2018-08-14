#include <iostream>

#include "Display.h"

using namespace std;

int main(int argv, char** argc)
{
	Display display(300, 300, "Title");

	while (!display.IsClosed())
	{
		display.background(51);

		display.Update();
	}

	return 0;
}