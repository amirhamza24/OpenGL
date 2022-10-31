#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include<windows.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>

double r;

void reshape(int width, int height){
  glViewport(0,0,width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0, (double)width/(double)height, 1.0, 200.0);

}

void cube(float a, float b, float c)
{

  glPushMatrix();
   glColor3f(a,b,c);
  glPushMatrix();
    //glColor3f(1.0f,1.0f,0.0f);
    glBegin(GL_QUADS);
      glVertex3f(3,3,3);
      glVertex3f(-3,3,3);
      glVertex3f(-3,-3,3);
      glVertex3f(3,-3,3);
    glEnd();
  glPopMatrix();

   ///back
  glPushMatrix();
    //glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_QUADS);
      glVertex3f(3,3,-3);
      glVertex3f(-3,3,-3);
      glVertex3f(-3,-3,-3);
      glVertex3f(3,-3,-3);
    glEnd();
  glPopMatrix();

  ///left side
  glPushMatrix();
    //glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_QUADS);
      glVertex3f(-3,3,3);
      glVertex3f(-3,3,-3);
      glVertex3f(-3,-3,-3);
      glVertex3f(-3,-3,3);
    glEnd();
  glPopMatrix();

  ///right side
  glPushMatrix();
    //glColor3f(0.1f,0.0f,1.0f);
    glBegin(GL_QUADS);
      glVertex3f(3,3,3);
      glVertex3f(3,3,-3);
      glVertex3f(3,-3,-3);
      glVertex3f(3,-3,3);
    glEnd();
  glPopMatrix();

  ///top side
  glPushMatrix();

        //glColor3f(1,0,0);
    glBegin(GL_QUADS);
      glVertex3f(-3,3,-3);
      glVertex3f(3,3,-3);
      glVertex3f(3,3,3);
      glVertex3f(-3,3,3);
    glEnd();
  glPopMatrix();

  ///bottom side
  glPushMatrix();
    //glColor3f(0.8f,0.0f,1.0f);
    glBegin(GL_QUADS);
      glVertex3f(-3,-3,-3);
      glVertex3f(3,-3,-3);
      glVertex3f(3,-3,3);
      glVertex3f(-3,-3,3);
    glEnd();
  glPopMatrix();
  glPopMatrix();
}


void myDisplay(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslated(0,0,-20);
  //glRotated(-45,1,1,0);
  glRotated(r,1,0,1);


    glPushMatrix();
        glTranslated(0,2,-2);
        glScaled(1,1,0.1);
        cube(1,0,0);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,-1,1);
        glScaled(1,0.1,1);
        cube(1,1,0);
    glPopMatrix();

    glPushMatrix();
        glTranslated(2.8,-3.8,3);
        glScaled(0.1,1,0.1);
        cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-2.8,-3.8,3);
        glScaled(0.1,1,0.1);
        cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-2.8,-3.8,-3);
        glScaled(0.1,1,0.1);
        cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(+2.8,-3.8,-3);
        glScaled(0.1,1,0.1);
        cube(1,1,1);
    glPopMatrix();


  glutSwapBuffers();

}

void rotates()
{
    r = r + 0.1;
    glutPostRedisplay();
}

void keyMove(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'r':
        glutIdleFunc(rotates);
        break;

    case 'b':
        glutIdleFunc(NULL);
        break;
    }

}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    //glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("3D Object");
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshape);
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyMove);


    glutMainLoop();

    return EXIT_SUCCESS;
}
