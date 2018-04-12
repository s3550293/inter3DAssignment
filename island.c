#include "island.h"

islandObj island = {
    100, 0
};

cannonBall_I arr_I_balls[MAX] = {0,0,0,0,0,0,0,0,false};

void drawIsland(float canAngle){
    island.canAng = canAngle;
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

void updateICB(float dt, float g, float t){
    dt *= 0.5;
    for( int i = 0; i< MAX; i++){
        if(!(arr_I_balls[i].v == 0)){
            arr_I_balls[i].x += arr_I_balls[i].vx * dt;
            arr_I_balls[i].y += arr_I_balls[i].vy * dt;
            arr_I_balls[i].vy += g * dt;
            arr_I_balls[i].g = g;
            arr_I_balls[i].t = t;
        }
    }
}

void removeICB(){
    for( int i = 0; i< MAX; i++){
        if(!(arr_I_balls[i].v == 0)){
            if(arr_I_balls[i].x < -1 || arr_I_balls[i].x > 1 || arr_I_balls[i].y < -1){
                printf("Remove Cannonball\n");
                arr_I_balls[i].v = 0;
            }
        }
    }
}

void drawICB(){
    int count = 0;
    for( int i = 0; i< MAX; i++){
        if(!(arr_I_balls[i].v == 0)){
                glPushMatrix();
                    glColor3f(1,1,1);
                    GLUquadric *quad;
                    quad = gluNewQuadric();
                    glTranslatef(arr_I_balls[i].x,arr_I_balls[i].y,0);
                    glutWireSphere(0.01,30,30);
                    glEnd();
                glPopMatrix();
            count++;
        }
    }
}

void drawIProab(){
    for( int i = 0; i< MAX; i++){
        if(!(arr_I_balls[i].v == 0)){
            float y = 0;
            float x = 0;
            float seg = 64;
            glColor3f(1,1,1);
            glBegin(GL_LINE_STRIP);
            for(int i=0;i<=seg;i++){
                x = 1.0 * arr_I_balls[i].t + 0;
                y = 1.0 / 2.0 * arr_I_balls[i].g * arr_I_balls[i].t * arr_I_balls[i].t + 2.0 * arr_I_balls[i].t + 0;
                glVertex3f(x,y,0);
            }
            glEnd();
        }
    }
}

void createICB(){
    for( int i = 0; i< MAX; i++){
        if(arr_I_balls[i].v == 0){
            float x,y,vx,vy,m;
            x = 0.22 * cos(degreesToRadians(island.canAng));
            y = 0.22 * sin(degreesToRadians(island.canAng))+ 0.25;
            vx = 1 * cos(degreesToRadians(island.canAng));
            vy = 1 * sin(degreesToRadians(island.canAng));
            m = island.canAng;
            cannonBall_I b = {x,y,vx,vy,m,1,0,0};
            arr_I_balls[i] = b;
            break;
        }
    }
}