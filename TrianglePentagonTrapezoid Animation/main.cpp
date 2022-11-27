#include <windows.h>
#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

float angle = 30.0f;


void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);


    glPushMatrix();
        glTranslated(0, -500, 0);
        glRotated(angle,0,0,-1);

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS); //Begin quadrilateral coordinates

        //Trapezoid
        glVertex3d(-200, 150, 0);
        glVertex3d(-200, -150, 0);
        glVertex3d(200, -150, 0);
        glVertex3d(200, 150, 0);

        glEnd(); //End quadrilateral coordinates
	glPopMatrix();

    glPushMatrix();
        glTranslated(600, 600, 0);
        glRotated(angle, 0, 1, 0);

        glBegin(GL_TRIANGLES); //Begin triangle coordinates

        //Pentagon
        glColor3f (1.0, 0.0, 1.0);
        glVertex3d(100, 0, 0);
        glVertex3d(100, -200, 0);
        glVertex3d(300, -200, 0);

        glColor3f (1.0, 1.0, 0.0);
        glVertex3d(300, 0, 0);
        glVertex3d(300, -200, 0);
        glVertex3d(100, 0, 0);

        glColor3f (0.0, 1.0, 1.0);
        glVertex3d(100, 0, 0);
        glVertex3d(300, 0, 0);
        glVertex3d(200, 150, 0);
        glEnd();
    glPopMatrix();


    glPushMatrix();
        glTranslated(-650, 400, 0);
        glRotated(angle, 1, 0, 0);

        glBegin(GL_TRIANGLES);
	//Triangle
        glVertex3d(-200, 200, 0);
        glVertex3d(200, 200, 0);
        glVertex3d(0, 500, 0);

        glEnd();//End triangle coordinates

	glPopMatrix();

    glFlush ();
}
void init (void)
{
    /* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1000, 1000, -1000, 1000, -1000, 1000);
}

void update(int val) {
    angle = angle + 2.0f;
    if(angle>360) {
        angle = angle - 360;
    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);

    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
