#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    // Flag ratio 11:8, window 550x400
    gluOrtho2D(0, 550, 0, 400);


    // RED background
    glColor3f(186.0f/255, 12.0f/255, 47.0f/255);
    glBegin(GL_QUADS);
    glVertex2f(0,   0);
    glVertex2f(550, 0);
    glVertex2f(550, 400);
    glVertex2f(0,   400);
    glEnd();

    // WHITE cross

    // Vertical white quad
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(125, 0);
    glVertex2f(325, 0);
    glVertex2f(325, 400);
    glVertex2f(125, 400);
    glEnd();
    // Horizontal white quad
    glBegin(GL_QUADS);
    glVertex2f(0,   125);
    glVertex2f(550, 125);
    glVertex2f(550, 275);
    glVertex2f(0,   275);
    glEnd();

    // BLUE cross

    // Vertical blue quad
    glColor3f(0.0f/255, 32.0f/255, 91.0f/255);
    glBegin(GL_QUADS);
    glVertex2f(150, 0);
    glVertex2f(300, 0);
    glVertex2f(300, 400);
    glVertex2f(150, 400);
    glEnd();
    // Horizontal blue quad
    glBegin(GL_QUADS);
    glVertex2f(0,   150);
    glVertex2f(550, 150);
    glVertex2f(550, 250);
    glVertex2f(0,   250);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(550, 400);
    glutInitWindowPosition(400, 200);
    glutCreateWindow("Norway Flag");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
