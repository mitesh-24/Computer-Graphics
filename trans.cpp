#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include <math.h>
#include<iostream>
#define h 1000 //define height and width
#define w 1000
using namespace std;
int tx,ty; //for translation
double sx,sy;//for scaling
int shx,shy;//for shearing
double theta,alpha; //for rotation
int p[3][3]={{100,150,200},{100,250,100},{1,1,1}};
void myInit(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(1.0,1.0,1.0,1.0);//set white color to window
glLineWidth(3.0);//set point size=6
glPointSize(3.0);
glMatrixMode(GL_PROJECTION);//set projection mode
glLoadIdentity();//load identity matrix
gluOrtho2D(-w/2,w/2,-h/2,h/2);//divide screen in four quadrants
}
void setpixel(int x,int y)//to draw axes
{
glColor3f(0.0,1.0,0.0);//green axes color
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
void drawpoly() //used to draw polygon
{
glBegin(GL_POLYGON);
glColor3f(1.0,0.0,0.0); //set red color
glVertex2i(p[0][0],p[1][0]);
glVertex2i(p[0][1],p[1][1]);
glVertex2i(p[0][2],p[1][2]);
glEnd();
glFlush();
}
void translate(int tx,int ty) //Translate object from its original position
{
int t[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};
int trans[3][3];
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
trans[i][j]=0;
for(int k=0;k<3;k++){
trans[i][j]+=t[i][k]*p[k][j];
}
}
}
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);//set the blue color
glVertex2i(trans[0][0],trans[1][0]);
glVertex2i(trans[0][1],trans[1][1]);
glVertex2i(trans[0][2],trans[1][2]);
glEnd();
glFlush();
}
void scaling(double sx,double sy,int tx,int ty)//Scaling of objects
{
double sc[3][3] ={{sx,0,0},{0,sy,0},{0,0,1}};
int t[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};
int t1[3][3]={{1,0,-tx},{0,1,-ty},{0,0,1}};
float a[3][3];
float b[3][3];
float scale[3][3];
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
a[i][j]=0;
for(int k=0;k<3;k++){
a[i][j]+=t[i][k]*sc[k][j];
}
}
}
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
b[i][j]=0;
for(int k=0;k<3;k++){
b[i][j]+=a[i][k]*t1[k][j];
}
}
}
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
scale[i][j]=0;
for(int k=0;k<3;k++){
scale[i][j]+=b[i][k]*p[k][j];
}
}
}
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);//set the blue color
glVertex2i(scale[0][0],scale[1][0]);
glVertex2i(scale[0][1],scale[1][1]);
glVertex2i(scale[0][2],scale[1][2]);
glEnd();
glFlush();
}
void anti_rot(double theta)//anticlockwise Rotation
{
float rot[3][3]={{cos(theta),-sin(theta),0},{sin(theta),cos(theta),0},{0,0,1}};
double anti[3][3];
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
anti[i][j]=0;
for(int k=0;k<3;k++){
anti[i][j]+=rot[i][k]*p[k][j];
}
}
}
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);//set the blue color
glVertex2i(anti[0][0],anti[1][0]);
glVertex2i(anti[0][1],anti[1][1]);
glVertex2i(anti[0][2],anti[1][2]);
glEnd();
glFlush();
}
void clock_rot(double theta)//Clockwise Rotation
{
float rot[3][3]={{cos(theta),sin(theta),0},{-sin(theta),cos(theta),0},{0,0,1}};
double clock[3][3];
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
clock[i][j]=0;
for(int k=0;k<3;k++){
clock[i][j]+=rot[i][k]*p[k][j];
}
}
}
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);//set the blue color
glVertex2i(clock[0][0],clock[1][0]);
glVertex2i(clock[0][1],clock[1][1]);
glVertex2i(clock[0][2],clock[1][2]);
glEnd();
glFlush();
}
void pivot_rot(int tx,int ty,double theta)//rotation about fixed point
{
float rot[3][3]={{cos(theta),-sin(theta),0},{sin(theta),cos(theta),0},{0,0,1}};
int t[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};
int y[3][3]={{1,0,-tx},{0,1,-ty},{0,0,1}};
float a[3][3];
float b[3][3];
float c[3][3];
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
a[i][j]=0.0;
for(int k=0;k<3;k++){
a[i][j]+=t[i][k]*rot[k][j];
}
}
}
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
b[i][j]=0.0;
for(int k=0;k<3;k++){
b[i][j]+=a[i][k]*y[k][j];
}
}
}
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
c[i][j]=0.0;
for(int k=0;k<3;k++){
c[i][j]+=b[i][k]*p[k][j];
}
}
}
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);//set the blue color
glVertex2i(c[0][0],c[1][0]);
glVertex2i(c[0][1],c[1][1]);
glVertex2i(c[0][2],c[1][2]);
glEnd();
glFlush();
}
void ref_x()//reflection about x axis
{
int r[3][3]={{1,0,0},{0,-1,0},{0,0,1}};
int r_x[3][3];
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
r_x[i][j]=0;
for(int k=0;k<3;k++){
r_x[i][j]+=r[i][k]*p[k][j];
}
}
}
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);//set the blue color
glVertex2i(r_x[0][0],r_x[1][0]);
glVertex2i(r_x[0][1],r_x[1][1]);
glVertex2i(r_x[0][2],r_x[1][2]);
glEnd();
glFlush();
}
void ref_y()//reflection about y axis
{
int r[3][3]={{-1,0,0},{0,1,0},{0,0,1}};
int r_y[3][3];
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
r_y[i][j]=0;
for(int k=0;k<3;k++){
r_y[i][j]+=r[i][k]*p[k][j];
}
}
}
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);//set the blue color
glVertex2i(r_y[0][0],r_y[1][0]);
glVertex2i(r_y[0][1],r_y[1][1]);
glVertex2i(r_y[0][2],r_y[1][2]);
glEnd();
glFlush();
}
void ref_xy()//reflection about xy axis
{
int r[3][3]={{-1,0,0},{0,-1,0},{0,0,1}};
int r_xy[3][3];
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
r_xy[i][j]=0;
for(int k=0;k<3;k++){
r_xy[i][j]+=r[i][k]*p[k][j];
}
}
}
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);//set the blue color
glVertex2i(r_xy[0][0],r_xy[1][0]);
glVertex2i(r_xy[0][1],r_xy[1][1]);
glVertex2i(r_xy[0][2],r_xy[1][2]);
glEnd();
glFlush();
}
void shear_x(int shx)//shearing about x axis
{
int s[3][3]={{1,shx,0},{0,1,0},{0,0,1}};
int s_x[3][3];
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
s_x[i][j]=0;
for(int k=0;k<3;k++){
s_x[i][j]+=p[i][k]*s[k][j];
}
}
}
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);//set the blue color
glVertex2i(s_x[0][0],s_x[1][0]);
glVertex2i(s_x[0][1],s_x[1][1]);
glVertex2i(s_x[0][2],s_x[1][2]);
glEnd();
glFlush();
}
void shear_y(int shy)//shearing about y axis
{
int s[3][3]={{1,0,0},{shy,1,0},{0,0,1}};
int s_y[3][3];
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
s_y[i][j]=0;
for(int k=0;k<3;k++){
s_y[i][j]+=p[i][k]*s[k][j];
}
}
}
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,1.0);//set the blue color
glVertex2i(s_y[0][0],s_y[1][0]);
glVertex2i(s_y[0][1],s_y[1][1]);
glVertex2i(s_y[0][2],s_y[1][2]);
glEnd();
glFlush();
}
void myDisplay(void){//display axes
for(int i=-w;i<=w;i+=2){
setpixel(i,0);
}
for(int i=-h;i<=h;i+=2){
setpixel(0,i);
}
glFlush();
}
void menu(int index){
if(index==0){
cout<<"Bye";
exit(0);
}
else if(index==1){
drawpoly();
glFlush();
}
else if(index==2){
cout<<"Translation\nEnter tx:";
cin>>tx;
cout<<"Enter ty:";
cin>>ty;
drawpoly();
translate(tx,ty);
glFlush();
}
else if(index==3){
cout<<endl<<"Scaling\nEnter sx:";
cin>>sx;
cout<<"Enter sy:";
cin>>sy;
cout<<"Enter tx:";
cin>>tx;
cout<<"Enter ty:";
cin>>ty;
drawpoly();
scaling(sx,sy,tx,ty);
glFlush();
}
else if(index==4){
cout<<"Anticlockwise Rotation\nEnter angle in rad:";
cin>>theta;
drawpoly();
anti_rot(theta);
}
else if(index==5){
cout<<"Clockwise Rotation\nEnter angle in rad:";
cin>>alpha;
drawpoly();
clock_rot(alpha);
}
else if(index==6){
cout<<"Rotation about pivot point\nEnter angle in rad:";
cin>>theta;
cout<<"Enter tx:";
cin>>tx;
cout<<"Enter ty:";
cin>>ty;
drawpoly();
pivot_rot(tx,ty,theta);
}
else if(index==7){
drawpoly();
ref_x();
}
else if(index==8){
drawpoly();
ref_y();
}
else if(index==9){
drawpoly();
ref_xy();
}
else if(index==10){
cout<<"Shearing about x axis\nEnter shx:";
cin>>shx;
drawpoly();
shear_x(shx);
}
else if(index==11){
cout<<"Shearing about y axis\nEnter shy:";
cin>>shy;
drawpoly();
shear_y(shy);
}
}
int main(int argc,char**argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set the display mode
glutInitWindowSize(640,480);//set window size
glutInitWindowPosition(300,150);//set window position
glutCreateWindow("TRANSFORMATIONS"); //create window
glClearColor(1.0,1.0,1.0,0.0);//set white color to window
glutDisplayFunc(myDisplay);//call back function
myInit();
glutCreateMenu(menu);//create menu
glutAddMenuEntry("1.Draw Object",1);
glutAddMenuEntry("2.Translation",2);
glutAddMenuEntry("3.Scaling",3);
glutAddMenuEntry("4.Anticlockwise Rotation",4);
glutAddMenuEntry("5.Clockwise Rotation",5);
glutAddMenuEntry("6.Rotation about pivot point",6);
glutAddMenuEntry("7.Reflection about x axis",7);
glutAddMenuEntry("8.Reflection about y axis",8);
glutAddMenuEntry("9.Reflection about xy axis",9);
glutAddMenuEntry("10.Shearing about x axis",10);
glutAddMenuEntry("11.Shearing about y axis",11);
glutAddMenuEntry("0.Exit",0);
glutAttachMenu(GLUT_RIGHT_BUTTON);//attach menu to right button
glutMainLoop();
return 0;
}
