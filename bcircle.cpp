#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#define h1 480
#define w 640
using namespace std;
//h : x-co-ordinate of center
//k : y-co-ordinate of center
//r : radius of circle
int h,k,r;
//for spiral
void plot_half(int x, int y,int i)
{
if(i%2==0)//upper half if even
{
glColor3f(1.0,1.0,1.0);//set white color to circle
glBegin(GL_POINTS);//plot points
glVertex2i(h+x, k+y);
glVertex2i(y+h, x+k);
glVertex2i(-y+h, x+k);
glVertex2i(-x+h, k+y);
glEnd();
}
else//else lower half
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_POINTS);
glVertex2i(h-x, k-y);
glVertex2i(-y+h, -x+k);
glVertex2i(y+h, -x+k);
glVertex2i(h+x, k-y);
glEnd();
}
}
//for normal circle
void plot_point(int x, int y)
{
//according to 8 way symmetry
glColor3f(1.0,1.0,1.0);//set circle color white
glBegin(GL_POINTS);
glVertex2i(h+x, k+y);
glVertex2i(y+h, x+k);
glVertex2i(-y+h, x+k);
glVertex2i(-x+h, k+y);
glVertex2i(h-x, k-y);
glVertex2i(-y+h, -x+k);
glVertex2i(y+h, -x+k);
glVertex2i(h+x, k-y);
glEnd();
}
//for axes drawing
void setpixel(int x,int y)
{
glColor3f(0.0f,1.0f,0.0f);
glBegin(GL_POINTS);//plot points
glVertex2i(x,y);
glEnd();
}
//normal circle
void circle(int r,int h,int k)
{
//step 1
int x=0;
int y=r;
float d = 3-(2*r);
plot_point(x,y);//plot first point
//step 2
while(x <= y)
{
if(d<=0)
{
d=d+(4*x)+6;
x = x + 1;
}
else
{
d = d + 4*(x - y) + 10;
x = x + 1;
y = y - 1;
}
plot_point(x,y);//plotting
}
}
//concentric circle
void concentric(int r,int k,int h)
{
//call simple circle function
circle(r,h,k);
circle(r/2,h,k);
}
//olympic ring
void olympic()
{
//call simple circle function
r=50,h=-120,k=50;
int xin,yin;
glColor3f(1.0f,1.0f,0.0f);
circle(r,h,k);
glColor3f(0.0f,1.0f,0.0f);
xin=h,yin=k;
h=h+2*r+10;
circle(r,h,k);
glColor3f(0.0f,0.0f,1.0f);
h=h+2*r+10;
circle(r,h,k);
glColor3f(0.0f,0.0f,0.0f);
k=yin-r-10;
h = xin+r;
circle(r,h,k);
glColor3f(1.0f,0.0f,0.0f);
h=h+2*r+10;
circle(r,h,k);
}
//for spiral
void draw(int i)
{
int x=0;
int y=r;
float d = 3-(2*r);
while(x <= y)
{
if(d<=0)
{
d=d+(4*x)+6;
x = x + 1;
}
else
{
d = d + 4*(x - y) + 10;
x = x + 1;
y = y - 1;
}
plot_half(x,y,i);//half circle
}
}
//spiral
void spiral()
{
int i;
r=20;
h=-120;
k=50;
//5 rounds of spiral
for(i=0;i<5;i++)
{
draw(i);
if(i%2==0)
{
h+=-r;
}
else
{
h=h+r;
}
r+=10;//increment radius
if(i%2==0)
{
h+=+r;
}
else
{
h=h-r;
}
}
}
void Init()
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(1.0f,1.0f,1.0f,1.0f);
glLineWidth(3.0);
glPointSize(3.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-w/2,w/2,-h1/2,h1/2);
}
//display function
void myDisplay()
{
//display axes
for(int i=-w;i<=w;i+=2)
{
setpixel(i,0);
}
for(int i=-h1;i<=h1;i+=2)
{
setpixel(0,i);
}
glFlush();
}
//menu
void menu(int id)
{
if(id==0)
{
cout<<"bye!";
exit(0);
}
else if(id==1)
{
cout<<"Enter center Co-ordinates:"<<endl;
cout<<"h: ";
cin>>h;
cout<<endl<<"k: ";
cin>>k;
cout<<endl<<"Enter radius 1: ";
cin>>r;
circle(r,h,k);//simple circle
glFlush();
}
else if(id==2)
{
cout<<"Enter center Co-ordinates:"<<endl;
cout<<"h: ";
cin>>h;
cout<<endl<<"k: ";
cin>>k;
cout<<endl<<"Enter radius 1: ";
cin>>r;
concentric(r,h,k);//concentric circle
glFlush();
}
else if(id==3)
{
olympic();//olympic Ring
glFlush();
}
else if(id==4)
{
spiral();//spiral
glFlush();
}
}
int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set display mode
glutInitWindowPosition(0,0);//set window position
glutInitWindowSize(640,480);//set window size
glutCreateWindow("bresenham_circle");
Init();
glutDisplayFunc(myDisplay);
glutCreateMenu(menu);//create menu
glutAddMenuEntry("Simple Circle",1);
glutAddMenuEntry("Concentric Circle",2);
glutAddMenuEntry("Olympic",3);
glutAddMenuEntry("Spiral",4);
glutAddMenuEntry("exit",0);
glutAttachMenu(GLUT_RIGHT_BUTTON);//attach menu to right click
glutMainLoop();
return 0;
}
