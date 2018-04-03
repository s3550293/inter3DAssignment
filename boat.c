#include "boat.h"

boatObj boat = {
    0,0,0,0,0,.5,.5,.5
};

void drawBoat(float x, float y, float xt, float yt){
    boat.x = x;
    boat.y = y - 0.012;
    glColor3f(boat.r,boat.g,boat.b);
    glBegin(GL_POLYGON);
    glVertex3f(boat.x, boat.y, 0);
    glVertex3f((boat.x - 0.05), boat.y, 0);
    glVertex3f((boat.x - 0.1), (boat.y + 0.05),0);
    glVertex3f((boat.x - 0.025), (boat.y + 0.05),0);
    glVertex3f((boat.x - 0.025), (boat.y + 0.1),0);
    // glVertex3f(boat.xt,boat.yt,0);
    glVertex3f((boat.x + 0.025), (boat.y + 0.1),0);
    glVertex3f((boat.x + 0.025), (boat.y + 0.05),0);
    glVertex3f((boat.x + 0.1), (boat.y + 0.05),0);
    glVertex3f((boat.x + 0.05), boat.y,0);
    glEnd();
}

// void updateBoat(float dt, bool drawMotion){
//     if(drawMotion == true){
//         water.v += dt;
//     }
// }