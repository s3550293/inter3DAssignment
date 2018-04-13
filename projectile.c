#include "projectile.h"

/*
    This allows for multiple cannon balls up to the MAX to exist at once
*/
cannonBall arr_balls[MAX] = {
    {0,0},{0,0},0,0
};

/*
    Updates the position of the cannon ball with dt
*/
void updateCannonBall(float dt){
    // dt *= 0.5;
    for( int i = 0; i< MAX; i++){
        if(!(arr_balls[i].a == 0)){
            arr_balls[i].p.x += arr_balls[i].v.x * dt;
            arr_balls[i].p.y += arr_balls[i].v.y * dt;
            arr_balls[i].v.y += G * dt;
        }
    }
}

/*
    This checks if the cannon ball leave the screen or hits the water
    and removes it if it does
*/
void removeCB(){
    for( int i = 0; i< MAX; i++){
        if(!(arr_balls[i].a == 0)){
            if(arr_balls[i].p.y < floatObjectY(arr_balls[i].p.x) || arr_balls[i].p.x < -1 || arr_balls[i].p.x > 1){
            // if(arr_balls[i].p.x < -1 || arr_balls[i].p.x > 1 || arr_balls[i].p.y < -1){
                printf("Remove Cannonball\n");
                arr_balls[i].a = 0;
            }
        }
    }
}

/*
    Draws all the active cannon balls in the array
*/
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

/*
    Draws the cannon ball trajectory, I had some issues with this one
    it is a little rought but it achives the goal.
*/
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
                if(y < floatObjectY(x)){
                    break;
                }
                if(y < 0.25 && x > -0.25 && x < 0.25){
                    break;
                }
                glVertex3f(x,y,0);
            }
            glEnd();
        }
    }
}

/*
    Creates a cannon ball and adds it to the array
*/
void createCannonBall(float ObjX, float objY, float objM, float objCL){
    for( int i = 0; i< MAX; i++){
        if(arr_balls[i].a == 0){
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

/*
    Checks if the cannon ball has collided with an object
    the collision boxes are round (so not boxes) this may make the island
    collision a tad weird
*/
bool checkCollisionBoat(float x1, float y1, float area){
    for( int i = 0; i< MAX; i++){
        if(!(arr_balls[i].a == 0)){
            float x = (x1 - arr_balls[i].p.x);
            x *= x;
            float y = (y1 - arr_balls[i].p.y);
            y *= y;

            float raid = area + 0.01;
            raid *= raid;

            float p = x + y;
            if(p<raid){
                printf("Collision\n");
                arr_balls[i].a = 0;
                return true;
            }
        }
    }
    return false;
}