#ifndef _prim_h_
#define _prim_h_

#include "util.h"
#include "sin.h"

// #define SIN(A, y, x) A * sin(((2 * M_PI) / y) * x);
// #define COSDY(A, y, x) A * ((2 * M_PI) / y) * cos(((2 * M_PI) / y) * x);

void drawLine();
void xyz(void);
void drawIsland();
void displayHUD();

void idle();

bool SHOW_T = true;
bool SHOW_N = true;
bool WAVEMOTION = true;
float WATERSEG = 64;

const float g = -9.8;
const int milli = 1000;

typedef struct {
    bool debug;
    bool go;
    float startTime;
    bool OSD;
    int frames;
    float frameRate;
    float frameRateInterval;
    float lastFrameRateT;
} global_t;

float deltaT = 0;

global_t global = { true, true, 0.0, true, 0, 0.0, 0.2, 0.0 };

#endif