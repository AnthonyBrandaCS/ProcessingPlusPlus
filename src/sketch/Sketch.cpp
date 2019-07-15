#include "Sketch.hpp"

Drop* drops = new Drop[500];

void setup(Processing* p) {
  p->size(640, 360);

  for(int i = 0; i < 500; i++)
  {
      drops[i].init(p);
  }
}

void draw(Processing* p) {
  p->background(230, 230, 250);
  for (int i = 0; i < 500; i += 2)
  {
    drops[i].fall();
    drops[i].show();

    drops[i+1].fall();
    drops[i+1].show();
  }
}

void end(Processing* p)
{
  std::cout << "Deleting the drops\n";
    delete[] drops;
}