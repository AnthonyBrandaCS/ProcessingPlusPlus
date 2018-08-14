#include "Display.h"

#include <iostream>

#include <GL/glew.h>

using namespace std;

Display::Display(int _width, int _height, const string& _title)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width = _width, height = _height, SDL_WINDOW_OPENGL);
	glContext = SDL_GL_CreateContext(window);

	GLenum status = glewInit();

	if (status != GLEW_OK) {
		cerr << "Glew failed to initialize." << endl;
	}

	isClosed = false;
}

void Display::Update()
{
	SDL_GL_SwapWindow(window);

	SDL_Event e;

	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT)
			isClosed = true;
	}
}
bool Display::IsClosed()
{
	return isClosed;
}

Display::~Display()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);

	SDL_Quit();
}



void Display::background(float b) {
	glClearColor(b / 255.0f, b / 255.0f, b / 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Display::background(float r, float g, float b) {
	glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Display::background(float r, float g, float b, float a) {
	glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a);
	glClear(GL_COLOR_BUFFER_BIT);
}