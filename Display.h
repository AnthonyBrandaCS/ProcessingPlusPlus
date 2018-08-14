#pragma once

#include <string>

#include <SDL2/SDL.h>

class Display
{
private:
	SDL_Window* window;
	SDL_GLContext glContext;
	bool isClosed;

	int width;
	int height;
	std::string title;

public:
	Display() {}
	Display(int _width, int _height, const std::string& _title);

	void Update();
	bool IsClosed();

	~Display();


	void background(float b);
	void background(float r, float g, float b);
	void background(float r, float g, float b, float a);
};

