#include <windows.h>
#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

void display(){

     glClearColor(0.5, 0.5, 0.5, 1);
     glClear(GL_COLOR_BUFFER_BIT);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-250 , 250 , -250 , 250);


     // creating lines axis
     glLineWidth(2);
     glBegin(GL_LINES);
     glColor3f(0 , 1 ,0);
     glVertex2f(-250 , 0);
     glVertex2f(250 , 0);
     glVertex2f(0 , 250);
     glVertex2f(0 , -250);
     glEnd();

     // red triangle
     glBegin(GL_TRIANGLES);
     glColor3f(1 , 0 , 0);
     glVertex2f(-170 , 150);
     glVertex2f(-120 , 75);
     glVertex2f(-200 , 75);
     glEnd();

     // triangle at 4th region
     glBegin(GL_TRIANGLES);
     glColor3f(1 , 0.5 , 0);
     glVertex2f(150 , -75);
     glVertex2f(120 , -225);
     glVertex2f(180 , -225);
     glEnd();


     // square
     glBegin(GL_QUADS);
     glColor3f(0 , 1 , 0);
     glVertex2f(-225 , -100);
     glVertex2f(-100 , -100);
     glVertex2f(-100 , -225);
     glVertex2f(-225 , -225);
     glEnd();

     // 1st region
     glBegin(GL_POLYGON);
     glColor3f(1 , 1 , 0);

     glVertex2f(100, 60);
     glVertex2f(150, 60);
     glVertex2f(190, 125);
     glVertex2f(150, 190);
     glVertex2f(100, 190);
     glVertex2f(60, 125);
     glEnd();


     glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000); // Set the window's initial width & height
    glutInitWindowPosition(400, 200);  // Set the window's initial position according to the monitor
    glutCreateWindow("Vertex, Primitive & Color"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}

