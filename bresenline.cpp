#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#define h 480
#define w 640
using namespace std;
int x1,y1,x2,y2;//initialize global variable
void myInit (void)
{
glClear(GL_COLOR_BUFFER_BIT);//clear the screen
glClearColor(1.0f,1.0f,1.0f,1.0f);//set black color for window
glLineWidth(3.0);
glPointSize(3.0);
glMatrixMode(GL_PROJECTION);//pojection mode
glLoadIdentity();//load identity matrix
gluOrtho2D(-w/2,w/2,-h/2,h/2);//quadrant display
}
void setpixel(int x,int y)//for axes drawing
{
glColor3f(0.0f,1.0f,0.0f);//axes color green
glBegin(GL_POINTS);//plot points
glVertex2i(x,y);
glEnd();
}
int sign(int t)//to decide sign of dx & dy
{
if(t>0)
{
return 1;
}
else if(t<0)
{
return -1;
}
else
{
return 0;
}
}
//simple line
void simple_line(int x1,int y1,int x2,int y2)
{
//take co-ordinates
cout<<"Enter x1 :";
cin>>x1;
cout<<"Enter y1 :";
cin>>y1;
//validation
while(1)
{
cout<<"Enter x2 :";
cin>>x2;
if(x2!=x1)
break;
else
cout<<"x1 should not be equal to x2";
}
while(1)
{
cout<<"Enter y2 :";
cin>>y2;
if(y2!=y1)
break;
else
cout<<"y1 should not be equal to y2";
}
//step 1
int interchange;
int x=x1;
int y=y1;
int dx=x2-x1;
int dy=y2-y1;
int s1=sign(dx);
int s2=sign(dy);
//step 2
//Interchange dx & dy depending on slope
if(dy>dx)
{
int temp = dx;
dx=dy;
dy=temp;
interchange = 1;
}
else
{
interchange=0;
}
//step 3
//initialize error term
int e =2*abs(dy)-abs(dx);
glBegin(GL_POINTS);
glColor3f(1.0f,0.0f,0.0f);//line color red
glVertex2i(x,y);
glEnd();
for(int i=1;i<=dx;i++)
{
glBegin(GL_POINTS);//plot points
glColor3f(1.0f,0.0f,0.0f);
glVertex2i(x,y);
glEnd();
while(e>=0)
{
if(interchange==1)
{
x+=s1;
}
else
{
y+=s2;
}
e=e-2*abs(dx);
}
if(interchange==1)
{
y+=s2;
}
else
{
x+=s1;
}
e=e+2*abs(dy);
}
glFlush();//to display on screen
}
//dotted line
void dotted_line(int x1,int y1,int x2,int y2)
{
cout<<"Enter x1 :";
cin>>x1;
cout<<"Enter y1 :";
cin>>y1;
while(1)
{
cout<<"Enter x2 :";
cin>>x2;
if(x2!=x1)
break;
else
cout<<"x1 should not be equal to x2";
}
while(1)
{
cout<<"Enter y2 :";
cin>>y2;
if(y2!=y1)
break;
else
cout<<"y1 should not be equal to y2";
}
int interchange;
int x=x1;
int y=y1;
int dx=x2-x1;
int dy=y2-y1;
int s1=sign(dx);
int s2=sign(dy);
if(dy>dx)
{
int temp = dx;
dx=dy;
dy=temp;
interchange = 1;
}
else
{
interchange=0;
}
int e =2*abs(dy)-abs(dx);
glBegin(GL_POINTS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2i(x,y);
glEnd();
for(int i=1;i<=dx;i++)
{
if(i%4==0)//condition for dotted line
{
glBegin(GL_POINTS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2i(x,y);
glEnd();
}
while(e>=0)
{
if(interchange==1)
{
x+=s1;
}
else
{
y+=s2;
}
e=e-2*abs(dx);
}
if(interchange==1)
{
y+=s2;
}
else
{
x+=s1;
}
e=e+2*abs(dy);
}
glFlush();
}
//dashed line
void dashed_line(int x1,int y1,int x2,int y2)
{
cout<<"Enter x1 :";
cin>>x1;
cout<<"Enter y1 :";
cin>>y1;
while(1)
{
cout<<"Enter x2 :";
cin>>x2;
if(x2!=x1)
break;
else
cout<<"x1 should not be equal to x2";
}
while(1)
{
cout<<"Enter y2 :";
cin>>y2;
if(y2!=y1)
break;
else
cout<<"y1 should not be equal to y2";
}
int interchange;
int x=x1;
int y=y1;
int dx=x2-x1;
int dy=y2-y1;
int s1=sign(dx);
int s2=sign(dy);
if(dy>dx)
{
int temp = dx;
dx=dy;
dy=temp;
interchange = 1;
}
else
{
interchange=0;
}
int e =2*abs(dy)-abs(dx);
glBegin(GL_POINTS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2i(x,y);
glEnd();
for(int i=1;i<=dx;i++)//condition for dashed line
{
if(i%10>=4)
{
glBegin(GL_POINTS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2i(x,y);
glEnd();
}
while(e>=0)
{
if(interchange==1)
{
x+=s1;
}
else
{
y+=s2;
}
e=e-2*abs(dx);
}
if(interchange==1)
{
y+=s2;
}
else
{
x+=s1;
}
e=e+2*abs(dy);
}
glFlush();
}
//dash-dot line
void dot_dash_line(int x1,int y1,int x2,int y2)
{
cout<<"Enter x1 :";
cin>>x1;
cout<<"Enter y1 :";
cin>>y1;
while(1)
{
cout<<"Enter x2 :";
cin>>x2;
if(x2!=x1)
break;
else
cout<<"x1 should not be equal to x2";
}
while(1)
{
cout<<"Enter y2 :";
cin>>y2;
if(y2!=y1)
break;
else
cout<<"y1 should not be equal to y2";
}
int interchange;
int x=x1;
int y=y1;
int dx=x2-x1;
int dy=y2-y1;
int s1=sign(dx);
int s2=sign(dy);
if(dy>dx)
{
int temp = dx;
dx=dy;
dy=temp;
interchange = 1;
}
else
{
interchange=0;
}
int e =2*abs(dy)-abs(dx);
glBegin(GL_POINTS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2i(x,y);
glEnd();
for(int i=1;i<=dx;i++)
{
if((i%10>=5) || (i%4==0))//condition for dash-dot line
{
glBegin(GL_POINTS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2i(x,y);
glEnd();
}
while(e>=0)
{
if(interchange==1)
{
x+=s1;
}
else
{
y+=s2;
}
e=e-2*abs(dx);
}
if(interchange==1)
{
y+=s2;
}
else
{
x+=s1;
}
e=e+2*abs(dy);
}
glFlush();
}
//Pattern drawing
void pattern(int x1,int y1,int x2,int y2)
{
//simple line algorithm
int interchange;
int x=x1;
int y=y1;
int dx=(x2-x1);
int dy=(y2-y1);
int s1=sign(dx);
int s2=sign(dy);
if(dy>dx)
{
int temp = dx;
dx=dy;
dy=temp;
interchange = 1;
}
else
{
interchange=0;
}
int e =2*abs(dy)-abs(dx);
glBegin(GL_POINTS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2i(x,y);
glEnd();
for(int i=1;i<=dx;i++)
{
glBegin(GL_POINTS);
glColor3f(1.0f,0.0f,0.0f);
glVertex2i(x,y);
glEnd();
while(e>=0)
{
if(interchange==1)
{
x+=s1;
}
else
{
y+=s2;
}
e=e-2*abs(dx);
}
if(interchange==1)
{
y+=s2;
}
else
{
x+=s1;
}
e=e+2*abs(dy);
}
glFlush();
}
//display function
void myDisplay()
{
//displaying axes
for(int i=-w;i<=w;i+=2)
{
setpixel(i,0);
}
for(int i=-h;i<=h;i+=2)
{
setpixel(0,i);
}
glFlush();
}
//Menu creation
void menu(int id)
{
if(id==0)
{
cout<<"bye!";
exit(0);
}
else if(id==1)
{
cout<<"__For Simple Line__"<<endl;
simple_line(x1,y1,x2,y2);//simple line
}
else if(id==2)
{
cout<<"__For Dotted Line__"<<endl;
dotted_line(x1,y1,x2,y2);//dotted line
}
else if(id==3)
{
cout<<"__For Dashed Line__"<<endl;
dashed_line(x1,y1,x2,y2);//dashed line
}
else if(id==4)
{
cout<<"__For Dashed-Dotted Line__"<<endl;
dot_dash_line(x1,y1,x2,y2);//dashed line
}
else if(id==5)
{
//pattern
pattern(-100,-70,100,-70);
pattern(-100,70,100,70);
pattern(-100,-70,-100,70);
pattern(100,-70,100,70);
pattern(-100,0,0,70);
pattern(100,0,0,70);
pattern(0,-70,100,0);
pattern(-100,0,0,-70);
pattern(-50,-35,-50,35);
pattern(50,-35,50,35);
pattern(-50,35,50,35);
pattern(-50,-35,50,-35);
}
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set display mode
glutInitWindowSize(800,700);//set window size
glutInitWindowPosition(300,300);//set window position
glutCreateWindow("LINE");//create window
glutDisplayFunc(myDisplay);
myInit();
glutCreateMenu(menu);//create window
glutAddMenuEntry("Simple Line",1);
glutAddMenuEntry("Dotted Line",2);
glutAddMenuEntry("Dashed Line",3);
glutAddMenuEntry("Dotted & Dashed Line",4);
glutAddMenuEntry("Pattern",5);
glutAddMenuEntry("exit",0);
glutAttachMenu(GLUT_RIGHT_BUTTON);//attach menu to right click
glutMainLoop();
return 0;
}
