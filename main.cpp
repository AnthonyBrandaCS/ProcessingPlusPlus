#include <iostream>

#include "ProcessingManager.h"

using namespace std;

int main(int argv, char** argc)
{
	ProcessingManager *processing = new ProcessingManager();

	processing->setup();
	if (processing->getP() == nullptr)
	{
		processing->size(150, 150);
	}

	while (!processing->getP()->IsClosed())
	{
		processing->draw();
		processing->getP()->Update();
	}

	return 0;
}