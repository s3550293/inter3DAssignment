#ifndef _boat_h_
#define _boat_h_

#include "util.h"
void drawBoatPart(float x, float y, float m, float r, float g, float b, float canAngle);
void drawCB();
void updateCannonBall(float dt, float g);
void createCannonBall(bool boat);
void removeCB();

typedef struct { 
    float x,y,cl,m,health; 
} boatObj ;

typedef struct { 
    float x,y,vx,vy,m,v;
    bool boat; 
} cannonBall;


#define MAX 10

#endif