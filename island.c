#include "island.h"

void drawIsland(){
    glColor4f(1 ,1 ,0, 1);
    glBegin(GL_QUADS);
        glVertex3f(-0.25, 0.25, 0);
        glVertex3f(0.25, 0.25, 0);
        glVertex3f(0.25, -1, 0);
        glVertex3f(-0.25, -1, 0);
    glEnd();
}