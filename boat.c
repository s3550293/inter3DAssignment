#include "boat.h"

void drawBoatPart(float x, float y, float m, float r, float g, float b, float canAngle){
    // y -= 0.012;
    glPushMatrix();
        printf("\nM:%f\n",m);
        glTranslated(x, y-.017, 0.0);
        glRotatef(m, 0.0, 0.0, 1.0);
        glColor4f(r ,g ,b, 1);
        // Hull
        glScalef(.7,.7,0);
        glBegin(GL_QUADS);
            glVertex3f(-0.05, 0, 0);
            glVertex3f(-0.1, 0.05,0);
            glVertex3f(0.1, 0.05,0);
            glVertex3f(0.05, 0,0);
        glEnd();
        // Deck
        glBegin(GL_QUADS);
            glVertex3f(-0.03, 0.05,0);
            glVertex3f(- 0.03, 0.1,0);
            glVertex3f(0.03, 0.1,0);
            glVertex3f(0.03,  0.05,0);
        glEnd();
        
        glPushMatrix();
            // Cannon
            glRotatef(canAngle, 0.0, 0.0, 1.0);
            glBegin(GL_QUADS);
                glVertex3f(-0.01, 0.05,0);
                glVertex3f(-0.01, 0.11,0);
                glVertex3f(0.01, 0.11,0);
                glVertex3f(0.01,  0.05,0);
            glEnd();
        glPopMatrix();
        
    glPopMatrix();
    
}