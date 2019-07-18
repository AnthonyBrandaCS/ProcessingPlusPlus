#include "Sketch.hpp"


int cx, cy;
float secondsRadius;
float minutesRadius;
float hoursRadius;
float clockDiameter;

void setup(Processing* p) {
  p->size(800, 480);
  p->stroke(255);
  
  int radius = p->min(p->width, p->height) / 2;
  secondsRadius = radius * 0.72;
  minutesRadius = radius * 0.60;
  hoursRadius = radius * 0.50;
  clockDiameter = radius * 1.8;
  
  cx = p->width / 2;
  cy = p->height / 2;
}

void draw(Processing* p) {
  p->background(0);
  
  int _s = p->second();
  int _m = p->minute();
  int _h = p->hour();

  float s = p->map(_s, 0, 60, 0, 2 * 3.14159) - (3.14159/2);
  float m = p->map(_m, 0, 60, 0, 2 * 3.14159) - (3.14159/2);
  float h = p->map(_h % 12, 0, 12, 0, 2 * 3.14159) - (3.14159/2);
  p->stroke(255);
  p->strokeWeight(1);
  p->line(cx, cy, cx + p->cos(s) * secondsRadius, cy + p->sin(s) * secondsRadius);
  p->strokeWeight(2);
  p->line(cx, cy, cx + p->cos(m) * minutesRadius, cy + p->sin(m) * minutesRadius);
  p->strokeWeight(4);
  p->line(cx, cy, cx + p->cos(h) * hoursRadius, cy + p->sin(h) * hoursRadius);
  
  // Draw the minute ticks
  p->strokeWeight(5);
  for (int a = 0; a < 360; a+=30) {
    float angle = p->radians(a);
    float x = cx + p->cos(angle) * secondsRadius;
    float y = cy + p->sin(angle) * secondsRadius;
    p->point(x, y);
  }
}