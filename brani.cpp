#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <math.h>
#define PI 3.14159265
#define GL_SILENCE_DEPRECATION

GLfloat i = 0.0f;

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3ub(109, 189, 119);
    glVertex2f(-1.0, -0.15);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(89, 142, 255);
    glVertex2f(-1.0, -0.15);
    glVertex2f(-1.0, 1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(1.0, -0.15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex2f(0.015, 0.27);
    glVertex2f(0.015, -0.15);
    glVertex2f(-0.015, -0.15);
    glVertex2f(-0.015, 0.27);
    glEnd();

    glLoadIdentity();
    
    glPushMatrix();
    glTranslatef(0.00, 0.27, 0);
    glRotatef(i, 0, 0, 0.1f);

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.15f,-0.10f);
    glVertex2f(0.14f,-0.12f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.01f,0.18f);
    glVertex2f(+0.01f,0.18f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-0.15f,-0.10f);
    glVertex2f(-0.14f,-0.12f);
    glEnd();

    glPopMatrix();

    i -= 1.0f;

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Windmill");
    glutDisplayFunc(display);
    glutIdleFunc(glutPostRedisplay);
    glutMainLoop();
    return 0;
}
