#include "util.h"
#ifndef _sin_h_
#define _sin_h_

typedef struct { 
    float x, y, wl, k, a, v; 
    int segments;
} sinWave ;

void updateWave(float dt, bool drawN);
void drawSinWave(bool drawT, bool drawN, float seg);
void drawTagent(float x, float a, float k);
void drawNormal(float x, float a, float k);

sinWave water = {
    0, 0, 0.5, (2 * M_PI / 0.5), 0.15, 0, 50 
};

#endif