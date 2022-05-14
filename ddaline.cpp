//DDA
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#include<cmath>
#define h 1000
#define w 1000
using namespace std;

void init(void){
glClearColor(0.7,0.7,0.7,0.7);
glColor3f(3.0,0.8,0.0);
glLineWidth(5.0);
glPointSize(1.0);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-w/2,w/2,-h/2,h/2);
}


void Line()
{
int x1,y1,x2,y2;
float len,dx,dy,x,y;

cout<<"Enter points for Simple Line:\nx1:";
cin>>x1;
cout<<"y1:";
cin>>y1;
cout<<"x2:";
cin>>x2;
cout<<"y2:";
cin>>y2;

if(abs(x2-x1)>=abs(y2-y1)){
len=abs(x2-x1);
}
else{
len=abs(y2-y1);
}

dx=(x2-x1)/len;
dy=(y2-y1)/len;

x=x1;
y=y1;

glBegin(GL_POINTS);
int i=1;
while(i<=len){

glVertex2i(round(x),round(y));

x=x+dx;
y=y+dy;
i=i+1;
}
glEnd();
glFlush();
}

void DashedLine()
{
int x1,y1,x2,y2;
float len,dx,dy,x,y;

cout<<"Enter points for Dashed Line:\nx1:";
cin>>x1;
cout<<"y1:";
cin>>y1;
cout<<"x2:";
cin>>x2;
cout<<"y2:";
cin>>y2;

if(abs(x2-x1)>=abs(y2-y1)){
len=abs(x2-x1);
}
else{
len=abs(y2-y1);
}

dx=(x2-x1)/len;
dy=(y2-y1)/len;

x=x1;
y=y1;

glBegin(GL_LINES);
glLineWidth(15.0);
glPointSize(10.0);
int i=1;
while(i<=len){
if(i%20==0){
glVertex2i(round(x),round(y));
}
x=x+dx;
y=y+dy;
i=i+1;
}
glEnd();
glFlush();
}

void DottedLine()
{
int x1,y1,x2,y2;
float len,dx,dy,x,y;

cout<<"Enter points for Dotted Line:\nx1:";
cin>>x1;
cout<<"y1:";
cin>>y1;
cout<<"x2:";
cin>>x2;
cout<<"y2:";
cin>>y2;

if(abs(x2-x1)>=abs(y2-y1)){
len=abs(x2-x1);
}
else{
len=abs(y2-y1);
}

dx=(x2-x1)/len;
dy=(y2-y1)/len;

x=x1;
y=y1;

glBegin(GL_POINTS);
int i=1;
while(i<=len){
if(i%10==0){
glVertex2i(round(x),round(y));
}

x=x+dx;
y=y+dy;
i=i+1;
}
glEnd();
glFlush();
}

void boat(float x1,float y1,float x2,float y2)
{
float len,dx,dy,x,y;
//glClear(GL_COLOR_BUFFER_BIT);

if(abs(x2-x1)>=abs(y2-y1)){
len=abs(x2-x1);
}
else{
len=abs(y2-y1);
}

dx=(x2-x1)/len;
dy=(y2-y1)/len;

x=x1;
y=y1;

glBegin(GL_POINTS);
int i=1;
while(i<=len){

glVertex2i(round(x),round(y));

x=x+dx;
y=y+dy;
i=i+1;
}
glEnd();
glFlush();
}


void setpixel(int x,int y){
glColor3f(3.0,8.0,0.0);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
glFlush();
}
void display(void){
glColor3f(1.0f,0.0f,0.0f);
glPointSize(4.0);
for(int i=-w;i<=w;i+=2){
setpixel(i,0);
setpixel(0,i);
}

boat(50,-250,450,-250);
boat(50,-250,150,-400);
boat(150,-400,350,-400);
boat(350,-400,450,-250);
boat(200,-50,200,-250);
boat(200,-50,300,-250);
}

void createMenu(void){
glutAddMenuEntry("1.Simple Line",1);
glutAddMenuEntry("2.Dashed Line",2);
glutAddMenuEntry("3.Dotted Line",3);
glutAddMenuEntry("4.Exit",0);
glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Menu(int choice){
if(choice==1){
Line();
}
if(choice==2){
DashedLine();
}
if(choice==3){
DottedLine();
}
if(choice==0){
exit(0);
}
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(100,350);
glutCreateWindow("Axis Plotting");
glutDisplayFunc(display);
init();
glutCreateMenu(Menu);
createMenu();
glutMainLoop();

return 0;
}
