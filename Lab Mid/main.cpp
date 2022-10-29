#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<math.h>
#define PI 3.1416
#include <stdlib.h>
#include <stdio.h>

void init()
{
 glClearColor(2,1.9,1.9,1);
 glOrtho(-100,100,-100,100,-100,100);
}

void circle(float radiusX,float radiusY){
    int i;
    float angle=0.0;
    glBegin(GL_LINE_LOOP);
        for(i=0;i<100;i++){
            angle= 2*PI*i/100;
            glVertex2f(radiusX*cos(angle),radiusY*sin(angle));

        }
    glEnd();

}

void line()
{
 glClear(GL_COLOR_BUFFER_BIT);



glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//main road border
     glColor3f(0.6,0.6,0.6);

        glVertex2d(-100,50);
        glVertex2d(100,50);
        glVertex2d(100,70);
        glVertex2d(-100,70);
glEnd();

glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//main road
       glColor3f(0,0,0);

        glVertex2d(-100,50);
        glVertex2d(100,50);
        glVertex2d(100,-45);
        glVertex2d(-100,-45);
glEnd();
glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//main road border
       glColor3f(0.6,0.6,0.6);

        glVertex2d(-100,-45);
        glVertex2d(100,-45);
        glVertex2d(100,-65);
        glVertex2d(-100,-65);
glEnd();

glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//up strip
       glColor3f(1,1,1);

        glVertex2d(-100,45);
        glVertex2d(100,45);
        glVertex2d(100,40);
        glVertex2d(-100,40);
glEnd();

glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//down strip
       glColor3f(1,1,1);

        glVertex2d(-100,-40);
        glVertex2d(100,-40);
        glVertex2d(100,-35);
        glVertex2d(-100,-35);
glEnd();
///////////////////////////////////////////////

glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//middle strip1
       glColor3f(1,1,1);

        glVertex2d(-100,5);
        glVertex2d(-80,5);
        glVertex2d(-80,0);
        glVertex2d(-100,0);
glEnd();

glPushMatrix();
   glTranslatef(-60,2,0);
   glColor3f(1,1,1);
   circle(16,16);
   glPopMatrix();

glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//middle strip2
      glColor3f(1,1,1);

        glVertex2d(-70,5);
        glVertex2d(-50,5);
        glVertex2d(-50,0);
        glVertex2d(-70,0);
glEnd();

glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//middle strip3
       glColor3f(1,1,1);

        glVertex2d(-20,5);
        glVertex2d(-40,5);
        glVertex2d(-40,0);
        glVertex2d(-20,0);
glEnd();


glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//middle strip1.2
       glColor3f(1,1,1);

        glVertex2d(100,5);
        glVertex2d(80,5);
        glVertex2d(80,0);
        glVertex2d(100,0);
glEnd();
glPushMatrix();
   glTranslatef(60,2,0);
   glColor3f(1,1,1);
   circle(16,16);
   glPopMatrix();

glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//middle strip2.2
       glColor3f(1,1,1);

        glVertex2d(70,5);
        glVertex2d(50,5);
        glVertex2d(50,0);
        glVertex2d(70,0);
glEnd();

glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//middle strip3.2
      glColor3f(1,1,1);

        glVertex2d(20,5);
        glVertex2d(40,5);
        glVertex2d(40,0);
        glVertex2d(20,0);
glEnd();
/////////////////////////////////////

glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//middle strip box
       glColor3f(1,1,1);

        glVertex2d(-5,5);
        glVertex2d(10,5);
        glVertex2d(10,0);
        glVertex2d(-5,0);
glEnd();

glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//middle strip box
      glColor3f(1,1,1);

        glVertex2d(-5,10);
        glVertex2d(10,10);
        glVertex2d(10,15);
        glVertex2d(-5,15);
glEnd();

glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//middle strip box
       glColor3f(1,1,1);

        glVertex2d(-5,20);
        glVertex2d(10,20);
        glVertex2d(10,25);
        glVertex2d(-5,25);
glEnd();

glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//middle strip box
       glColor3f(1,1,1);

        glVertex2d(-5,35);
        glVertex2d(10,35);
        glVertex2d(10,30);
        glVertex2d(-5,30);
glEnd();






glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//middle strip box
       glColor3f(1,1,1);

        glVertex2d(-5,-5);
        glVertex2d(10,-5);
        glVertex2d(10,-10);
        glVertex2d(-5,-10);
glEnd();




glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//middle strip box
       glColor3f(1,1,1);

        glVertex2d(-5,-15);
        glVertex2d(10,-15);
        glVertex2d(10,-20);
        glVertex2d(-5,-20);
glEnd();

glBegin(GL_QUADS);
     glColor3f( 0.058 ,0.05,0.05 );//middle strip box
       glColor3f(1,1,1);

        glVertex2d(-5,-25);
        glVertex2d(10,-25);
        glVertex2d(10,-30);
        glVertex2d(-5,-30);
glEnd();




 glFlush();
}
int main()
{
    printf("Name: Amir Hamza\n");
    printf("Id: CSE 069 08020");
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Amir Hamza_CSE06908020");
    init();
    glutDisplayFunc(line);

    glutMainLoop();
}
