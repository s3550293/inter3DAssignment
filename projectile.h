#ifndef _projectile_h_
#define _projectile_h_

#include "util.h"
#include "sin.h"

void updateCannonBall(float dt);
void removeCB();
void drawCB();
void drawProab();
void createCannonBall(float ObjX, float objY, float objM, float objCL);
bool checkCollisionBoat(float x1, float y1, float area);


#endif