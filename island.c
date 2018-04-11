#include "island.h"

islandObj island = {
    100
};

void drawIsland(float canAngle){
    glPushMatrix();
        glTranslated(0, 0.25, 0.0);
        glRotatef(canAngle+270, 0.0, 0.0, 1.0);
        glColor4f(0.52 ,0.52 ,0.53, 1);
        glBegin(GL_QUADS);
            glVertex3f(-0.02, 0.0,0);
            glVertex3f(-0.02, 0.22,0);
            glVertex3f(0.02, 0.22,0);
            glVertex3f(0.02,  0.0,0);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslated(0, 0.23, 0.0);
        glScalef(.07,.07,0);
        glBegin(GL_QUAD_STRIP);
        for(int i =0; i <= 150; i++){
            double angle = 2 * M_PI * i / 300;
            double x = cos(angle);
            double y = sin(angle);
            glVertex2d(x,y);
            glVertex2d(0,0);
        }
        glEnd();
    glPopMatrix();
    glColor4f(1 ,1 ,0, 1);
    glBegin(GL_QUADS);
        glVertex3f(-0.25, 0.25, 0);
        glVertex3f(0.25, 0.25, 0);
        glVertex3f(0.25, -1, 0);
        glVertex3f(-0.25, -1, 0);
    glEnd();
}