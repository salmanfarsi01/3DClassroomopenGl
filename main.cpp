#include <iostream>
#include<GL/gl.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <bits/stdc++.h>
#include<GL/gl.h>
#include<windows.h>
#include<math.h>


using namespace std;

const int width = 600;
const int height = 800;

GLfloat eyeX =0;
GLfloat eyeY = 10;
GLfloat eyeZ =10;

GLfloat lookX = 0;
GLfloat lookY = 10;
GLfloat lookZ = 0;

static GLfloat v_cube[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},

    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};

static GLubyte c_ind[6][4] =
{
    {0,2,6,4},
    {1,5,7,3},
    {0,4,5,1},
    {2,3,7,6},
    {0,1,3,2},
    {4,6,7,5}
};

static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void cube(float r,float g,float b)
{

    glBegin(GL_QUADS);
    glColor3d(r,g,b);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                    v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                    v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);

        for (GLint j=0; j<4; j++)
        {
            glVertex3fv(&v_cube[c_ind[i][j]][0]);
        }
    }
    glEnd();
}


void desk(){



    glPushMatrix();
    glTranslated(5,3,-30.5);
    glScaled(0.1,3,3);
    cube(.5, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.45,0,0);
    glScaled(0.9,3,0.5);
    cube(0.569, 0.4, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.45,0,0);
    glScaled(0.9,3,0.5);
    glTranslated(4,0,0);
    cube(0.569, 0.4, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.45,0,0);
    glScaled(0.9,3,0.5);
    glTranslated(0,0,3);
    cube(0.569, 0.4, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.45,0,0);
    glScaled(0.9,3,0.5);
    glTranslated(4,0,3);
    cube(0.569, 0.4, 0.2);
    glPopMatrix();

    glPushMatrix();
    glScaled(5.4,0.5,2.5);
    glTranslated(0,6,0);
    cube(0.569, 0.4, 0.2);
    glPopMatrix();

    glPushMatrix(); //monitor
    glScaled(3.1,3.1,.2);
    glTranslated(0.7,1.0,6.0);
    cube(1, 1, 1);
    glPopMatrix();

    glPushMatrix(); //monitor screen
    glScaled(2.9,2.9,.2);
    glTranslated(0.8,1.1,5.9);
    cube(0, 0, 0);
    glPopMatrix();
                    //monitor stand1

                    //monitor stand2

    glPushMatrix(); //keyboard
    glScaled(2.9,.3,0.7);
    glTranslated(0.9,11.5,0.5);
    cube(0.92, 0.92, 0.92);
    glPopMatrix();

}
void chair()
{

    glPushMatrix();
    glTranslated(0.75,0,0);
    glScaled(1.5,2,0.5);
    glTranslated(.5,0,-2);
    cube(1,0.8,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.75,0,0);
    glScaled(1.5,2,0.5);
    glTranslated(3.5,0,-2);
    cube(1,0.8,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.75,0,0);
    glScaled(1.5,2,0.5);
    glTranslated(.5,0,-4);
    cube(1,0.8,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.75,0,0);
    glScaled(1.5,2,0.5);
    glTranslated(3.5,0,-4);
    cube(1,0.8,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.75,0,0);
    glScaled(6,0.33,2);
    glTranslated(0.15,6,-1.2);
    cube(1, 0.84, 0.53);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.75,0,0);
    glScaled(6,0.33,2);
    glTranslated(.15,1,-5);
    cube(1,0.7,0.4);
    glPopMatrix();
}


void full_set()
{
    glPushMatrix();
    desk();
    glPopMatrix();

    glPushMatrix();
    chair();
    glPopMatrix();

}


void full_set_chair_desk()
{
    glPushMatrix();
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslated(5,0,0);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5,0,0);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-10,0,0);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,-6);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslated(5,0,-6);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5,0,-6);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-10,0,-6);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,-12);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslated(5,0,-12);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5,0,-12);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-10,0,-12);
    full_set();
    glPopMatrix();

    glPushMatrix();
    glScaled(-1,1,1);
    glTranslated(7,0,6);
    desk();
    glPopMatrix();

}

void board()
{


    glPopMatrix(); //board border
    glPushMatrix();
    glScaled(16,8,0.1);
    glTranslated(-0.5,.38,130.5);
    cube(0.67, 0.7, 0.7);
    glPopMatrix();

    glPopMatrix(); //board
    glPushMatrix();
    glScaled(14.5,7.5,0.1);
    glTranslated(-0.5,.45,130);
    cube(1,1,1);
    glPopMatrix();



}


void window()

{   glPushMatrix();
    glScaled(0.1,3,3);
    glTranslated(-140,3,-3.5);
    cube(.5, 1, 1);
    glPopMatrix();
     glPushMatrix();
    glScaled(0.1,3,.1);
    glTranslated(-140,3,-16.5);
    cube(0, 0, 0);
    glPopMatrix(); //right shade

    glPushMatrix();
    glScaled(0.1,3,3);
    glTranslated(-140,3,-2);
    cube(.5, 1, 1);
    glPopMatrix();

     glPushMatrix();
    glScaled(0.1,3,.1);
    glTranslated(-140,3,-61.0);
    cube(0, 0, 0);
    glPopMatrix(); //right shade





    glPushMatrix();
    glScaled(0.1,3,3);
    glTranslated(-140,3,-.5);
    cube(.5, 1, 1);
    glPopMatrix();

     glPushMatrix();
    glScaled(0.1,3,.1);
    glTranslated(-140,3,-105.5);
    cube(0, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glScaled(0.1,3,3);
    glTranslated(-140,3,1.0);
    cube(.5, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glScaled(0.1,3,.1);
    glTranslated(-140,3,28.5);
    cube(0, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glScaled(0.1,3,3);
    glTranslated(-140,3,2.5);
    cube(.5, 1, 1);
    glPopMatrix();

     glPushMatrix();
    glScaled(0.1,3,.1);
    glTranslated(-140,3,74);
    cube(0, 0, 0);
    glPopMatrix();


}
void windows()
{
    glPushMatrix();
    window();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,1,0);
    window();
    glPopMatrix();
}

void projector()
{
    glPushMatrix(); //projector
    glScaled(2,.7,1.8);
    glTranslated(-0.43,15,-.4);
    cube(0.278, 0.835, 0.961);
    glPopMatrix();

    glPushMatrix(); //projector stand
    glScaled(.5,3.4,.5);
    glTranslated(0,3.2,0);
    cube(0.071, 0.184, 0.6);
    glPopMatrix();

    glPushMatrix();
    glScaled(.68,.68,.68);
    glTranslated(0,15.45,1);
    cube(0,0,0);
    glPopMatrix();  //eye border

    glPushMatrix();
    glScaled(.60,.60,.60);
    glTranslated(0.05,17.55,1.4);
    cube(256,256,256);
    glPopMatrix(); //eye
}


void AC()
{
    glPushMatrix(); //ac
    glScaled(6.5,2,2);
    glTranslated(-0.5,6,-7.5);
    cube(0.408, 0.643, 0.949);
    glPopMatrix();

    glPushMatrix();  //acborder1
    glScaled(6.5,0.2,0.5);
    glTranslated(-0.5,60.5,-26.5);
    cube(0.49, 0.75, 0.92);
    glPopMatrix();

    glPushMatrix();
    glScaled(6.5,0.2,0.5);
    glTranslated(-0.5,62.5,-26.5);
    cube(0.49, 0.75, 0.92);
    glPopMatrix();               //ac border line2



}
GLfloat bulbColor[3] = {255, 255, 255};  // Initializing white color to a arr
bool bulbOn = true;  // by default on

void bulb() {
    glPushMatrix();
    glScaled(2, 0.5, 0.5);
    glTranslated(0, 10, 0);
    cube(bulbColor[0] * 255, bulbColor[1] * 255, bulbColor[2] * 255);
    glPopMatrix();
}

void on_bulb_set()
{



    glPushMatrix();
    glScaled(1,1,1);
    glTranslated(-5,8.2,-5);
    bulb();
    glPopMatrix();

     glPushMatrix();
    glScaled(1,1,1);
    glTranslated(5,8.2,-5);
    bulb();
    glPopMatrix();

     glPushMatrix();
    glScaled(1,1,1);
    glTranslated(-5,8.2,5);
    bulb();
    glPopMatrix();

     glPushMatrix();
    glScaled(1,1,1);
    glTranslated(5,8.2,5);
    bulb();
    glPopMatrix();

}
void door()
{
    glPushMatrix(); //door
    glScaled(3.8,10,.2);
    glTranslated(2.2,0,-75);
    cube(0.478, 0.141, 0);
    glPopMatrix();

    glPushMatrix(); //door glass
    glScaled(1.5,1,.2);
    glTranslated(6.2,7.5,-73);
    cube(.5, 1, 1);
    glPopMatrix();

    glPushMatrix(); //door handle
    glScaled(0.5,0.5,.2);
    glTranslated(17.5,10.5,-73);
    cube(0.651, 0.651, 0.651);
    glPopMatrix();



}
void floorWallsCeiling()
{

    glPushMatrix();// floor
    glScaled(30,1,30);
    glTranslated(-0.5,-1,-0.5);
    cube(0.878, 0.878, 0.757);
    glPopMatrix();


    glPushMatrix();
    glTranslated(15,7.4,0);
    glScaled(1,15,30);
    glTranslated(-1,-0.5,-0.5);
    cube(1, 0.549, 0); //side wall
    glPopMatrix();

    glPushMatrix();
    glTranslated(-14,7.5,0);
    glScaled(1,15,30);
    glTranslated(-1,-0.5,-0.5);
    cube(1, 0.549, 0); //side wall
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,7.4,15);
    glScaled(30,15,1);
    glTranslated(-0.5,-0.5,-1);
    cube(1, 0.549, 0);
    glPopMatrix();

    glPushMatrix(); //pichoner wall
    glTranslated(0,7.5,15);
    glScaled(30,15,1);
    glTranslated(-0.5,-0.5,-31);
    cube(1, 0.549, 0);
    glPopMatrix();


    glPushMatrix(); //uporer chad
    glTranslated(0,15,0);
    glScaled(30,1,30);
    glTranslated(-0.5,-1,-0.5);
    cube(0.878, 0.878, 0.757);
    glPopMatrix();

}


static void display(void)
{




    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3, 3, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);
    glViewport(0, 0, width, height);


    full_set_chair_desk();

    floorWallsCeiling();

    windows();
    board();

    projector();
    AC();
    on_bulb_set();
    door();
    glFlush();







  glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 'w':
        eyeY=eyeY+0.1;
        break;
    case 's':
        eyeY=eyeY-0.1;
        break;
    case 'd':
        eyeX=eyeX+0.1;
        break;
    case 'a':
        eyeX=eyeX-0.1;
    break;


    case '+':
        eyeZ=eyeZ+0.1;
        break;
    case '-':
        eyeZ=eyeZ-0.1;
        break;
        case '1':
        bulbOn = true;
        bulbColor[0] = 0.0;
        bulbColor[1] = 0.0;
        bulbColor[2] = 0.0;  // Black color
        break;
    case '2':
        bulbOn = true;
        bulbColor[0] = 255;
        bulbColor[1] = 255;
        bulbColor[2] = 255;  // White color
        break;
    case '0':
        bulbOn = false;
        break;



    }

    glutPostRedisplay();
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(300,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("SEU 618");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );



    PlaySound(("C:/song/song.wav"),NULL,SND_ASYNC|SND_LOOP);


    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();


    return 0;
}
