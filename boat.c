#include "boat.h"

boatObj red = {
    0,0,0,0,10
};

boatObj blue = {
    0,0,0,0,10
};

void drawBoatPart(float x, float y, float m, float r, float g, float b, float canAngle){
    if(r == 1){
        red.x = x;
        red.y = y;
        red.cl = 0.11;
        red.m = (canAngle + 90) + m;
    }else{
        blue.x = x;
        blue.y = y;
        blue.cl = 0.11;
        blue.m = (canAngle + 90) + m;;
    }
    // y -= 0.012;
    glPushMatrix();
        // printf("\nM:%f\n",m);
        glTranslated(x, y-.017, 0.0);
        glRotatef(m, 0.0, 0.0, 1.0);
        glScalef(.7,.7,0);
        // Hull
        glColor4f(r ,g ,b, 1);
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
            glTranslatef(0.005,0.005,0);
            glRotatef(canAngle, 0.0, 0.0, 1.0);
            glColor4f(0.52 ,0.52 ,0.53, 1);
            glBegin(GL_QUADS);
                glVertex3f(-0.01, 0.00,0);
                glVertex3f(-0.01, 0.11,0);
                glVertex3f(0.01, 0.11,0);
                glVertex3f(0.01,  0.00,0);
            glEnd();
        glPopMatrix();
    glPopMatrix();
}

boatObj fireBall(bool boat){
    if(boat){
        return red;

    }else{
        return blue;
    }
}
