#ifndef prim_h

typedef enum { false, true } bool;

#define SIN(A, y, x) A * sin(((2 * M_PI) / y) * x);
#define COSDY(A, y, x) A * ((2 * M_PI) / y) * cos(((2 * M_PI) / y) * x);

void drawLine();
void xyz();
void drawSinWave();
void drawTagent(float x);
void drawNormal(float x);
void drawIsland();

// #define M_PI 3.14159265358979323846

#endif