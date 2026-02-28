#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    // Flag ratio 3:2
    gluOrtho2D(0, 600, 0, 400);

    // make the green background
    glColor3f(0 , 122.0/255.0 , 77.0/255.0);
    glBegin(GL_QUADS);
    glVertex2f(0 , 0);
    glVertex2f(600 , 0);
    glVertex2f(600 , 400);
    glVertex2f(0 , 400);
    glEnd();

    // blue
    glColor3f(0.0, 35.0/255.0, 149.0/255.0);
    glBegin(GL_QUADS);
    glVertex2f(100,   0);
    glVertex2f(600, 0);
    glVertex2f(600, 133);
    glVertex2f(350,   133);
    glEnd();

    // white quad with blue
    glColor3f(1 , 1 , 1);
    glBegin(GL_QUADS);
    glVertex2f(60, 0);
    glVertex2f(100,   0);
    glVertex2f(350, 133);
    glVertex2f(350,   163);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_QUADS);
    glVertex2f(600,   133);
    glVertex2f(600, 163);
    glVertex2f(350, 163);
    glVertex2f(350,   133);
    glEnd();



    // yellow triangle
    glColor3f(255/255.0, 184/255.0, 28/255.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(300, 198);
    glVertex2f(0, 360);
    glVertex2f(0,   53);
    glEnd();

    // black triangle
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 83);
    glVertex2f(0, 330);
    glVertex2f(260, 195);
    glEnd();

    // red  quad
    glColor3f(222/255.0, 56/255.0, 49/255.0);
    glBegin(GL_QUADS);
    glVertex2f(600, 600);
    glVertex2f(600,   267);
    glVertex2f(350, 267);
    glVertex2f(100,   400);
    glEnd();

    // white quad with red
    glColor3f(1 , 1 , 1);
    glBegin(GL_QUADS);
    glVertex2f(600, 237);
    glVertex2f(600, 267);
    glVertex2f(350, 267);
    glVertex2f(350,   237);
    glEnd();


    glColor3f(1 , 1 , 1);
    glBegin(GL_QUADS);
    glVertex2f(350, 237);
    glVertex2f(350, 267);
    glVertex2f(100, 400);
    glVertex2f(55,   400);
    glEnd();


    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(1400, 200);
    glutCreateWindow("South Africa Flag");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

