#pragma once

#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Display
{
protected:
    GLFWwindow* window;
	bool closed;

	int width;
	int height;
	std::string title;

public:
	Display();
	Display(int _width, int _height, const char* _title);

	void Update();
	bool IsClosed();
	void close();
	void keyboard(GLFWkeyfun cbfun);

	GLFWwindow* getWindow();
	int getWidth();
	int getHeight();

	~Display();
};