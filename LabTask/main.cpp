#include<stdio.h>
#include<windows.h>
#include<math.h>
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define PI 3.1416
#include <stdlib.h>

float cx=1,cy=1;
float ca=1;
void init()
{
    glClearColor(0,0,0,0);
    glOrtho(-25,25,-25,25,-25,25);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

        glTranslated(0+cx,0+cy,0);
        glRotated(ca ,-1 , 0 ,0);

        glBegin(GL_LINE_LOOP);
            glColor3f(1,1,1);
            glVertex2d(0,10);
            glVertex2d(-6,5);
            glVertex2d(-6,-5);
            glVertex2d(0,-10);
            glVertex2d(6,-5);
            glVertex2d(6,5);
        glEnd();
        glBegin(GL_LINES);
            glColor3f(1,1,1);
            glVertex2d(-6,5);
            glVertex2d(6,-5);
        glEnd();
        glBegin(GL_LINES);
            glColor3f(1,1,1);
            glVertex2d(-6,-5);
            glVertex2d(6,5);
        glEnd();
        glBegin(GL_LINES);
            glColor3f(1,1,1);
            glVertex2d(0,10);
            glVertex2d(0,-10);
        glEnd();
    glPopMatrix();
    glFlush();
}

void rotated()
{
    ca = ca + 0.1;
    glutPostRedisplay();
}

void wheelMoveForward()
{
    cx = cx+0.01;
    glutPostRedisplay();
}

void wheelMoveBackward()
{
    cx = cx-0.01;
    glutPostRedisplay();
}
void wheelMoveUpkward()
{
    cy = cy+0.01;
    glutPostRedisplay();
}
void wheelMoveDownkward()
{
    cy = cy-0.01;
    glutPostRedisplay();
}

void specialkey(int key, int x, int y)
{
    switch(key){
    case GLUT_KEY_DOWN:
        glutIdleFunc(wheelMoveDownkward);
        break;
    case GLUT_KEY_UP:
        glutIdleFunc(wheelMoveUpkward);
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
void keyBoardKey(unsigned char key, int x, int y)
{
  switch(key){
  case 'r':
      glutIdleFunc(rotated);
      break;
  case 's':
    glutIdleFunc(NULL);
  default:
    break;
  }
}

int main()
{
    printf("Student ID: CSE 069 08020\n");
    printf("Stduent Name: Amir Hamza");

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1100,700);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Amir Hamza_CSE06908020");
    init();
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(specialkey);
    glutKeyboardFunc(keyBoardKey);
    glutMainLoop();

    return 0;
}
