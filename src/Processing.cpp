#include "Processing.hpp"

Processing::Processing()
{

}

ProcessingManager* Processing::instance()
{
    return p;
}

Processing::~Processing()
{
    delete p;
}

void Processing::size(int _width, int _height)
{
    if(p == nullptr)
    {
        p = new ProcessingManager(_width, _height, "Clock");
    }
}

void Processing::background(int b, int a)
{
    p->background(b, a);
}

void Processing::background(int r, int g, int b, int a)
{
    p->background(r, g, b, a);
}

void Processing::stroke(int b, int a)
{
    p->stroke(b, a);
}

void Processing::stroke(int r, int g, int b, int a)
{
    p->stroke(r, g, b, a);
}

void Processing::strokeWeight(int w)
{
    p->strokeWeight(w);
}

void Processing::point(float x, float y)
{
    p->point(x, y);
}

void Processing::line(float x1, float y1, float x2, float y2)
{
    p->line(x1, y1, x2, y2);
}

int Processing::second()
{
    return p->sec();
}

int Processing::minute()
{
    return p->min();
}

int Processing::hour()
{
    return p->hour();
}

int Processing::day()
{
    return p->day();
}

int Processing::month()
{
    return p->month();
}

int Processing::year()
{
    return p->year();
}


float Processing::map(float v, float a, float b, float c, float d)
{
    return p->map(v, a, b, c, d);
}

float Processing::norm(float v, float a, float b)
{
    return p->map(v, a, b, 0, 1);
}

float Processing::min(float a, float b)
{
    return p->min(a, b);
}

float Processing::max(float a, float b)
{
    return p->max(a, b);
}

float Processing::random(float a)
{
    return p->random(a);
}

float Processing::random(float a, float b)
{
    return p->random(a, b);
}

float Processing::radians(float a)
{
    return p->radians(a);
}

float Processing::sin(float a)
{
	return p->_sin(a);
}

float Processing::cos(float a)
{
	return p->_cos(a);
}

float Processing::tan(float a)
{
	return p->_tan(a);
}
	
float Processing::asin(float a)
{
	return p->_asin(a);
}

float Processing::acos(float a)
{
	return p->_acos(a);
}

float Processing::atan(float a)
{
	return p->_atan(a);
}

void Processing::exit()
{
    return p->close();
}

void Processing::setup(void (*f)(Processing*))
{
    (*f)(this);

    if(p == nullptr)
    {
        size(150, 150);
    }
}

void Processing::draw(void (*f)(Processing*))
{
    (*f)(this);

    p->Update();
}

void Processing::end(void (*f)(Processing*))
{
    (*f)(this);

    delete this;
}

void Processing::keyPressed(void(*f)(Processing*), int _key)
{
    key = _key;
    if(key == GLFW_KEY_ESCAPE)
    {
        exit();
    }
    
    (*f)(this);
}

void Processing::keyReleased(void(*f)(Processing*), int _key)
{
    key = _key;
    
    (*f)(this);
}