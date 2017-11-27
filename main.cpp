#include <stdlib.h>
#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>



float l=200.0; //square side length


int draw1(float x,float y,float l); // direction 1
int draw2(float x,float y,float l); // direction 2
int draw3(float x,float y,float l); // direction 3
int draw4(float x,float y,float l); // direction 4



void drawBitmapText(char *string,float r,float s)
{
    char *z;
    glRasterPos2f(r,s);

    for(z=string; *z !='\0';z++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*z);
    }
}


void display()
{
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glColor3f(0,0,0);
  drawBitmapText("Fractals Generation -SQUARE",40,850);
  drawBitmapText("Name- Udit Singh Guleria",40,30);
  drawBitmapText("Batch- B.tech CCVT Sem V- B4 ",40,15);
  drawBitmapText("Roll No. - 136",40,5);



}

int draw1(float x,float y,float l)
{

     glColor4f(1,0.498039,0,1);
     glBegin(GL_POLYGON);
     glVertex2f(x,y);
     glVertex2f(x+l,y);
     glVertex2f(x+l,y+l);
     glVertex2f(x,y+l);
     glEnd();
     glFlush();



     printf(" l is= %.3f \n\n",l);
     if(l<1)
        {

            printf("Returned");
            return 0;
        }
     draw1(x+l,y+l,l/2 );
    draw2(x,y+l,l/2);
  //   draw3(x-l,y-l,l/2); //not needed
    draw4(x+l,y,l/2);


}


int draw2(float x,float y,float l)
{

     glColor4f(0.6,0.196078,0.8,1);


     glBegin(GL_POLYGON);
     glVertex2f(x,y);
     glVertex2f(x,y+l);
     glVertex2f(x-l,y+l);
     glVertex2f(x-l,y);
     glEnd();
        glFlush();



     printf(" l is= %.3f \n\n",l);
     if(l<1)
        {

            printf("Returned");
            return 0;
        }
     draw1(x,y+l,l/2);
     draw2(x-l,y+l,l/2);
     draw3(x-l,y,l/2);
     //draw4(x+l,y-l,l/2); //not needed




}
int draw3(float x,float y,float l)
{

     glColor4f(.678431,0.917647,0.917647,1);


     glBegin(GL_POLYGON);
     glVertex2f(x,y);
     glVertex2f(x-l,y);
     glVertex2f(x-l,y-l);
     glVertex2f(x,y-l);
     glEnd();
        glFlush();



     printf(" l is= %.3f \n\n",l);
     if(l<1)
        {

            printf("Returned");
            return 0;
        }
   //  draw1(x+l,y+l,l/2); //not needed
     draw2(x-l,y,l/2);
     draw3(x-l,y-l,l/2);
     draw4(x,y-l,l/2);




}
int draw4(float x,float y,float l)
{

     glColor4f(.82,.57,.46,1);


     glBegin(GL_POLYGON);
     glVertex2f(x,y);
     glVertex2f(x+l,y);
     glVertex2f(x+l,y-l);
     glVertex2f(x,y-l);
     glEnd();
        glFlush();



     printf(" l is= %.3f \n\n",l);
     if(l<1)
        {

            printf("Returned");
            return 0;
        }
    draw1(x+l,y,l/2);
    // draw2(x-l,y+l,l/2); //not needed
    draw3(x,y-l,l/2);
    draw4(x+l,y-l,l/2);



}

void mousefunc(int button, int state, int a, int b)
{

     if (button == GLUT_LEFT_BUTTON &&state==GLUT_DOWN)
        {


     //glColor4f(.85,.85,.10,1);
     glBegin(GL_POLYGON); // drawing the centre Square
     glColor4f(.678431,0.917647,0.917647,1);
     glVertex2f(350,350);
     glColor4f(.82,.57,.46,1);
     glVertex2f(550,350);
     glColor4f(1,0.498039,0,1);
     glVertex2f(550,550);
     glColor4f(0.6,0.196078,0.8,1);
     glVertex2f(350,550);
     glEnd();
     glFlush();

     draw1(550,550,l/2);
     draw2(350,550,l/2);
     draw3(350,350,l/2);
     draw4(550,350,l/2);

}

}


void myinit()
{
    glViewport(0,0,900,900);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)900,0.0,(GLdouble)900);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
   glutInit(&argc,argv);
   int mode=GLUT_RGB|GLUT_SINGLE;
   glutInitDisplayMode(mode);
   glutInitWindowSize(900,900);

   glutCreateWindow("FRACTAL GENERATION");
   myinit();
   glutDisplayFunc(display);
   glutMouseFunc(mousefunc);
   printf("Click to generate the fractal. \n\n");

   glutMainLoop();
   return 0;
}
