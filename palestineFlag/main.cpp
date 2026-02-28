#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    // Flag ratio 2:1, window 600x300
    gluOrtho2D(0, 600, 0, 300);

    // Black  : White : Green = 1 : 1 : 1
    // Black = 300/3 = 100
    // white = 100
    // green = 100

    // green quad
    glColor3f(0.0, 151.0/255.0, 54.0/255.0);
    glBegin(GL_QUADS);
    glVertex2f(0,   0);
    glVertex2f(600, 0);
    glVertex2f(600, 100);
    glVertex2f(0,   100);
    glEnd();

    // white quad
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(0,   100);
    glVertex2f(600, 100);
    glVertex2f(600, 200);
    glVertex2f(0,   200);
    glEnd();

    // black quad
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(0,   200);
    glVertex2f(600, 200);
    glVertex2f(600, 300);
    glVertex2f(0,   300);
    glEnd();

    // red triangle
    glColor3f(238/255.0, 42/255.0, 53/255.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0,0);
    glVertex2f(0,300);
    glVertex2f(250,150);
    glEnd();


    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 300);
    glutInitWindowPosition(400, 200);
    glutCreateWindow("Palestine Flag");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
