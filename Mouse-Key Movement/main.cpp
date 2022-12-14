#include<windows.h>
#include<math.h>
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define PI 3.1416
#include <stdlib.h>

float cx=1;
float ca=1;
float cPosition = -1;
float cl1 = 0.5, cl2=0.51, cl3=0.52;
float c1=1, c2=1, c3=1;
void init()
{
    glClearColor(0,0,0,0);
    glOrtho(-5,5,-5,5,-5,5);
}
void circle(float radiusX, float radiusY)
{
    int i;
    float angle = 0.0;
    glBegin(GL_POLYGON);
        for(i=0;i<100;i++){
            angle = 2*PI*i/100;
            glVertex2f(radiusX*cos(angle),radiusY*sin(angle));

        }
        glEnd();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslated(cPosition,0,0);

        glPushMatrix();
            glScaled(0.8,0.5,1);
            glTranslated(1,0.5,0);
            glColor3f(c1,c2,c3);
            glRotated(ca,0,0,-1);
            circle(1,1);
        glPopMatrix();

        glPushMatrix();
            glScaled(0.8,0.5,1);
            glTranslated(2.2,1,0);
            glColor3f(c1,c2,c3);
            glRotated(ca,0,0,-1);
            circle(1,1);
        glPopMatrix();


        glPushMatrix();
           glScaled(0.8,0.5,1);
           glTranslated(1.8,0.6,0);
           glColor3f(c1,c2,c3);
           glRotated(ca,0,0,-1);
           circle(1,1);
        glPopMatrix();

        glPushMatrix();
            glScaled(0.9,0.5,1);
            glTranslated(2.2,0.1,0);
            glColor3f(c1,c2,c3);
            glRotated(ca,0,0,-1);
            circle(1,1);
       glPopMatrix();
       glPushMatrix();
            glScaled(0.9,0.5,1);
            glTranslated(0,0.1,0);
            glColor3f(c1,c2,c3);
            glRotated(ca,0,0,-1);
            circle(1,1);
       glPopMatrix();

       glPushMatrix();
            glScaled(0.8,0.5,1);
            glTranslated(1,-0.4,0);
            glColor3f(c1,c2,c3);
            glRotated(ca,0,0,-1);
            circle(1,1);
       glPopMatrix();

    glPopMatrix();

    glFlush();
}

void wheelMoveForward()
{
    cx = cx+0.001;
    ca = ca+0.1;
    glutPostRedisplay();
}

void cloudMoverRight() {
    cPosition = cPosition+0.01;
    if(cPosition > 6) {
        cPosition = -6;
    }
    glutPostRedisplay();
}
void cloudMoverLeft() {
    cPosition = cPosition-0.01;
    if(cPosition < -6) {
        cPosition = 6;
    }
    glutPostRedisplay();
}

void mouseKey(int button, int state, int x, int y) {
    switch(button) {
    case GLUT_LEFT_BUTTON:
        if(state == GLUT_DOWN) {
            glutIdleFunc(cloudMoverLeft);
        }
        else if(state == GLUT_UP) {
            glutIdleFunc(NULL);
            glutPostRedisplay();
        }

        break;

    case GLUT_RIGHT_BUTTON:
        if(state == GLUT_DOWN) {
            glutIdleFunc(cloudMoverRight);
        }
        else if(state == GLUT_UP) {
            glutIdleFunc(NULL);
            glutPostRedisplay();
        }

        break;
    default:
        break;
    }
}

void keyBoard(unsigned char key, int x, int y) {
    switch(key) {
    case 'a':
        c1=cl1;
        c2=cl2;
        c3=cl3;
        glutPostRedisplay();
        break;

    case 'b':
        c1=c2=c3=1;
        glutPostRedisplay();
        break;

    default:
        break;
    }

}

void wheelMoveBackward()
{
    ca = ca-0.1;
    cx = cx-0.01;
    glutPostRedisplay();
}

void specialkey(int key, int x, int y)
{
    switch(key){
    case GLUT_KEY_DOWN:
        break;
    case GLUT_KEY_UP:
        break;
    case GLUT_KEY_LEFT:
        glutIdleFunc(wheelMoveBackward);
        break;
    case GLUT_KEY_RIGHT:
        glutIdleFunc(wheelMoveForward);
        break;
    default:
        break;
    }
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Mouse-Key");
    init();
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(specialkey);
    glutMouseFunc(mouseKey);
    glutKeyboardFunc(keyBoard);
    glutMainLoop();

    return 0;
}
