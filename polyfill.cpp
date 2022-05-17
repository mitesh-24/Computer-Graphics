#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#define h 480
#define w 640
using namespace std;
int xi,y2;
float interiorColor[3] = {0,0,0};
float fillColor_f[3] = {1,0,0};
float fillColor_b[3] = {0,0,1};
float readPixel[3];

void setPixel(int x,int y,float fillColor[3]){
    glColor3fv(fillColor);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

void getPixel(int x,int y,float *color){
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}

int sign(int t){
    if (t>0){
        return 1;
    }
    else if(t < 0){
        return -1;
    }
    else{
        return 0;
    }
}

void floodFill(int x,int y){
    getPixel(x,y,readPixel);

    if((readPixel[0]==interiorColor[0] && readPixel[1]==interiorColor[1]&&readPixel[2]== interiorColor[2] || readPixel[0]==fillColor_b[0] && readPixel[1] && fillColor_b[1] && readPixel[2]==fillColor_b[2])){
        setPixel(x,y,fillColor_f);
        floodFill(x+1,y);
        floodFill(x,y+1);
        floodFill(x-1,y);
        floodFill(x,y-1);
        glFlush();
    }   
}

void boundaryFill(int x,int y){
    getPixel(x,y,readPixel);

    if((readPixel[0]==interiorColor[0] && readPixel[1]==interiorColor[1] && readPixel[2]== interiorColor[2] || readPixel[0]==fillColor_f[0] && readPixel[1] && fillColor_f[1] && readPixel[2]==fillColor_f[2])){
        setPixel(x,y,fillColor_b);
        boundaryFill(x+1,y);
        boundaryFill(x-1,y);
        boundaryFill(x,y+1);
        boundaryFill(x,y-1);
        glFlush();
    }   
}

void display(){
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glColor3f(0.0,1.0,0.0);
    glLoadIdentity();
    gluOrtho2D(0,640,0,480);
}

void mouse(int btn,int state,int x,int y){
    if((btn == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)){
        int xi = x;
        int y2 = 480-y;
        floodFill(xi,y2);
    }
    if((btn == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN)){
        int xi = x;
        int y2 = 480-y;
        boundaryFill(xi,y2);
    }
}

void menu(int choice){
    if (choice == 1){
        glColor3f(1.0f,1.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(50,50);
        glVertex2f(50,200);
        glVertex2f(50,200);
        glVertex2f(200,200);
        glVertex2f(200,200);
        glVertex2f(200,50);
        glVertex2f(200,50);
        glVertex2f(50,50);
        glEnd();
        glFlush();
    }
    else if (choice == 0){
        exit(0);
    }
}

int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(w,h);
    glutInitWindowPosition(100,100);

    glutCreateWindow("POLYGON FILLING");
    glutDisplayFunc(display);
    
    glutCreateMenu(menu);//create menu
    glutAddMenuEntry("Draw",1);//add entry in menu
    glutAddMenuEntry("Exit",0);//add entry in menu
    glutAttachMenu(GLUT_MIDDLE_BUTTON);//attach menu to middle button of mouse
    glutMouseFunc(mouse);//callback function for mouse interfacing
    glutMainLoop();
    return 0;
}
