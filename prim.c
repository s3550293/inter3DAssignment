#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "prim.h"

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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    xyz();
    // drawLine();
    drawSinWave();
    

    printf("display\n");
    printf("%s\n",gluErrorString(glGetError()));


    glutSwapBuffers();
}

void drawLine(){
    // float segments = 10;
    // float left = -1.0;
    // float right = 1.0;
    // float range = right - left;
    // float stepsize = range/segments;
    // printf("%f\n",stepsize);
    // float x,y;
    // glBegin(GL_LINE_STRIP);
    // for (int i = 0; i <= segments; i++){
    //     x = i * stepsize + left;
    //     y = (2 * pow(x,2)) - 1;
    //     printf("%f,%f\n",x,y);
    //     glVertex3f(x,y,0);
    // }
    // glEnd();
    float x,y;
    glBegin(GL_LINE_STRIP);
    for (x = -1.f; x <= 1.f; x += 0.01){
        y = SIN(1,2,x);
        glVertex3f(x,y,0);
    }
    glEnd();
}

void drawSinWave(){
    // float x,y;
    // float waveLength = 2;
    // float k = 2 * M_PI / waveLength;
    // float a = 1;
    // float left = -1.0;
    // float right = 1.0;
    // int segments = 20;
    // float range = right - left;
    // float stepsize = range/segments;
    // float curveX[segments];
    // float curveY[segments];
    
    // glBegin(GL_LINE_STRIP);
    // for (int i = 0; i <= segments; i++){
    //     x = i * stepsize + left;
    //     y = a * sin(k * x);
    //     curveX[i] = x;
    //     curveY[i] = y;
    //     glVertex3f(x,y,0);
    // }
    // glEnd();

    float x,y;
    glBegin(GL_LINE_STRIP);
    for (x = -1.f; x <= 1.f; x += 0.01){
        y = SIN(1,2,x);
        glVertex3f(x,y,0);
    }
    glEnd();

    // glBegin(GL_LINE_STRIP);
    // for (int i = 0; i <= segments; i++){
    //     glVertex3f(curveX[i],curveY[i],0);
    // }
    // glEnd();
    
    glColor3f(1,1,1);
    for (x = -1.f; x <= 1.f; x += 0.01){
        drawTagent(x);
    }

    glColor3f(1,.5,1);
    for (x = -1.f; x <= 1.f; x += 0.01){
        drawNormal(x);
    }
    
    // for (int i = 0; i <= segments; i++){
    //     drawVector(curveX[i],curveY[i],a,k);
    // }
    
    
}

void drawTagent(float x){
    float y;
    float dx = 1;
    float dy = COSDY(1,2,x);
    float t = sqrtf(dx * dx + dy * dy);
    dx /= t;
    dy /= t;
    glBegin(GL_LINES);
    y = SIN(1,2,x);
    glVertex3f(x, y, 0);
    glVertex3f(x + dx, y + dy, 0);
    glEnd();
}

void drawNormal(float x){
    float y;
    float dx = 1;
    float dy = COSDY(1,2,x);
    float t = sqrtf(dx * dx + dy * dy);
    x /= t;
    y /= t;
    glBegin(GL_LINES);
    y = SIN(1,2,x);
    glVertex3f(x, y, 0);
    glVertex3f(x + dy, y - dx, 0);
    glEnd();
}

void xyz(){
    glBegin(GL_LINES);
    /* glColor3f(red,green,blue);*/
    glColor3f(1,0,0);
    /* glVertex3f(x,y,z);*/
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    glEnd();
}

void drawIsland(){
    //TODO
}

/* You can ignore this for now, it just lets you exit when you press 'q' or ESC */
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
    case 'q':
        exit(EXIT_SUCCESS);
        break;
    default:
        break;
    }
}

void init()
{
    /* In this program these OpenGL calls only need to be done once,
      but normally they would go elsewhere, e.g. display */

    glMatrixMode(GL_PROJECTION);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Assignment 1 Island Battle!");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return EXIT_SUCCESS;
}