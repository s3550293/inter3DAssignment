#ifndef _boat_h_
#define _boat_h_

#include "util.h"
void drawBoatPart(float x, float y, float m, float r, float g, float b, float canAngle);
void drawCB();
void fireCannonBall(float x, float y, float m);

typedef struct { 
    float health; 
} boatObj ;

#endif