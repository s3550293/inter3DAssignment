#ifndef _boat_h_
#define _boat_h_

#include "util.h"
void drawBoat(float x, float y, float xt, float yt);

typedef struct { 
    float x, y, xt, yt, v, r, g, b; 
} boatObj ;

#endif