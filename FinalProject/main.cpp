#include<Windows.h>
#include<GL\glut.h>
#include<math.h>

void init()
{

    glClearColor(1, 1, 1, 1);


    glOrtho(-800, 800, -800, 800, -800, 800);
}

void circle(int x, int y, double h, double w)
{

    glBegin(GL_LINE_STRIP);

    for (float i = 0; i < 10; i += 0.1)
    {
        glVertex2d(x + w * cos(i), y + h * sin(i));
    }

    glEnd();
}
void circleFill(int x, int y, double h, double w)
{

    glBegin(GL_POLYGON);

    for (float i = 0; i < 10; i += 0.1)
    {
        glVertex2d(x + w * cos(i), y + h * sin(i));
    }

    glEnd();
}

void cloud(int x, int y){
    //glColor3ub(255, 255, 255);
    circleFill(0+x,0+y, 100, 100);
    circleFill(100+x,0+y, 100, 100);
    circleFill(200+x,0+y, 100, 100);
    circleFill(80+x,50+y, 130, 130);
    glBegin(GL_POLYGON);
        glVertex2d(0+x, 80+y);
        glVertex2d(200+x, 80+y);
        glVertex2d(200+x, -100+y);
        glVertex2d(0+x, -100+y);
    glEnd();

}

void rect(int x, int y, double h, double w)
{
    glPushMatrix();
    glTranslated(x, y, 0);
    glBegin(GL_QUADS);
    glVertex2d(0, 0);
    glVertex2d(0 + w, 0);
    glVertex2d(0 + w, 0 - h);
    glVertex2d(0, 0 - h);
    glEnd();
    glPopMatrix();
}

void treeBranch(){
    glColor3ub(0, 180, 0);
    circleFill(0, 0, 100, 100);
    circleFill(20, 60, 95, 95);
    circleFill(80, 100, 75, 75);

    glColor3ub(0, 200, 0);
    circleFill(50, 20, 120, 120);
    circleFill(150, -10, 90, 90);
    circleFill(150, 60, 90, 90);
}

void tree(int x, int y, double h, double w)
{
    glColor3ub(255, 255, 255);
    treeBranch();

}

void background(){

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);

        glColor3ub(220, 68, 60);
        glVertex2i(-1200, 800);

        glColor3ub(220, 68, 60);
        glVertex2i(1200, 800);
        glColor3f(1, 0.9, 0.46);
        glVertex2i(1200, -800);
        glColor3f(1, 0.9, 0.46);
        glVertex2i(-1200, -800);
    glEnd();


    glFlush();
}
void line(double x,double y)
{
    glPushMatrix();
    glTranslated(x,y,0);
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glVertex2d(20,0);
    glVertex2d(20,5);
    glVertex2d(0,5);
    glEnd();
    glPopMatrix();

}

void road(double x, double y,double z){

     // Road
    glPushMatrix();
        glTranslated(x,y,z);
        /* upper color */
        glPushMatrix();
            glColor3ub(153, 102, 51);
            glBegin(GL_POLYGON);
            glVertex3d(1000,-800,z);
            glVertex3d(-1000,-800,z);
            glVertex3d(-1000,-600,z);
            glVertex3d(1000,-600,z);

            glEnd();
        glPopMatrix();

        /* yellow border */
        glPushMatrix();
            glColor3ub(255, 255, 0);
            glBegin(GL_POLYGON);
            glVertex3d(1000,-600,z);
            glVertex3d(-1000,-600,z);
            glVertex3d(-1000,-610,z);
            glVertex3d(1000,-610,z);
            glEnd();
        glPopMatrix();


        /*topper yellow border*/
        glPushMatrix();
            glColor3ub(255, 255, 0);
            glBegin(GL_POLYGON);
            glVertex3d(1000,-800,z);
            glVertex3d(-1000,-800,z);
            glVertex3d(-1000,-790,z);
            glVertex3d(1000,-790,z);
            glEnd();
        glPopMatrix();


        /* center seferated lane1 */
        glPushMatrix();
            glColor3ub(255, 255, 0);
            glBegin(GL_POLYGON);
            glVertex3d(1000,-701,z);
            glVertex3d(-1000,-701,z);
            glVertex3d(-1000,-706,z);
            glVertex3d(1000,-706,z);
            glEnd();
        glPopMatrix();


        /* center seferated lane2 */
        glPushMatrix();
            glColor3ub(255, 255, 0);
            glBegin(GL_POLYGON);
            glVertex3d(1000,-695,z);
            glVertex3d(-1000,-695,z);
            glVertex3d(-1000,-700,z);
            glVertex3d(1000,-700,z);
            glEnd();
        glPopMatrix();

    /* white lane  */
    glPushMatrix();
    for(int i = 0; i < 801;i+=100){
        line(-i,-750);
        line(i,-750);

        line(-i,-650);
        line(i,-650);
    }
    glPopMatrix();

    glPopMatrix();

}

void building()
{
    //building
        glPushMatrix();
            glColor3ub(0,153,0);
            glTranslated(0,0,0);
            glBegin(GL_POLYGON);
                glVertex3d(0,0, 300);
                glVertex3d(0, 300, 300);
                glVertex3d(300, 300,300);
                glVertex3d(300, 0, 300);

            glEnd();
        glPopMatrix();
}


void car(){
glPushMatrix();
    // Main body
    glColor3ub(1, 104, 142);
    glBegin(GL_POLYGON);
        glVertex2d(-350,0);
        glVertex2d(400,0);
        glVertex2d(390, -150);
        glVertex2d(-360, -150);
    glEnd();

    // upper body blue
    glColor3ub(51,61,71);
    glBegin(GL_POLYGON);
        glVertex2d(-350, 0);
        glVertex2d(200,0);
        glVertex2d(75, 100);
        glVertex2d(-300, 75);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2d(-300, 75);
        glVertex2d(-335, 75);
        glVertex2d(-290, 45);
    glEnd();

    // upper body line bisque
    /*glColor3ub(255, 248, 150);
    glBegin(GL_POLYGON);
        glVertex2d(-20, 75);
        glVertex2d(140, 75);
        glVertex2d(-30, 55);
    glEnd();*/

    // tires
    glColor3ub(42, 33, 45);
    circleFill(-200, -140, 60, 60);
    circleFill(250, -140, 60, 60);

    // wheels
    glColor3ub(167,169,174);
    circleFill(-200, -140, 30, 30);
    circleFill(250, -140, 30, 30);

    // backlight
    glColor3ub(200, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2d(-320, -45);
        glVertex2d(-355, -55);
        glVertex2d(-355, -75);
        glVertex2d(-320, -75);
    glEnd();

    //backLightInWhite
    glColor3ub(233, 231, 200);
    glBegin(GL_POLYGON);
        glVertex2d(-325, -55);
        glVertex2d(-350, -60);
        glVertex2d(-350, -70);
        glVertex2d(-325, -70);
    glEnd();

    // frontlight
    glColor3ub(218,215,176);
    glBegin(GL_POLYGON);
        glVertex2d(360, -25);
        glVertex2d(398, -35);
        glVertex2d(398, -55);
        glVertex2d(360, -50);
    glEnd();

    // DoorHandle
    glColor3ub(42,33,45);
    glBegin(GL_POLYGON);
        glVertex2d(-30, -25);
        glVertex2d(20, -25);
        glVertex2d(20, -35);
        glVertex2d(-30, -35);
    glEnd();
    glPopMatrix();
}



void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslated(0,200,0);
    glRotated(-15,1,0,0);
    glPushMatrix();
  /*  glRotated(-20,1,0,1);
    road(0,0,0);
    glPushMatrix();
    glRotated(90,0,0,1);
    road(200,700,10);


    glPopMatrix();
*/
    glScaled(.3,.3,1);
        car();
    //building();
    glPopMatrix();

        glFlush();
}

int main(int argc, char ** argv)
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(100, 100);

    glutInitWindowSize(1000, 800);

    glutCreateWindow("2D House in OpenGL ");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
}
