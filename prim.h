#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#if _WIN32
#   include <Windows.h>
#endif
#if __APPLE__
#   include <OpenGL/gl.h>
#   include <OpenGL/glu.h>
#   include <GLUT/glut.h>
#else
#   include <GL/gl.h>
#   include <GL/glu.h>
#   include <GL/glut.h>
#endif

#ifndef prim_h

typedef enum { false, true } bool;

#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846

#define SIN(A, y, x) A * sin(((2 * M_PI) / y) * x);
#define COSDY(A, y, x) A * ((2 * M_PI) / y) * cos(((2 * M_PI) / y) * x);

void drawLine();
void xyz();
void drawSinWave(bool drawT, bool drawN);
void drawTagent(float x, float a, float k);
void drawNormal(float x, float a, float k);
void drawIsland();


bool SHOW_T = true;
bool SHOW_N = true;


const float g = -9.8;
const int milli = 1000;

typedef enum { analytical, numerical } integrationMode;

typedef struct {
    bool debug;
    bool go;
    float startTime;
    integrationMode integrateMode;
    bool OSD;
    int frames;
    float frameRate;
    float frameRateInterval;
    float lastFrameRateT;
} global_t;


global_t global = { true, false, 0.0, numerical, true, 0, 0.0, 0.2, 0.0 };

#endif