#include "prim.h"


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    xyz();
    drawSinWave(SHOW_T,SHOW_N);
    displayHUD();

    printf("display\n");
    printf("%s\n",gluErrorString(glGetError()));


    glutSwapBuffers();
}

void updateWave(float dt){
    water.x = water.x * dt;
     water.y = water.y * dt;
}

void drawSinWave(bool drawT, bool drawN){
    // float x,y;
    // float waveLength = .5;
    // float k = 2 * M_PI / waveLength;
    // float a = .15;
    float left = -1.0;
    float right = 1.0;
    // int segments = 50;
    float range = right - left;
    // float stepsize = range/segments;
    float stepsize = range/water.segments;
    glColor3f(1,1,1);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= water.segments; i++){
        water.x = i * stepsize + left;
        water.y = water.a * sin(water.k * water.x);
        glVertex3f(water.x,water.y,0);
    }
    glEnd();

    if(drawT == true){
        glColor3f(1,0,1);
        for (int i = 0; i <=  water.segments; i++){
            water.x = i * stepsize + left;
            drawTagent(water.x,water.a,water.k);
        }
    }
    
    if(drawN == true){
        glColor3f(1,1,0);
        for (int i = 0; i <= water.segments; i++){
            water.x = i * stepsize + left;
            drawNormal(water.x,water.a,water.k);
        }
    }
    
}

void drawTagent(float x, float a, float k){
    float y;
    float dx = 1;
    float dy = a * k * cos(k*x);
    float t = sqrtf(dx * dx + dy * dy);
    t /= 0.15;
    dx /= t;
    dy /= t;
    y = a * sin(k * x);
    glBegin(GL_LINES);
    glVertex3f(x, y, 0);
    glVertex3f(x + dx, y + dy, 0);
    glEnd();
}

void drawNormal(float x, float a, float k){
    float y;
    float dx = 1;
    float dy = a * k * cos(k*x);
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
    static float lastT = -1.0;
    float t, dt;
    
    if (!global.go) 
        return;
    
    t = glutGet(GLUT_ELAPSED_TIME) / (float)milli - global.startTime;
    
    if (lastT < 0.0) {
        lastT = t;
        return;
    }
    
    dt = t - lastT;
    if (global.debug)
        printf("%f %f\n", t, dt);
    // updateProjectileState(t, dt);
    lastT = t;
    
    /* Frame rate */
    dt = t - global.lastFrameRateT;
    updateWave(dt);
    if (dt > global.frameRateInterval) {
        global.frameRate = global.frames / dt;
        global.lastFrameRateT = t;
        global.frames = 0;
    }
    deltaT = dt;
    glutPostRedisplay();
    printf("DT: %f",deltaT);
}

void displayHUD(){
    char buffer[30];
    char *bufp;
    int w, h;
    
    glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    
    /* Set up orthographic coordinate system to match the 
       window, i.e. (0,0)-(w,h) */
    w = glutGet(GLUT_WINDOW_WIDTH);
    h = glutGet(GLUT_WINDOW_HEIGHT);
    glOrtho(0.0, w, 0.0, h, -1.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    /* Frame rate */
    glColor3f(1.0, 1.0, 0.0);
    glRasterPos2i(10, 60);
    snprintf(buffer, sizeof buffer, "fr (f/s): %6.0f", global.frameRate);
    for (bufp = buffer; *bufp; bufp++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *bufp);
    
    /* Time per frame */
    glColor3f(1.0, 1.0, 0.0);
    glRasterPos2i(10, 40);
    snprintf(buffer, sizeof buffer, "ft (ms/f): %5.0f", 1.0 / global.frameRate * 1000.0);
    for (bufp = buffer; *bufp; bufp++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *bufp);
    
    /* Pop modelview */
    glPopMatrix();  
    glMatrixMode(GL_PROJECTION);
    
    /* Pop projection */
    glPopMatrix();  
    glMatrixMode(GL_MODELVIEW);
    
    /* Pop attributes */
    glPopAttrib();
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
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Assignment 1 Island Battle!");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutMainLoop();

    return EXIT_SUCCESS;
}