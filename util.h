#ifndef _util_h_
#define _util_h_

#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846

#define degreesToRadians(angleDegrees) ((angleDegrees) * M_PI / 180.0)
#define radiansToDegrees(angleRadians) ((angleRadians) * 180.0 / M_PI)

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

#define MAX 100
typedef enum { false, true } bool;


#endif