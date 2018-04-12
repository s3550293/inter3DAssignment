#ifndef _island_h_
#define _island_h_

#include "util.h"

typedef struct { 
    float health, canAng; 
} islandObj ;

typedef struct { 
    float x,y,vx,vy,m,v,t,g;
} cannonBall_I;

void drawIsland(float canAngle);
void drawIProab();
void createICB();
void drawICB();
void removeICB();
void updateICB(float dt, float g, float t);
#endif