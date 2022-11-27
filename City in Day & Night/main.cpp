#include<windows.h>
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

#include <stdlib.h>

double vPos1 = 0;
double vPos2 = 800;
double vPos3 = -400;
double vPos4 = 700;
double vPos5 = -800;
double vPos6 = -300;

double vSpeed1 = 0.0;
double vSpeed2 = 0.0;
double vSpeed3 = 0.0;
double vSpeed4 = 0.0;
double vSpeed5 = 0.0;
double vSpeed6 = 0.0;

void init()
{
    glClearColor(0,0,0,0);
    glOrtho(-300,300,-300,300,-300,300);
}
void circleShape(int x, int y, double h, double w){

    glBegin(GL_POLYGON);

    for (float i = 0; i < 10; i += 0.1){
        glVertex2d(x + w * cos(i), y + h * sin(i));
    }

    glEnd();
}

void truck(){
    // container
    glColor3ub(247, 176, 35);
    glBegin(GL_POLYGON);
        glVertex2d(0,0);
        glVertex2d(400,0);
        glVertex2d(400, 150);
        glVertex2d(0, 150);
    glEnd();

    // main body
    glBegin(GL_POLYGON);
        glColor3ub(180, 180, 180);
        glVertex2d(0,-10);
        glVertex2d(420,-10);
        glColor3ub(160, 160, 160);
        glVertex2d(420, -40);
        glColor3ub(180, 180, 180);
        glVertex2d(0, -40);
    glEnd();

    // Head
    glColor3ub(40, 40, 200);
    glBegin(GL_POLYGON);
        glColor3ub(100, 100, 200);
        glVertex2d(400,-40);
        glVertex2d(550,-40);

        glColor3ub(140, 140, 240);
        glVertex2d(550, 40);

        glColor3ub(180, 180, 255);
        glVertex2d(470, 100);
        glVertex2d(400, 100);
    glEnd();

    glPushMatrix();
        glTranslated(440, 15, 1);
        glScaled(0.4, 0.7, 1);
        glBegin(GL_POLYGON);
            glColor3ub(99, 99, 99);
            glVertex2d(-70,20);
            glColor3ub(55, 55, 55);
            glVertex2d(200,20);
            glColor3ub(99, 99, 99);
            glVertex2d(100, 100);
            glColor3ub(55, 55, 55);
            glVertex2d(-70, 100);
        glEnd();
    glPopMatrix();

    // tires
    glColor3ub(85,85,85);
    circleShape(100, -40, 50, 50);
    circleShape(450, -40, 50, 50);


    // wheels
    glColor3ub(200,200,200);
    circleShape(100, -40, 20, 20);
    circleShape(450, -40, 20, 20);


}

void car(){
    // Main body
    glColor3ub(7, 126, 159);
    glBegin(GL_POLYGON);
        glVertex2d(-350,0);
        glVertex2d(390,0);
        glVertex2d(400, -110);
        glVertex2d(-350, -110);
    glEnd();

    // upper body black
    glColor3ub(100, 100, 130);
    glBegin(GL_POLYGON);
        glVertex2d(-350,0);
        glVertex2d(250,0);
        glVertex2d(120, 120);
        glVertex2d(-280, 120);
    glEnd();

    glColor3ub(255, 248, 150);
    glBegin(GL_POLYGON);
        glColor3ub(99, 99, 99);
        glVertex2d(-300,20);
        glColor3ub(55, 55, 55);
        glVertex2d(-100,20);
        glColor3ub(99, 99, 99);
        glVertex2d(-100, 100);
        glColor3ub(55, 55, 55);
        glVertex2d(-250, 100);
    glEnd();

    glColor3ub(255, 248, 150);
    glBegin(GL_POLYGON);
        glColor3ub(99, 99, 99);
        glVertex2d(-70,20);
        glColor3ub(55, 55, 55);
        glVertex2d(200,20);
        glColor3ub(99, 99, 99);
        glVertex2d(100, 100);
        glColor3ub(55, 55, 55);
        glVertex2d(-70, 100);
    glEnd();


    // tires
    glColor3ub(85,85,85);
    circleShape(-200, -110, 60, 60);
    circleShape(250, -110, 60, 60);

    // wheels
    glColor3ub(200,200,200);
    circleShape(-200, -110, 30, 30);
    circleShape(250, -110, 30, 30);
}

void poly(int x, int y)
{
    glPushMatrix();
    glTranslated(x,y,0);
    glBegin(GL_POLYGON);
    glColor3ub(218, 214, 221);
    glVertex2d(-310,322);
    glVertex2d(-292,322);
    glVertex2d(-292,277);
    glVertex2d(-310,277);
    glEnd();
    glPopMatrix();

}

void Line(int x,int y, int x1, int y1)
{
    glPushMatrix();
    glColor3ub(166, 127, 156);
    glBegin(GL_POLYGON);
    glVertex2d(295+x,50+y);
    glVertex2d(295+x1,200+y1);
    glVertex2d(300+x1,200+y1);
    glVertex2d(300+x,50+y);
    glEnd();
    glPopMatrix();
}

void Line2(int x,int y, int x1, int y1)
{
    glPushMatrix();
    glColor3ub(197, 183, 198);
    glBegin(GL_POLYGON);
    glVertex2d(295+x,50+y);
    glVertex2d(295+x1,199+y1);
    glVertex2d(300+x1,200+y1);
    glVertex2d(300+x,50+y);
    glEnd();
    glPopMatrix();
}

void Zebra(int x)
{
    glPushMatrix();
    glTranslated(x,-140,0);
    glColor3ub(252, 252, 250);
    glBegin(GL_POLYGON);
    glVertex2d(10,30);
    glVertex2d(13,30);
    glVertex2d(-10,-30);
    glVertex2d(-13,-30);
    glEnd();
    glPopMatrix();
}
void update(){
    vPos1 += vSpeed1;
    if(vPos1 > 2000){
        vPos1 = -4500;
    }

    vPos2 += vSpeed2;
    if(vPos2 > 3000){
        vPos2 = -5500;
    }

    vPos6 += vSpeed6;
    if(vPos6 > 3000){
        vPos6 = -4500;
    }

    vPos3 -= vSpeed3;
    if(vPos3 < -3000){
        vPos3 = 3500;
    }

    vPos4 -= vSpeed4;
    if(vPos4 < -3500){
        vPos4 = 4500;
    }

    vPos5 -= vSpeed5;
    if(vPos5 < -4000){
        vPos5 = 3500;
    }

    glutPostRedisplay();
}


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    ///UPPER PORTION

    ///BackGround
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(118, 129, 149);
    glVertex2d(-300,50);
    glVertex2d(300,50);
    glVertex2d(300,-300);
    glVertex2d(-300,-300);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(164, 230, 255);
    glVertex2d(-300,50);
    glVertex2d(300,50);
    glVertex2d(300,300);
    glVertex2d(-300,300);
    glEnd();

    glPopMatrix();
    ///Background Building
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(171, 190, 232);
    glVertex2d(-40,180);
    glVertex2d(0,180);
    glVertex2d(0,50);
    glVertex2d(-40,50);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(171, 190, 232);
    glVertex2d(0,160);
    glVertex2d(20,160);
    glVertex2d(20,50);
    glVertex2d(0,50);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(171, 190, 232);
    glVertex2d(20,230);
    glVertex2d(60,230);
    glVertex2d(60,50);
    glVertex2d(20,50);
    glEnd();
    glPopMatrix();
    ///Back Back
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(140, 164, 210);
    glVertex2d(-40,100);
    glVertex2d(0,100);
    glVertex2d(0,50);
    glVertex2d(-40,50);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(140, 164, 210);
    glVertex2d(0,80);
    glVertex2d(20,80);
    glVertex2d(20,50);
    glVertex2d(0,50);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(140, 164, 210);
    glVertex2d(20,150);
    glVertex2d(60,150);
    glVertex2d(60,50);
    glVertex2d(20,50);
    glEnd();
    glPopMatrix();
    ///Left Building
    glPushMatrix();
    glColor3ub(172, 139, 156);
    glBegin(GL_POLYGON);
    glVertex2d(-130,50);
    glVertex2d(-300,50);
    glVertex2d(-300,300);
    glVertex2d(-130,300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(106, 81, 100);
    glBegin(GL_POLYGON);
    glVertex2d(-130,50);
    glVertex2d(-300,50);
    glVertex2d(-300,113);
    glVertex2d(-130,113);
    glEnd();
    glPopMatrix();
    for(int i=0;i <240; i+=48){
        for(int j=0; j<100; j+=20){
            poly(j,-i);
        }
    }
    glPushMatrix();
    glColor3ub(86, 90, 119);
    glBegin(GL_POLYGON);
    glVertex2d(-130,196);
    glVertex2d(-212,196);
    glVertex2d(-212,193);
    glVertex2d(-130,193);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(86, 90, 119);
    glVertex2d(-130,50);
    glVertex2d(-115,50);
    glVertex2d(-115,300);
    glVertex2d(-130,300);
    glEnd();
    glPopMatrix();

     ///Left Back Building
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(86, 90, 119);
    glVertex2d(-100,60);
    glVertex2d(-25,60);
    glVertex2d(-25,250);
    glVertex2d(-100,250);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(124, 148, 192);
    glVertex2d(-90,60);
    glVertex2d(-29,60);
    glVertex2d(-29,250);
    glVertex2d(-90,250);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINES);
    glColor3ub(86, 90, 119);
    glVertex2d(-80,60);
    glVertex2d(-80,250);
    glVertex2d(-75,60);
    glVertex2d(-75,250);
    glEnd();
    glPopMatrix();

    ///Right Front Building
    glPushMatrix();
    glColor3ub(53, 48, 68);
    glBegin(GL_POLYGON);
    glVertex2d(215,50);
    glVertex2d(215,200);
    glVertex2d(300,200);
    glVertex2d(300,55);
    glEnd();
    glPopMatrix();

    Line(0,0,0,0);
    Line(-22,0,-22,0);
    Line(-55,0,-55,0);
    Line(-80,0,-80,0);

    /// Right Side big

    glPushMatrix();
    glColor3ub(108, 131, 175);
    glBegin(GL_POLYGON);
    glVertex2d(60,50);
    glVertex2d(60,300);
    glVertex2d(195,300);
    glVertex2d(195,50);
    glEnd();
    glPopMatrix();


    Line(0,0,0,0);
    Line(-240,0,-240,200);
    Line(-220,0,-220,200);
    Line(-200,0,-200,200);
    Line(-180,0,-180,200);
    Line(-100,0,-100,200);
    ///Right Side
    glPushMatrix();
    glColor3ub(53, 48, 68);
    glBegin(GL_POLYGON);
    glVertex2d(215,50);
    glVertex2d(215,200);
    glVertex2d(130,185);
    glVertex2d(130,60);
    glEnd();
    glPopMatrix();

    Line2(-85,0,-85,0);
    Line2(-110,4,-110,-4);
    Line2(-140,7,-140,-9);
    Line2(-165,10,-165,-14);




    /// Right side 2 big

    glPushMatrix();
    glColor3ub(102, 80, 116);
    glBegin(GL_POLYGON);
    glVertex2d(220,200);
    glVertex2d(220,300);
    glVertex2d(300,300);
    glVertex2d(300,200);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glColor3ub(71, 51, 76);
    glBegin(GL_POLYGON);
    glVertex2d(220,200);
    glVertex2d(220,300);
    glVertex2d(240,300);
    glVertex2d(240,200);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glColor3ub(75, 76, 104);
    glBegin(GL_POLYGON);
    glVertex2d(240,250);
    glVertex2d(300,250);
    glVertex2d(300,255);
    glVertex2d(240,255);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75, 76, 104);
    glBegin(GL_POLYGON);
    glVertex2d(233,200);
    glVertex2d(233,300);
    glVertex2d(240,300);
    glVertex2d(240,200);
    glEnd();
    glPopMatrix();


    /// right 2 big windows

    glColor3ub(185, 150, 165);
    glBegin(GL_POLYGON);
    glVertex2d(260,235);
    glVertex2d(270,235);
    glVertex2d(270,240);
    glVertex2d(260,240);
    glEnd();
    glPopMatrix();

    glColor3ub(185, 150, 165);
    glBegin(GL_POLYGON);
    glVertex2d(275,235);
    glVertex2d(290,235);
    glVertex2d(290,240);
    glVertex2d(275,240);
    glEnd();

    glPopMatrix();
    glColor3ub(185, 150, 165);
    glBegin(GL_POLYGON);
    glVertex2d(270,220);
    glVertex2d(270,225);
    glVertex2d(280,225);
    glVertex2d(280,220);
    glEnd();
    glPopMatrix();

    glPopMatrix();
    glColor3ub(185, 150, 165);
    glBegin(GL_POLYGON);
    glVertex2d(240,220);
    glVertex2d(240,225);
    glVertex2d(255,225);
    glVertex2d(255,220);
    glEnd();
    glPopMatrix();

    glPopMatrix();
    glColor3ub(185, 150, 165);
    glBegin(GL_POLYGON);
    glVertex2d(240,260);
    glVertex2d(240,265);
    glVertex2d(255,265);
    glVertex2d(255,260);
    glEnd();
    glPopMatrix();

    glPopMatrix();
    glColor3ub(185, 150, 165);
    glBegin(GL_POLYGON);
    glVertex2d(260,270);
    glVertex2d(260,280);
    glVertex2d(270,280);
    glVertex2d(270,270);
    glEnd();

    glPopMatrix();
    glColor3ub(185, 150, 165);
    glBegin(GL_POLYGON);
    glVertex2d(275,270);
    glVertex2d(275,275);
    glVertex2d(290,275);
    glVertex2d(290,270);
    glEnd();
    glPopMatrix();

    /// left trees
    glPushMatrix();
    glColor3ub(122, 121, 56);
    glBegin(GL_POLYGON);
    glVertex2d(-45,80);
    glVertex2d(-30,80);
    glVertex2d(-25,95);
    glVertex2d(-40,91);
    glVertex2d(-25,115);
    glVertex2d(-40,110);
    glVertex2d(-45,150);
    glEnd();
    glPopMatrix();

    glColor3ub(122, 121, 56);
    glBegin(GL_POLYGON);
    glVertex2d(-45,80);
    glVertex2d(-60,80);
    glVertex2d(-65,95);
    glVertex2d(-50,91);
    glVertex2d(-65,115);
    glVertex2d(-50,110);
    glVertex2d(-45,150);
    glEnd();

    glColor3ub(40, 26, 36);
    glBegin(GL_POLYGON);
    glVertex2d(-47.5,60);
    glVertex2d(-42.5,60);
    glVertex2d(-42.5,80);
    glVertex2d(-47.5,80);
    glEnd();
    /// 2nd tree

    glPushMatrix();
    glColor3ub(122, 121, 56);
    glBegin(GL_POLYGON);
    glVertex2d(-85,80);
    glVertex2d(-70,80);
    glVertex2d(-65,95);
    glVertex2d(-80,91);
    glVertex2d(-65,115);
    glVertex2d(-80,110);
    glVertex2d(-85,150);
    glEnd();
    glPopMatrix();

    glColor3ub(122, 121, 56);
    glBegin(GL_POLYGON);
    glVertex2d(-85,80);
    glVertex2d(-100,80);
    glVertex2d(-105,95);
    glVertex2d(-90,91);
    glVertex2d(-105,115);
    glVertex2d(-90,110);
    glVertex2d(-85,150);
    glEnd();

    glColor3ub(40, 26, 36);
    glBegin(GL_POLYGON);
    glVertex2d(-87.5,60);
    glVertex2d(-82.5,60);
    glVertex2d(-82.5,80);
    glVertex2d(-87.5,80);
    glEnd();
    ///3rd tree

    glPushMatrix();
    glColor3ub(204, 183, 66);
    glBegin(GL_POLYGON);
    glVertex2d(-265,80);
    glVertex2d(-250,80);
    glVertex2d(-245,115);
    glVertex2d(-260,111);
    glVertex2d(-245,145);
    glVertex2d(-260,140);
    glVertex2d(-265,180);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(204, 183, 66);
    glBegin(GL_POLYGON);
    glVertex2d(-265,80);
    glVertex2d(-280,80);
    glVertex2d(-285,115);
    glVertex2d(-270,111);
    glVertex2d(-285,145);
    glVertex2d(-270,140);
    glVertex2d(-265,180);
    glEnd();
    glPopMatrix();

///
    glPushMatrix();
    glColor3ub(122, 121, 56);
    glBegin(GL_POLYGON);
    glVertex2d(-300,80);
    glVertex2d(-280,80);
    glVertex2d(-300,200);
    glEnd();
    glPopMatrix();


    /// LOWER PORTION


    ///Left up
    glPushMatrix();
    glColor3ub(255, 204, 204);
    glBegin(GL_POLYGON);
    glVertex2d(-45,50);
    glVertex2d(-40,60);
    glVertex2d(-300,55);
    glVertex2d(-300,50);
    glEnd();
    glPopMatrix();

    ///Right up
    glPushMatrix();
    glColor3ub(255, 204, 204);
    glBegin(GL_POLYGON);
    glVertex2d(45,50);
    glVertex2d(40,60);
    glVertex2d(300,55);
    glVertex2d(300,50);
    glEnd();
    glPopMatrix();

    ///Left Down
    glPushMatrix();
    glColor3ub(255, 204, 204);
    glBegin(GL_POLYGON);
    glVertex2d(-300,-100);
    glVertex2d(-245,-100);
    glVertex2d(-255,-107);
    glVertex2d(-300,-105);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 204, 204);
    glBegin(GL_POLYGON);
    glVertex2d(-245,-100);
    glVertex2d(-255,-107);
    glVertex2d(-305,-198);
    glVertex2d(-300,-200);
    glEnd();
    glPopMatrix();

    ///Right Down
    glPushMatrix();
    glColor3ub(255, 204, 204);
    glBegin(GL_POLYGON);
    glVertex2d(300,-100);
    glVertex2d(245,-100);
    glVertex2d(255,-107);
    glVertex2d(300,-105);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 204, 204);
    glBegin(GL_POLYGON);
    glVertex2d(245,-100);
    glVertex2d(255,-107);
    glVertex2d(230,-300);
    glVertex2d(225,-300);
    glEnd();
    glPopMatrix();

    ///Left Road
    glPushMatrix();
    glColor3ub(255, 204, 204);
    glBegin(GL_POLYGON);
    glVertex2d(-130,-100);
    glVertex2d(-135,-100);
    glVertex2d(-210,-300);
    glVertex2d(-220,-300);
    glEnd();
    glPopMatrix();

    ///Right Road
    glPushMatrix();
    glColor3ub(255, 204, 204);
    glTranslated(-25,0,0);
    glBegin(GL_POLYGON);
    glVertex2d(185,-100);
    glVertex2d(190,-100);
    glVertex2d(140,-300);
    glVertex2d(150,-300);
    glEnd();
    glPopMatrix();
    ///Divider UP
    glPushMatrix();
    glColor3ub(5, 4, 13);
    glBegin(GL_POLYGON);
    glVertex2d(-300,48);
    glVertex2d(300,48);
    glVertex2d(300,50);
    glVertex2d(-300,50);
    glEnd();
    glPopMatrix();
    ///Divider Down
    glPushMatrix();
    glColor3ub(5, 4, 13);
    glBegin(GL_POLYGON);
    glVertex2d(-300,-98);
    glVertex2d(300,-98);
    glVertex2d(300,-100);
    glVertex2d(-300,-100);
    glEnd();
    glPopMatrix();

    ///Movement

    glPushMatrix();
        glScaled(0.15, 0.3, 0);
        glTranslated(vPos1, 100, 1);
        truck();
    glPopMatrix();

    glPushMatrix();
        glScaled(0.15, 0.3, 0);
        glTranslated(vPos2, 150, 1);
        truck();
    glPopMatrix();

    glPushMatrix();
        glScaled(0.1, 0.2, 0);
        glTranslated(vPos6, 150, 1);
        car();
    glPopMatrix();



    glPushMatrix();
        glScaled(0.18, 0.37, 0);
        glTranslated(vPos3, -80, 1);
        glRotated(180, 0, 1, 0);
        truck();
    glPopMatrix();

    glPushMatrix();
        glScaled(0.12, 0.25, 0);
        glTranslated(vPos4, -120, 1);
        glRotated(180, 0, 1, 0);
        car();
    glPopMatrix();

    glPushMatrix();
        glScaled(0.12, 0.25, 0);
        glTranslated(vPos5, -180, 1);
        glRotated(180, 0, 1, 0);
        car();
    glPopMatrix();



    ///Zebra Crossing

    Zebra(0);
    Zebra(10);
    for(int i=0; i<150; i+=10){
        Zebra(i);
        Zebra(-i);
    }
    ///traffic light
    glPushMatrix();
    glColor3ub(237, 224, 233);
    glBegin(GL_POLYGON);
    glVertex2d(-200,-140);
    glVertex2d(-180,-140);
    glVertex2d(-180,-160);
    glVertex2d(-200,-160);
    glEnd();


    glColor3ub(237, 224, 233);
    glBegin(GL_POLYGON);
    glVertex2d(-187,-140);
    glVertex2d(-187,5);
    glVertex2d(-193,5);
    glVertex2d(-193,-140);
    glEnd();

    glColor3ub(37, 24, 38);
    glBegin(GL_POLYGON);
    glVertex2d(-197,0);
    glVertex2d(-183,0);
    glVertex2d(-183,45);
    glVertex2d(-197,45);
    glEnd();
    glPopMatrix();

    update();
    glFlush();
}
void stop(){
    vSpeed1 = 0.0;
    vSpeed2 = 0.0;
    vSpeed3 = 0.0;
    vSpeed4 = 0.0;
    vSpeed5 = 0.0;
    vSpeed6 = 0.0;
}

void run(){
    vSpeed1 = 2.0;
    vSpeed2 = 3.0;
    vSpeed3 = 1.5;
    vSpeed4 = 3.0;
    vSpeed5 = 4.0;
    vSpeed6 = 2.5;
}

void keyPress(unsigned char key, int x, int y) {
    switch(key){
        case 'r':
        glutIdleFunc(run);
        break;

        case 's':
        glutIdleFunc(stop);
        break;
    }
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Simple Line");
    init();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyPress);
    glutMainLoop();

    return 0;
}


