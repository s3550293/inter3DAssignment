#include "prim.h"

bool SHOW_T = false;
bool SHOW_N = false;
bool WAVEMOTION = true;
float WATERSEG = 64;

float redBoatX = -0.5;
float blueBoatX = 0.5;

float redCannonAng = 315;
float blueCannonAng = 45;

float islandCannonAng = 90;

float rBHealth = 0.50;
float bBHealth = 0.50;
float iHealth = 0.50;

const float g = -1.5;
const int milli = 1000;

typedef struct {
    bool debug;
    bool wire;
    bool go;
    float startTime;
    bool OSD;
    int frames;
    float frameRate;
    float frameRateInterval;
    float lastFrameRateT;
} global_t;

float deltaT = 0;

global_t global = { false, false, true, 0.0, true, 0, 0.0, 0.2, 0.0 };

float rT = 0;
float bT = 0;
float iT = 0;
float t = 0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    if (global.OSD)
        displayHUD();
    drawCB();
    drawProab();
    drawBoatPart(redBoatX,floatObjectY(redBoatX),floatObjectM(redBoatX), 1,0,0,redCannonAng);
    drawBoatPart(blueBoatX,floatObjectY(blueBoatX),floatObjectM(blueBoatX), 0,0,1,blueCannonAng);
    drawIsland(islandCannonAng);
    glDisable(GL_DEPTH_TEST);
    drawSinWave(SHOW_T,SHOW_N,WATERSEG);
    displayHealth();
    if(rBHealth <=0 || bBHealth <=0 || iHealth <=0){
        gameOverScreen();
    }
    glEnable(GL_DEPTH_TEST);
    xyz();
    global.frames++;
    if(global.debug){
        printf("\ndisplay\n");
        printf("%s\n",gluErrorString(glGetError()));
    }


    glutSwapBuffers();
}

/*
    Displays the health of the Boats and Islands
*/
void displayHealth(){
    glPushMatrix();
        glTranslatef(-0.9,0.9,0);
        glBegin(GL_QUADS);
        glColor3f(1,0,0);
        glVertex3f(0,-.02,0);
        glVertex3f(0,.02,0);
        glVertex3f(rBHealth,.02,0);
        glVertex3f(rBHealth,-.02,0);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.9,0.86,0);
        glBegin(GL_QUADS);
        glColor3f(0,0,1);
        glVertex3f(0,-.02,0);
        glVertex3f(0,.02,0);
        glVertex3f(bBHealth,.02,0);
        glVertex3f(bBHealth,-.02,0);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.9,0.82,0);
        glBegin(GL_QUADS);
        glColor3f(1,1,0);
        glVertex3f(0,-.02,0);
        glVertex3f(0,.02,0);
        glVertex3f(iHealth,.02,0);
        glVertex3f(iHealth,-.02,0);
        glEnd();
    glPopMatrix();
}

/*
    Displays the XYZ axis
*/
void xyz(void){

    glBegin(GL_LINES);
    /* glColor3f(red,green,blue);*/
    glColor3f(0,1,0);
    /* glVertex3f(x,y,z);*/
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    glEnd();
}

/*
    Displays the game over message
*/
void gameOverScreen(){
    char buffer[30];
    char *bufp;
    int w, h;
    
    glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    
    w = glutGet(GLUT_WINDOW_WIDTH);
    h = glutGet(GLUT_WINDOW_HEIGHT);
    glOrtho(0.0, w, 0.0, h, -1.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(w/3, h/1.2);
    if(iHealth <= 0){
        snprintf(buffer, sizeof buffer, "Game Over, %s Win!", "Boats");
    }else{
        snprintf(buffer, sizeof buffer, "Game Over, %s Wins!", "Island");
    }
    for (bufp = buffer; *bufp; bufp++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *bufp);
    
    glPopMatrix();  
    glMatrixMode(GL_PROJECTION);
    
    glPopMatrix();  
    glMatrixMode(GL_MODELVIEW);
    
    glPopAttrib();
}

/*
    Keybaord Input proccessing
*/
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
    // case 'Q':
        exit(EXIT_SUCCESS);
        break;
    case 'N':
        if(SHOW_N == true){
            SHOW_N = false;
        }else{
            SHOW_N = true;
        }
        break;
    case 'T':
        if(SHOW_T == true){
            SHOW_T = false;
        }else{
            SHOW_T = true;
        }
        break;
    case 'G':
        if(global.go){
            WAVEMOTION = false;
            global.go = false;
        }else{
            WAVEMOTION = true;
            global.go = true;
        }
        break;
    case 'O':
        if(global.OSD){
            global.OSD = false;
        }else{
            global.OSD = true;
        }
        break;
    case 'W':
        if(global.wire){
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            global.wire = false;
        }else{
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            global.wire = true;
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
        if(WAVEMOTION){
            WAVEMOTION = false;
        }else{
            WAVEMOTION = true;
        }
        break;

    case 'a':
        if(redBoatX > -1){
            redBoatX -= 0.005;
        }
        break;
    case 'd':
        if(redBoatX < -0.35){
            redBoatX+= 0.005;
        }
        break;
    case 'w':
        if(redCannonAng < 340){
            redCannonAng += 1;
        }
        break;
    case 's':
        if(redCannonAng > 305){
            redCannonAng -= 1;
        }
        break;
    case 'e':
        if(t > (rT+1.5) && rBHealth > 0){
            createCannonBall(boatx(true),boaty(true),boatm(true),boatcl(true));
            rT = t;
        }
        break;


    case 'j':
        if(blueBoatX > 0.35){
            blueBoatX -= 0.005;
        }
        break;
    case 'l':
        if(blueBoatX < 1){
            blueBoatX += 0.005;
        }
        break;
    case 'i':
        if(blueCannonAng > 20){
            blueCannonAng -= 1;
        }
        break;
    case 'k':
        if(blueCannonAng < 55){
            blueCannonAng += 1;
        }
        break;
    case 'o':
        if(t > (bT + 1.5) && bBHealth > 0){
            createCannonBall(boatx(false),boaty(false),boatm(false),boatcl(false));
            bT = t;
        }
        break;
    case 'f':
        if(islandCannonAng < 160){
            islandCannonAng += 1;
        }
        break;
    case 'h':
        if(islandCannonAng > 20){
            islandCannonAng -= 1;
        }
        break;
    case 32:
        if(t > (iT+1.5) && iHealth > 0){
            createCannonBall(0,0.25,canAng(),0.22);
            iT = t;
        }
        break;
    default:
        break;
    }
}

/*
    Function to update time Delta Time and objects positions
*/
void idle(void){
    static float lastT = -1.0;
    float dt;
    
    t = glutGet(GLUT_ELAPSED_TIME) / (float)milli - global.startTime;
    
    if (lastT < 0.0) {
        lastT = t;
        return;
    }
    
    dt = t - lastT;
    if (global.debug)
        printf("%f %f\n", t, dt);
    if (global.go){
        updateWave(dt,WAVEMOTION, 0.7);
        updateCannonBall(dt);
        removeCB();
        if(checkCollisionBoat(boatx(true),boaty(true),0.09)){
            rBHealth -= 0.05;
            if(rBHealth <= 0){
                global.go = false;
            }
        }
        if(checkCollisionBoat(boatx(false),boaty(false),0.09)){
            bBHealth -= 0.05;
            if(bBHealth <= 0){
                global.go = false;
            }
        }
        if(checkCollisionBoat(0,0,0.25)){
            iHealth -= 0.01;
            if(iHealth <= 0){
                global.go = false;
            }
        }
    }
    // updateBoat(WAVEMOTION);
    lastT = t;
    
    /* Frame rate */
    dt = t - global.lastFrameRateT;
    if (dt > global.frameRateInterval) {
        global.frameRate = global.frames / dt;
        global.lastFrameRateT = t;
        global.frames = 0;
    }
    deltaT = dt;
    if (global.debug)
        printf("DT: %f",deltaT);
    glutPostRedisplay();
}


/*
    Displays the FPS, the length at which a frame is displayed
    and the number of vertices in the sin wave
*/
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
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    // glDisable(GL_TEXTURE_2D);
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