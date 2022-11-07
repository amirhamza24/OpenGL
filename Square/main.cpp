#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include<windows.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>
float rx = 0.0;
float ry = 0.0;
float rz = 0.0;
float r = 45.0;

void lightRendering(){
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    //There are 7 Diffuse Light in OPENGL
     //There are 1 A
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}

void reshape(int width, int height){
  glViewport(0,0,width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0, (double)width/(double)height, 1.0, 200.0);

}
void myDisplay(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   GLfloat ambienLight[]={0.4f,0.3f,0.2f,1.0f};
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambienLight);


   /*GLfloat light0[]={0.5f,0.7f,0.9,1.0f};
   GLfloat position0[]={1.0f,2.0f,2.0f};
   glLightfv(GL_LIGHT0,GL_DIFFUSE,light0);
   glLightfv(GL_LIGHT0,GL_DIFFUSE,position0);

    GLfloat light1[]={0.7f,0.8f,0.9,1.0f};
   GLfloat position1[]={-1.0f,-2.0f,-2.0f};
   glLightfv(GL_LIGHT0,GL_DIFFUSE,light1);
   glLightfv(GL_LIGHT0,GL_DIFFUSE,position1);
   */






  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslated(0,0,-20);
  glRotated(r,1,1,0);
  ///front
  glPushMatrix();
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
      glVertex3f(3,3,3);
      glVertex3f(-3,3,3);
      glVertex3f(-3,-3,3);
      glVertex3f(3,-3,3);
    glEnd();
  glPopMatrix();

   ///back
  glPushMatrix();
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_QUADS);
      glVertex3f(3,3,-3);
      glVertex3f(-3,3,-3);
      glVertex3f(-3,-3,-3);
      glVertex3f(3,-3,-3);
    glEnd();
  glPopMatrix();

  ///left side
  glPushMatrix();
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_QUADS);
      glVertex3f(-3,3,3);
      glVertex3f(-3,3,-3);
      glVertex3f(-3,-3,-3);
      glVertex3f(-3,-3,3);
    glEnd();
  glPopMatrix();

  ///right side
  glPushMatrix();
    glColor3f(1.0f,0.0f,1.0f);
    glBegin(GL_QUADS);
      glVertex3f(3,3,3);
      glVertex3f(3,3,-3);
      glVertex3f(3,-3,-3);
      glVertex3f(3,-3,3);
    glEnd();
  glPopMatrix();

  ///top side
  glPushMatrix();
    glColor3f(0.5f,0.7f,1.0f);
    glBegin(GL_QUADS);
      glVertex3f(-3,3,-3);
      glVertex3f(3,3,-3);
      glVertex3f(3,3,3);
      glVertex3f(-3,3,3);
    glEnd();
  glPopMatrix();

  ///bottom side
  glPushMatrix();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
      glVertex3f(-3,-3,-3);
      glVertex3f(3,-3,-3);
      glVertex3f(3,-3,3);
      glVertex3f(-3,-3,3);
    glEnd();
  glPopMatrix();

  glutSwapBuffers();

}
void xRotate(){
    r+=0.1;
    glutPostRedisplay();
}
void myKey(unsigned char key,int x,int y){
  switch(key){
    case 'x':
      glutIdleFunc(xRotate);
      break;

    default:
      break;
  }




}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    //glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("3D Object");
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshape);
    glutDisplayFunc(myDisplay);
    lightRendering();
    glutKeyboardFunc(myKey);

    glutMainLoop();

    return EXIT_SUCCESS;
}
