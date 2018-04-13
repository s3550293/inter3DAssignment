#ifndef _projectile_h_
#define _projectile_h_

#include "util.h"

void updateCannonBall(float dt, float g);
void removeCB();
void drawCB();
void drawProab();
void createCannonBall(float ObjX, float objY, float objM, float objCL)

typedef struct { 
    vec2f p,v;
    float m,a;
} cannonBall;

#endif