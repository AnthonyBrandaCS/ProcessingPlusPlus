#include "Display.hpp"

Display::Display()
{
	
}

Display::Display(int _width, int _height, const char* _title)
{
	if(!glfwInit())
	{
		std::cout << "Failed to glfwInit()";
		exit(-1);
	}
	glfwWindowHint (GLFW_RESIZABLE, GL_FALSE);
	window = glfwCreateWindow(_width, _height, _title, NULL, NULL);
	if(!window)
	{
		std::cout << "Failed to glfwCreateWindow()";
		glfwTerminate();
		exit(-2);
	}

	glfwMakeContextCurrent(window);

	closed = false;
}

void Display::Update()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}
bool Display::IsClosed()
{
	return closed;
}

void Display::close()
{
	closed = true;
}

void Display::keyboard(GLFWkeyfun cbfun)
{
	glfwSetKeyCallback(window, cbfun);
}

GLFWwindow* Display::getWindow()
{
	return window;
}

Display::~Display()
{
	glfwTerminate();
}