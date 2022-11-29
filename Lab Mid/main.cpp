#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<math.h>
#define PI 3.1416
#include<stdio.h>

void init()
{
    glClearColor(2,1.9,1.9,1);
    glOrtho(-100,100,-100,100,-100,100);
}

void circle(float radiusX,float radiusY)
{
    int i;
    float angle=0.0;
    glBegin(GL_LINE_LOOP);
        for(i=0;i<100;i++)
        {
            angle= 2*PI*i/100;
            glVertex2f(radiusX*cos(angle),radiusY*sin(angle));
        }
    glEnd();

}

void line()
{
    glClear(GL_COLOR_BUFFER_BIT);

    ///main road border up
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(0.6,0.6,0.6);

            glVertex2d(-100,50);
            glVertex2d(100,50);
            glVertex2d(100,70);
            glVertex2d(-100,70);
    glEnd();

    ///main road border down
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );//main road border
        glColor3f(0.6,0.6,0.6);

            glVertex2d(-100,-45);
            glVertex2d(100,-45);
            glVertex2d(100,-65);
            glVertex2d(-100,-65);
    glEnd();

    ///main road black
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(0,0,0);

            glVertex2d(-100,50);
            glVertex2d(100,50);
            glVertex2d(100,-45);
            glVertex2d(-100,-45);
    glEnd();

    ///road up border
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(1,1,1);

            glVertex2d(-100,45);
            glVertex2d(100,45);
            glVertex2d(100,40);
            glVertex2d(-100,40);
    glEnd();

    ///road down border
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(1,1,1);

            glVertex2d(-100,-40);
            glVertex2d(100,-40);
            glVertex2d(100,-35);
            glVertex2d(-100,-35);
    glEnd();

    ///left border 3
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(1,1,1);

            glVertex2d(-100,5);
            glVertex2d(-85,5);
            glVertex2d(-85,0);
            glVertex2d(-100,0);
    glEnd();

    ///left border 2
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(1,1,1);

            glVertex2d(-76,5);
            glVertex2d(-60,5);
            glVertex2d(-60,0);
            glVertex2d(-76,0);
    glEnd();

    ///left border 1
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(1,1,1);

            glVertex2d(-35,5);
            glVertex2d(-50,5);
            glVertex2d(-50,0);
            glVertex2d(-35,0);
    glEnd();

    ///right border 1
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(1,1,1);

            glVertex2d(100,5);
            glVertex2d(85,5);
            glVertex2d(85,0);
            glVertex2d(100,0);
    glEnd();

    ///right border 2
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(1,1,1);

            glVertex2d(75,5);
            glVertex2d(59,5);
            glVertex2d(59,0);
            glVertex2d(75,0);
    glEnd();

    ///right border 3
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(1,1,1);

            glVertex2d(35,5);
            glVertex2d(50,5);
            glVertex2d(50,0);
            glVertex2d(35,0);
    glEnd();

    ///road middle border 1
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(1,1,1);

            glVertex2d(-25,30);
            glVertex2d(25,30);
            glVertex2d(25,35);
            glVertex2d(-25,35);
    glEnd();

    ///road middle border 2
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(1,1,1);

            glVertex2d(-25,20);
            glVertex2d(25,20);
            glVertex2d(25,25);
            glVertex2d(-25,25);
    glEnd();

    ///road middle border 3
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(1,1,1);

            glVertex2d(-25,10);
            glVertex2d(25,10);
            glVertex2d(25,15);
            glVertex2d(-25,15);
    glEnd();


    ///road middle border 4
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );
        glColor3f(1,1,1);

            glVertex2d(-25,5);
            glVertex2d(25,5);
            glVertex2d(25,0);
            glVertex2d(-25,0);
    glEnd();

    ///road middle border 5
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );//middle strip box
        glColor3f(1,1,1);

            glVertex2d(-25,-5);
            glVertex2d(25,-5);
            glVertex2d(25,-10);
            glVertex2d(-25,-10);
    glEnd();

    ///road middle border 6
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );//middle strip box
        glColor3f(1,1,1);

            glVertex2d(-25,-15);
            glVertex2d(25,-15);
            glVertex2d(25,-20);
            glVertex2d(-25,-20);
    glEnd();

    ///road middle border 7
    glBegin(GL_QUADS);
        glColor3f( 0.058 ,0.05,0.05 );//middle strip box
        glColor3f(1,1,1);

            glVertex2d(-25,-25);
            glVertex2d(25,-25);
            glVertex2d(25,-30);
            glVertex2d(-25,-30);
    glEnd();


    ///left circle
    glPushMatrix();
        glTranslatef(-68,2,0);
        glColor3f(1,1,1);
            circle(8,20);
    glPopMatrix();

    ///right circle
    glPushMatrix();
        glTranslatef(67,2,0);
        glColor3f(1,1,1);
            circle(8,20);
    glPopMatrix();


    glFlush();
}


int main()
{
    printf("Student ID: CSE 06908020\n");
    printf("Name: Amir Hamza..");
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Amir Hamza_CSE06908020");
    init();
    glutDisplayFunc(line);

    glutMainLoop();
}
