#include "boat.h"

boatObj red = {
    0,0,0,0,10
};

boatObj blue = {
    0,0,0,0,10
};

cannonBall arr_balls[MAX] = {0,0,0,0,0,0,0,0,false};

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

void updateCannonBall(float dt, float g, float t){
    dt *= 0.5;
    for( int i = 0; i< MAX; i++){
        if(!(arr_balls[i].v == 0)){
            arr_balls[i].x += arr_balls[i].vx * dt;
            arr_balls[i].y += arr_balls[i].vy * dt;
            arr_balls[i].vy += g * dt;
            arr_balls[i].g = g;
            arr_balls[i].t = t;
        }
    }
}

void removeCB(){
    for( int i = 0; i< MAX; i++){
        if(!(arr_balls[i].v == 0)){
            if(arr_balls[i].x < -1 || arr_balls[i].x > 1 || arr_balls[i].y < -1){
                printf("Remove Cannonball\n");
                arr_balls[i].v = 0;
            }
        }
    }
}

void drawCB(){
    int count = 0;
    for( int i = 0; i< MAX; i++){
        if(!(arr_balls[i].v == 0)){
                glPushMatrix();
                    // printf("Cannon Angle %f\n",arr_balls[i].m);
                    glColor3f(1,1,1);
                    GLUquadric *quad;
                    quad = gluNewQuadric();
                    glTranslatef(arr_balls[i].x,arr_balls[i].y,0);
                    glutWireSphere(0.01,30,30);
                    glEnd();
                glPopMatrix();
            count++;
        }
    }
}

void drawProab(){
    for( int i = 0; i< MAX; i++){
        if(!(arr_balls[i].v == 0)){
            float y = 0;
            float x = 0;
            float t = 0;
            float seg = 100;
            glColor3f(1,1,1);
            glBegin(GL_LINE_STRIP);
            for(int k=0;k<=seg;k++){
                // x = arr_balls[i].vx * arr_balls[i].t + arr_balls[i].x;
                // y = -(1.0 / 2.0) * arr_balls[i].g * pow(arr_balls[i].t,2) + arr_balls[i].vy * arr_balls[i].t + arr_balls[i].y;
                x = arr_balls[i].vx * t + arr_balls[i].x;
                y = (1.0 / 2.0) * arr_balls[i].g * pow(t,2) + arr_balls[i].vy * t + arr_balls[i].y;
                t += glutGet(GLUT_ELAPSED_TIME) / (float)milli - 0.0;
                // x = arr_balls[i].x;
                // y = arr_balls[i].y;
                printf("Parab: %f,%f:\n",x,y);
                printf("Ball: %f,%f:\n",arr_balls[i].x,arr_balls[i].y);
                glVertex3f(x,y,0);
                if(y < 0){
                    break;
                }
            }
            glEnd();
        }
    }
}

void createCannonBall(bool boat){
    for( int i = 0; i< MAX; i++){
        if(arr_balls[i].v == 0){
            float x,y,vx,vy,m;
            if(boat){
                // x = red.x;
                // y = red.y;
                x = 0.11 * cos(degreesToRadians(red.m))+red.x;
                y = 0.11 * sin(degreesToRadians(red.m))+red.y-.017;
                vx = 1.5 * cos(degreesToRadians(red.m));
                vy = 1.5 * sin(degreesToRadians(red.m));
                m = red.m;
            }
            else{
                x = 0.11 * cos(degreesToRadians(blue.m))+blue.x;
                y = 0.11 * sin(degreesToRadians(blue.m))+blue.y-.017;
                vx = 1.5 * cos(degreesToRadians(blue.m));
                vy = 1.5 * sin(degreesToRadians(blue.m));
                m = blue.m;
                boat = false;
            }
            cannonBall b = {x,y,vx,vy,m,1,0,0,boat};
            arr_balls[i] = b;
            break;
        }
    }
}