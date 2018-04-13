#ifndef _sin_h_
#define _sin_h_

#include "util.h"

void updateWave(float dt, bool drawMotion, float speed);
void drawSinWave(bool drawT, bool drawN, float seg);
void drawTagent(float x, float a, float k);
void drawNormal(float x, float a, float k);
float placeBoat(float x, float a, float k);
float floatObjectM(float x);

#endif