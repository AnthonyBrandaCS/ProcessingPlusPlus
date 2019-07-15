#pragma once

#include "../Processing.hpp"

class Drop
{
public:
    Processing* p;

    float x;
    float y;
    float z;
    float len;
    float yspeed;

    Drop();
    void init(Processing* _p);
    void fall();
    void show();
};