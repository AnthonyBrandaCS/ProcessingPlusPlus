#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Processing.hpp"
#include "sketch/Sketch.hpp"

Processing* processing;

void empty(Processing* a){}
void empty_key(Processing* a, int b){}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
    {
        if(keyPressed)
            processing->keyPressed(keyPressed, key);
        else
            processing->keyPressed(empty_key, key);
    }
    if(action == GLFW_RELEASE)
    {
        if(keyReleased)
            processing->keyReleased(keyReleased, key);
        else
            processing->keyReleased(empty_key, key);
    }
}

int main(int argv, char** argc)
{
    processing = new Processing();

    if(setup)
        processing->setup(setup);
    else
        processing->setup(empty);

    if(!processing->instance())
        exit(-1);

    processing->instance()->keyboard(key_callback);

    while(!processing->instance()->IsClosed())
    {
        if(draw)
            processing->draw(draw);
        else
            processing->draw(empty);
        
    }
    
    if(end)
        processing->end(end);
    else
        processing->end(empty);
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