#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include<math.h>
#include<iostream>
using namespace std;
int w=640,h=480;//width and height of window
int xi,y2;//for particular pixel
float interiorColor[3]={0,0,0};//default interior color of polygon
float fillColor_f[3]={1,0,0};//color to be filled by flood fill
float fillColor_b[3]={0,0,1};//color to be filled by boundary fill
float readPixel[3];//to read the color of active pixel
void setPixel(int x,int y,float fillColor[3])//to plot pixel of particular color
{
    glColor3fv(fillColor);//color array
    glBegin(GL_POINTS);
        glVertex2f(x,y);
    glEnd();
    glFlush();
}
void getPixel(int x, int y, float *color)//to get pixel co-ordinates,color of active pixel
{
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}
int sign(float arg)//for Bresenham's line drawing algorithm
{
    if(arg<0)
        return -1;
    else if(arg==0)
        return 0;
    else
        return 1;
}
void Bre(int X1,int Y1,int X2,int Y2)//used to draw polygon
{
    //step-1
    float dx=abs(X2-X1);
    float dy=abs(Y2-Y1);
    int s1,s2,exc,y,x,i;
    float g,temp;
    x=X1;
    y=Y1;
	s1=sign(X2-X1);
	s2=sign(Y2-Y1);
	//step-2
	glBegin(GL_POINTS);
        if(dy>dx)
        {
            temp=dx;
            dx=dy;
            dy=temp;
            exc=1;
        }
        else
            exc=0;
        g=2*dy-dx;
        i=1;
        //step-3
        while(i<=dx)
        {
            glVertex2d(x,y);
            while(g>=0)
            {
                if(exc==1)
                x=x+s1;
                else
                y=y+s2;
                g=g-2*dx;
            }
            if(exc==1)
                y=y+s2;
            else
                x=x+s1;
            g=g+2*dy;
            i++;
        }
    glEnd();
	glFlush();
}
void display()//to display window
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glLoadIdentity();
    gluOrtho2D(0,640,0,480);
}
void floodFill(int x,int y)//to fill polygon by flood fill method
{
    getPixel(x,y,readPixel);//get active pixel
    //compare interior color and active pixel color
    if((readPixel[0]==interiorColor[0] && readPixel[1]==interiorColor[1] && readPixel[2]==interiorColor[2])||(readPixel[0]==fillColor_b[0] && readPixel[1]==fillColor_b[1] && readPixel[2]==fillColor_b[2]) )
    {
        setPixel(x,y,fillColor_f);//plot pixel of red color
        floodFill(x+1,y);//call function recursively for peripheral points
        floodFill(x,y+1);
        floodFill(x-1,y);
        floodFill(x,y-1);
        glFlush();
    }
}
void boundary_fill(int x, int y)//to fill polygon by Boundary fill method
{
    getPixel(x,y,readPixel);//get active pixel
     //compare interior color and active pixel color
    if((readPixel[0]==fillColor_f[0] && readPixel[1]==fillColor_f[1] && readPixel[2]==fillColor_f[2])||(readPixel[0]==interiorColor[0] && readPixel[1]==interiorColor[1] && readPixel[2]==interiorColor[2]))
    {
        //glColor3f(fillColor_b[0],fillColor_b[1],fillColor_b[2]);
        setPixel(x,y,fillColor_b);//plot pixel of blue color
        boundary_fill(x+1,y);//call function recursively for peripheral points
        boundary_fill(x-1,y);
        boundary_fill(x,y+1);
        boundary_fill(x,y-1);
    }
}
void mouse(int btn,int state,int x,int y)//to select pixel by mouse clicking
{
       if((btn==GLUT_LEFT_BUTTON)&&(state==GLUT_DOWN))//if left click then flood fill
       {
            int xi=x;
            int y2=480-y;
            floodFill(xi,y2);
       }
        if((btn==GLUT_RIGHT_BUTTON)&&(state==GLUT_DOWN))//if right fill then boundary fill
       
            int xi=x;
            int y2=480-y;
            boundary_fill(xi,y2);
       }
}
void menu(int i)//create menu
{
    if(i==0)//for exit
    {
        cout<<"Bye";
        exit(0);
    }
    else if(i==1)//to draw polygon
    {
        //DRAW SMALL SIZE POLYGON USING BRESENHAM'S LINE DRAWING ALGORITHM
        Bre(50,50,50,200);
        Bre(50,200,200,200);
        Bre(200,200,200,50);
        Bre(50,50,200,50);
    }
}
 int main(int argc,char** argv)
  {
       glutInit(&argc,argv);
       glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set display mode
       glutInitWindowSize(w,h);//set window size
       glutCreateWindow("Polygon Filling");//create window
       glutDisplayFunc(display);//call back function
       glutCreateMenu(menu);//create menu
       glutAddMenuEntry("Draw",1);//add entry in menu
       glutAddMenuEntry("Exit",0);//add entry in menu
       glutAttachMenu(GLUT_MIDDLE_BUTTON);//attach menu to middle button of mouse
       glutMouseFunc(mouse);//callback function for mouse interfacing
       glutMainLoop();
       return 0;
  }
