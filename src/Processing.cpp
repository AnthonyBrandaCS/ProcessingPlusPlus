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
        p = new ProcessingManager(_width, _height, "");
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

float Processing::map(float v, float a, float b, float c, float d)
{
    return p->map(v, a, b, c, d);
}

float Processing::random(float a)
{
    return p->random(a);
}

float Processing::random(float a, float b)
{
    return p->random(a, b);
}

void Processing::exit()
{
    p->close();
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