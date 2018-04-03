#include "sin.h"

sinWave water = {
    0, 0, 0.5, (2 * M_PI / 0.5), 0.15, 0, 50 
};

void updateWave(float dt, bool drawMotion){
    if(drawMotion == true){
        water.v += dt;
    }
}

void drawSinWave(bool drawT, bool drawN, float seg){
    water.segments = seg;
    float left = -1.0;
    float right = 1.0;
    float range = right - left;
    float stepsize = range/water.segments;
    glColor3f(1,1,1);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= water.segments; i++){
        water.x = i * stepsize + left;
        water.y = water.a * sin((water.k * water.x) + water.v);
        glVertex3f(water.x,water.y,0);
    }
    glEnd();

    if(drawT == true){
        glColor3f(1,0,1);
        for (int i = 0; i <=  water.segments; i++){
            water.x = i * stepsize + left;
            drawTagent(water.x,water.a,water.k);
        }
    }
    
    if(drawN == true){
        glColor3f(1,1,0);
        for (int i = 0; i <= water.segments; i++){
            water.x = i * stepsize + left;
            drawNormal(water.x,water.a,water.k);
        }
    }
    
}

void drawTagent(float x, float a, float k){
    float y;
    float dx = 1;
    float dy = a * k * cos((k*x) + water.v );
    float t = sqrtf(dx * dx + dy * dy);
    t /= 0.15;
    dx /= t;
    dy /= t;
    y = a * sin((k * x) + water.v);
    glBegin(GL_LINES);
    glVertex3f(x, y, 0);
    glVertex3f(x + dx, y + dy, 0);
    glEnd();
}

void drawNormal(float x, float a, float k){
    float y;
    float dx = 1;
    float dy = a * k * cos((k*x) + water.v);
    float t = sqrtf(dx * dx + dy * dy);
    t /= 0.15;
    dx /= t;
    dy /= t;
    y = a * sin((k * x) + water.v);
    glBegin(GL_LINES);
    glVertex3f(x, y, 0);
    glVertex3f(x - dy, y + dx, 0);
    glEnd();
}