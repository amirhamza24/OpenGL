#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include<windows.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<stdio.h>

double r;
void reshape(int width, int height){
  glViewport(0,0,width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0, (double)width/(double)height, 1.0, 200.0);

}
void myDisplay(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslated(0,0,-20);
  //glRotated(-45,1,1,0);
  glRotated(r,0,1,0);
  //glRotated(r,0,1,0);

    ///door
      glPushMatrix();
       glColor3ub(102, 51, 0);
       glBegin(GL_QUADS);
       glVertex3d(-2,1.8,3.1);
       glVertex3d(-2,-2,3.1);
       glVertex3d(-0.8, -2,3.1);
       glVertex3d(-0.8,1.8,3.1);
       glEnd;
      glPopMatrix();

      ///window1
      glPushMatrix();
      glColor3ub(102, 51, 0);
      glBegin(GL_QUADS);
      glVertex3d(-0.5,1.8,3.1);
      glVertex3d(-0.5,0.5,3.1);
      glVertex3d(0.6, 0.5,3.1);
      glVertex3d(0.6,1.8,3.1);
      glEnd;
      glPopMatrix();

      glPushMatrix();
      glColor3ub(102, 51, 0);
      glBegin(GL_QUADS);
      glVertex3d(1,1.8,3.1);
      glVertex3d(1,0.5,3.1);
      glVertex3d(2, 0.5,3.1);
      glVertex3d(2,1.8,3.1);
      glEnd;
      glPopMatrix();

      glPushMatrix();
      glColor3ub(102, 51, 0);
      glBegin(GL_QUADS);
      glVertex3d(2.4,1.8,3.1);
      glVertex3d(2.4,0.5,3.1);
      glVertex3d(3.4, 0.5,3.1);
      glVertex3d(3.4,1.8,3.1);
      glEnd;
      glPopMatrix();

      glPushMatrix();
      glColor3ub(102, 51, 0);
      glBegin(GL_QUADS);
      glVertex3d(3.8,1.8,3.1);
      glVertex3d(3.8,0.5,3.1);
      glVertex3d(4.8, 0.5,3.1);
      glVertex3d(4.8,1.8,3.1);
      glEnd;
      glPopMatrix();


      glPushMatrix();
      glColor3ub(102, 51, 0);
      glBegin(GL_QUADS);
      glVertex3d(-0.5,1.8,-3.1);
      glVertex3d(-0.5,0.5,-3.1);
      glVertex3d(0.6, 0.5,-3.1);
      glVertex3d(0.6,1.8,-3.1);
      glEnd;
      glPopMatrix();

      glPushMatrix();
      glColor3ub(102, 51, 0);
      glBegin(GL_QUADS);
      glVertex3d(1,1.8,-3.1);
      glVertex3d(1,0.5,-3.1);
      glVertex3d(2, 0.5,-3.1);
      glVertex3d(2,1.8,-3.1);
      glEnd;
      glPopMatrix();

      glPushMatrix();
      glColor3ub(102, 51, 0);
      glBegin(GL_QUADS);
      glVertex3d(2.4,1.8,-3.1);
      glVertex3d(2.4,0.5,-3.1);
      glVertex3d(3.4, 0.5,-3.1);
      glVertex3d(3.4,1.8,-3.1);
      glEnd;
      glPopMatrix();

      glPushMatrix();
      glColor3ub(102, 51, 0);
      glBegin(GL_QUADS);
      glVertex3d(3.8,1.8,-3.1);
      glVertex3d(3.8,0.5,-3.1);
      glVertex3d(4.8, 0.5,-3.1);
      glVertex3d(4.8,1.8,-3.1);
      glEnd;
      glPopMatrix();


  ///front
  glPushMatrix();
    glColor3f(1.0f,1.0f,0.0f);
    glBegin(GL_QUADS);
      glVertex3f(6,3,3);
      glVertex3f(-2,3,3);
      glVertex3f(-6,-3,3);
      glVertex3f(6,-3,3);


      /*glPushMatrix();
       glColor3ub(102, 51, 0);
       glBegin(GL_QUADS);
       glVertex3d(-2,1.8,3);
       glVertex3d(-2,-2,3);
       glVertex3d(-1, -2,3);
       glVertex3d(-1,1.8,3);
       glEnd;
      glPopMatrix();

      glPushMatrix();
      glColor3ub(102, 51, 0);
      glBegin(GL_QUADS);
      glVertex3d(-0.5,1.8,3);
      glVertex3d(-0.5,0,3);
      glVertex3d(0.6, 0,3);
      glVertex3d(0.6,1.8,3);
      glEnd;
      glPopMatrix();*/
    glEnd();
  glPopMatrix();

   ///back
  glPushMatrix();
    glColor3f(1.0f,1.0f,0.0f);
    glBegin(GL_QUADS);
      glVertex3f(6,3,-3);
      glVertex3f(-2,3,-3);
      glVertex3f(-6,-3,-3);
      glVertex3f(6,-3,-3);

    glEnd();
  glPopMatrix();

  ///left side
  glPushMatrix();
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
      glVertex3f(-2,3,3);
      glVertex3f(-2,3,-3);
      glVertex3f(-6,-3,-3);
      glVertex3f(-6,-3,3);
    glEnd();
  glPopMatrix();

  ///right side
  glPushMatrix();
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
      glVertex3f(6,3,3);
      glVertex3f(6,3,-3);
      glVertex3f(6,-3,-3);
      glVertex3f(6,-3,3);
    glEnd();
  glPopMatrix();

  ///top side
  glPushMatrix();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
      glVertex3f(-2,3,-3);
      glVertex3f(6,3,-3);
      glVertex3f(6,3,3);
      glVertex3f(-2,3,3);
    glEnd();
  glPopMatrix();

  glutSwapBuffers();

}

void rotates()
{
    r = r + 0.1;
    glutPostRedisplay();
}

void rotates2()
{

    r = r+0.1;
    glutPostRedisplay();
}

void keyMove(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'r':
        glutIdleFunc(rotates);
        break;

    case 'a':
        glutIdleFunc(rotates2);
        break;

    case 'b':
        glutIdleFunc(NULL);
        break;
    }

}


int main(int argc, char *argv[])
{

    printf("Student Id: CSE 06908020\n");
    printf("Name: Amir Hamza");
    glutInit(&argc, argv);
    glutInitWindowSize(1100,700);
    //glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("ID: CSE06908020.. Name: Amir Hamza");
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshape);
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyMove);


    glutMainLoop();

    return EXIT_SUCCESS;
}
