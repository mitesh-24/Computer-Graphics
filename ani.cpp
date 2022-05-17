#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;
float inc=0.5;
float angle=135;
void drawCircle(float segments,float radius,float sx,float sy)
{
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<segments;i++)
    {
    	//get the current angle
        float theta=2.0*3.142*float(i)/float(segments); 
        float x=radius*cos(theta);
        float y=radius*sin(theta);
        glVertex2f(x+sx,y+sy);
    }
    glEnd();
}
void draw(float x1,float y1,float angle)
{
    float segments=100;
    float radius=6.0;

    //Drawing Clock main Circle
    glLineWidth(4);
    glColor3f(1,1,0);
    drawCircle(segments,radius,x1,y1);

    //Drawing Minute Line
    glColor3f(1,1,0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x1,(radius/3.0)*2.0);
    glEnd();

    //Drawing Hour Line
  	glColor3f(1,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(radius/3.0,radius/3.0);
    glEnd();
    //Drawing Pendulum Circle
    double radians=angle*3.142/180;
    float x2=(radius*3.4)*cos(radians);
    float y2=(radius*3.4)*sin(radians);
    float radius2=radius/3.0;

    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    //glLineWidth(2);
    drawCircle(segments,radius2,x2,y2);
    glBegin(GL_LINES);
    glVertex2f(x1,-1*(radius)+0.2);
    glVertex2f(x2,y2);
    glEnd();
}
void display()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-10,10,-30);
    glColor3f(1,0,1);
    draw(0,0,angle);
    glutSwapBuffers();
}
//reshape function for reshape call back 
//for the current window
void reshape(int w,int h)  
{
	glMatrixMode (GL_PROJECTION);  
	glLoadIdentity();
	gluPerspective (100, (GLfloat)w / (GLfloat)h, 0.5, 100.0);
	glMatrixMode (GL_MODELVIEW);
}
//Timer function to control pendulum speed
void timer_func(int t) 
{
if(angle>315)
	{
		angle=315;
		inc=-inc;
	}
	if(angle<225)
	{
		angle=225;
		inc=-inc;
	}
    angle += inc;
    
glutPostRedisplay();
glutTimerFunc(10,timer_func,inc);
}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("PENDULUM ANIMATION");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(10,timer_func,inc);
	glutMainLoop();
    return 0;
}
