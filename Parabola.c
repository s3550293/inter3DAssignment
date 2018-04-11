#include "util.h"

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glBegin(GL_LINES);
    /* glColor3f(red,green,blue);*/
    glColor3f(0,1,0);
    /* glVertex3f(x,y,z);*/
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    glEnd();

    float x,y;
    float half = -0.5;
    float seg = 64;
    float left = -1.0;
    float right = 1.0;
    float range = right - left;
    float stepSize = range / seg;
    glColor3f(1,1,1);
    glBegin(GL_LINE_STRIP);
    for(int t=0;t<seg;t++){
        x =  t * stepSize + left;
        y = -2 * pow(x,2) + 2 * x + 1;
        glVertex3f(x,y,0);
    }
    glEnd();

    glutSwapBuffers();
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
    glutCreateWindow("Tutorial 1");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return EXIT_SUCCESS;
}