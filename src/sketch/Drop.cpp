#include "Drop.hpp"

Drop::Drop()
{

}

void Drop::init(Processing* _p)
{
    p = _p;

    x  = p->random(p->width); // random x position ie width because anywhere along the width of screen
    y  = p->random(-500, -50); // random y position, negative values because drop first begins off screen to give a realistic effect
    z  = p->random(0, 20); // z value is to give a perspective view , farther and nearer drops effect
    len = p->map(z, 0, 20, 10, 20); // if z is near then  drop is longer
    yspeed  = p->map(z, 0, 20, 1, 20); // if z is near drop is faster
}

void Drop::fall()
{
    y = y + yspeed; // increment y position to give the effect of falling 
    float grav = p->map(z, 0, 20, 0, 0.2); // if z is near then gravity on drop is more
    yspeed = yspeed + grav; // speed increases as gravity acts on the drop

    if (y > 600) { // repositions the drop after it has 'disappeared' from screen
      y = p->random(-200, -100);
      yspeed = p->map(z, 0, 20, 4, 10);
    }
}

void Drop::show()
{
    float thick = p->map(z, 0, 20, 1, 3); //if z is near , drop is more thicker 
    p->strokeWeight(thick); // weight of the drop
    p->stroke(138, 43, 226); // purple color
    p->line(x, y, x, y+len); // draws the line with two points 
}
