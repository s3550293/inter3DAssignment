#include "prim.h"


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    xyz();
    drawSinWave(SHOW_T,SHOW_N,WATERSEG);
    // drawBoat(0,0);
    if (global.OSD)
        displayHUD();
    global.frames++;
    printf("\ndisplay\n");
    printf("%s\n",gluErrorString(glGetError()));


    glutSwapBuffers();
}

void xyz(void){
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
    case '+':
    case '=':
        WATERSEG *= 2;
        break;
    case '-':
        if(WATERSEG != 4){
            WATERSEG /= 2;
        }
        break;
    case '`':
        if(WAVEMOTION == true){
            WAVEMOTION = false;
        }else{
            WAVEMOTION = true;
        }
        break;
    default:
        break;
    }
}

void idle(void){
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
    updateWave(dt,WAVEMOTION);
    lastT = t;
    
    /* Frame rate */
    dt = t - global.lastFrameRateT;
    if (dt > global.frameRateInterval) {
        global.frameRate = global.frames / dt;
        global.lastFrameRateT = t;
        global.frames = 0;
    }
    deltaT = dt;
    printf("DT: %f",deltaT);
    glutPostRedisplay();
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
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(w - 150, h - 15);
    snprintf(buffer, sizeof buffer, "fr (f/s): %6.0f", global.frameRate);
    for (bufp = buffer; *bufp; bufp++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *bufp);
    
    /* Time per frame */
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(w - 150, h - 30);
    snprintf(buffer, sizeof buffer, "ft (ms/f): %5.0f", 1.0 / global.frameRate * 1000.0);
    for (bufp = buffer; *bufp; bufp++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *bufp);
    
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(w - 150, h - 45);
    snprintf(buffer, sizeof buffer, "tess: %5.0f", WATERSEG);
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
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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