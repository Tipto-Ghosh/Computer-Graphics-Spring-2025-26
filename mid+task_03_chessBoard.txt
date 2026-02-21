#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void chessBoard();

void display() {
    glClearColor(0.361, 0.361, 0.357, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 400, 0, 400);
    chessBoard();
    glFlush();
}

void chessBoard() {
    bool isBlack = true;

    for (int y = 0; y < 400; y += 50) {
        for (int x = 0; x < 400; x += 50) {
            glBegin(GL_QUADS);
            if (isBlack) {
                glColor3f(0, 0, 0);
            } else {
                glColor3f(1, 1, 1);
            }
            glVertex2f(x, y);
            glVertex2f(x + 50, y);
            glVertex2f(x + 50, y + 50);
            glVertex2f(x, y + 50);
            glEnd();

            isBlack = !isBlack; // invert after each column
        }
        isBlack = !isBlack; // invert at the end of each row
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(500, 170);
    glutCreateWindow("Chess Board");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
