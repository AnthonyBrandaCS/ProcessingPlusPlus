#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Processing.hpp"
#include "sketch/Sketch.hpp"

Processing* processing;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if(key == GLFW_KEY_ESCAPE)
    processing->exit();
}

int main(int argv, char** argc)
{
    processing = new Processing();
    
    processing->setup(setup);

    processing->instance()->keyboard(key_callback);

    while(!processing->instance()->IsClosed())
    {
        processing->draw(draw);
    }
    
    processing->end(end);
}























/*
#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Processing.hpp"
#include "sketch/Sketch.hpp"

Processing* processing;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if(key == GLFW_KEY_ESCAPE)
    processing->exit();
}

int main(int argv, char** argc)
{
    // Defines a new Manager
    // Manager Contains instance of Processing Object
    // Manager is a wrapper for Processing functions
    processing = new Processing();

    // Processing Manager runs the sketch setup function
    processing->setup(setup);

    processing->instance()->keyboard(key_callback);

    // Checks to see if window has closed
    while(!processing->instance()->IsClosed())
    {
        // Processing Manager runs the sketch draw function
        processing->draw(draw);
    }
    
    // Deletes this and ProcessingManager
    processing->end(end);
}*/