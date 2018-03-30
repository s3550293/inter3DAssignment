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
    drawLine(0.5);
    

    printf("display\n");
    printf("%d\n",glGetError());
    printf("%s\n",gluErrorString(glGetError()));


    glutSwapBuffers();
}

void drawLine(float x){
    // const int n = 4;
    // const float r = 1.0;
    // float x, y;

    // glPointSize(2.0);
    // glBegin(GL_POINTS);
    // for (int i = 0; i <= n; i++) {
    //     x = (i / (float)n - 0.5) * 2.0 * r;
    //     y = sqrtf(r * r - x * x);
    //     glVertex3f(x, y);
    //     glVertex3f(x, -y);
    // }
    // glEnd();

    const int c = 10;
    const float m = 1;
    float y;
    // glPointSize(2.0);
    glBegin(GL_POINTS);
    for (int i = 0; i<= c; i++){
        y = (x * m + i)
        glVertex3f(x, y);
    }
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