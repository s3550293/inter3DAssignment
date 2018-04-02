#include "prim.h"


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    xyz();
    // drawLine();
    drawSinWave(SHOW_T,SHOW_N);
    

    printf("display\n");
    printf("%s\n",gluErrorString(glGetError()));


    glutSwapBuffers();
}

void drawSinWave(bool drawT, bool drawN){
    float x,y;
    float waveLength = .5;
    float k = 2 * M_PI / waveLength;
    float a = .15;
    float left = -1.0;
    float right = 1.0;
    int segments = 100;
    float range = right - left;
    float stepsize = range/segments;
    // float curveX[segments];
    // float curveY[segments];
    
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= segments; i++){
        x = i * stepsize + left;
        y = a * sin(k * x);
    //     y = a * sin(k * x);
    //     curveX[i] = x;
    //     curveY[i] = y;
    //     glVertex3f(x,y,0);
    // }
    // glEnd();

    // float x,y;
    // glBegin(GL_LINE_STRIP);
    // for (x = -1.f; x <= 1.f; x += 0.01){
        // y = SIN(1,2,x);
        glVertex3f(x,y,0);
    }
    glEnd();

    // glBegin(GL_LINE_STRIP);
    // for (int i = 0; i <= segments; i++){
    //     glVertex3f(curveX[i],curveY[i],0);
    // }
    // glEnd();
    
    if(drawT == true){
        glColor3f(1,0,1);
        for (int i = 0; i <= segments; i++){
        // for (x = -1.f; x <= 1.f; x += 0.01){
            x = i * stepsize + left;
            drawTagent(x,a,k);
        }
    }
    
    if(drawN == true){
        glColor3f(1,1,0);
        for (int i = 0; i <= segments; i++){
        // for (x = -1.f; x <= 1.f; x += 0.01){
            x = i * stepsize + left;
            drawNormal(x,a,k);
        }
    }
    
    // for (int i = 0; i <= segments; i++){
    //     drawVector(curveX[i],curveY[i],a,k);
    // }
    
    
}

void drawTagent(float x, float a, float k){
    float y;
    float dx = 1;
    // float dy = COSDY(1,2,x);
    float dy = a * k * cos(k*x);
    float t = sqrtf(dx * dx + dy * dy);
    t /= 0.15;
    dx /= t;
    dy /= t;
    y = a * sin(k * x);
    glBegin(GL_LINES);
    // y = SIN(1,2,x);
    glVertex3f(x, y, 0);
    glVertex3f(x + dx, y + dy, 0);
    glEnd();
}

void drawNormal(float x, float a, float k){
    float y;
    float dx = 1;
    float dy = a * k * cos(k*x);
    // float dy = COSDY(1,2,x);
    float t = sqrtf(dx * dx + dy * dy);
    t /= 0.15;
    dx /= t;
    dy /= t;
    y = a * sin(k * x);
    glBegin(GL_LINES);
    glVertex3f(x, y, 0);
    glVertex3f(x + dy, y - dx, 0);
    glEnd();
}

void xyz(){
    glBegin(GL_LINES);
    /* glColor3f(red,green,blue);*/
    glColor3f(1,0,0);
    /* glVertex3f(x,y,z);*/
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    glEnd();
}

void drawIsland(){
    //TODO
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
    case 'n':
        if(SHOW_N == true){
            SHOW_N = false;
        }else{
            SHOW_N = true;
        }
        break;
    case 't':
        if(SHOW_T == true){
            SHOW_T = false;
        }else{
            SHOW_T = true;
        }
        
        break;
    default:
        break;
    }
}

void idle(){
    
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
    glutIdleFunc(idle);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Assignment 1 Island Battle!");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return EXIT_SUCCESS;
}