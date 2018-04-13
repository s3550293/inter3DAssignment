#include "projectile.h"

cannonBall arr_balls[MAX] = {
    {0,0},{0,0},0,0
};

void updateCannonBall(float dt, float g){
    // dt *= 0.5;
    for( int i = 0; i< MAX; i++){
        if(!(arr_balls[i].a == 0)){
            arr_balls[i].x += arr_balls[i].vx * dt;
            arr_balls[i].y += arr_balls[i].vy * dt;
            arr_balls[i].vy += g * dt;
            arr_balls[i].g = g;
        }
    }
}

void removeCB(){
    for( int i = 0; i< MAX; i++){
        if(!(arr_balls[i].a == 0)){
            if(arr_balls[i].p.x < -1 || arr_balls[i].p.x > 1 || arr_balls[i].p.y < -1){
                printf("Remove Cannonball\n");
                arr_balls[i].a = 0;
            }
        }
    }
}

void drawCB(){
    int count = 0;
    for( int i = 0; i< MAX; i++){
        if(!(arr_balls[i].a == 0)){
                glPushMatrix();
                    // printf("Cannon Angle %f\n",arr_balls[i].m);
                    glColor3f(1,1,1);
                    GLUquadric *quad;
                    quad = gluNewQuadric();
                    glTranslatef(arr_balls[i].p.x,arr_balls[i].p.y,0);
                    glutWireSphere(0.01,30,30);
                    glEnd();
                glPopMatrix();
            count++;
        }
    }
}

void drawProab(){
    for( int i = 0; i< MAX; i++){
        if(!(arr_balls[i].a == 0)){
            float y = 0;
            float x = 0;
            float t = 0;
            float seg = 90;
            glColor3f(1,1,1);
            glBegin(GL_LINE_STRIP);
            for(int k=0;k<=seg;k++){
                x = arr_balls[i].v.x * t + arr_balls[i].p.x;
                y = (1.0 / 2.0) * G * pow(t,2) + arr_balls[i].v.y * t + arr_balls[i].p.y;
                t += 0.03;
                float b = floatObjectY(x);
                printf("Parab Y: %f,\n",b);
                printf("Parab: %f,%f\n",x,y);
                if(y < floatObjectY(x)){
                    break;
                }
                glVertex3f(x,y,0);
            }
            glEnd();
        }
    }
}

void createCannonBall(float ObjX, float objY, float objM, float objCL){
    for( int i = 0; i< MAX; i++){
        if(arr_balls[i].v == 0){
            float x,y,vx,vy,m;
            x = objCL * cos(degreesToRadians(objM))+ObjX;
            y = objCL * sin(degreesToRadians(objM))+objY;
            vx = 1.5 * cos(degreesToRadians(objM));
            vy = 1.5 * sin(degreesToRadians(objM));
            m = objM;
            cannonBall b = {{x,y},{vx,vy},m,1};
            arr_balls[i] = b;
            break;
        }
    }
}

