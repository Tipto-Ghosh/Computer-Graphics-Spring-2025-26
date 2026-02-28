#include <GL/glut.h>
#include <cmath>


#define RED_R 210.0/255.0
#define RED_G 16.0/255.0
#define RED_B 52.0/255.0

#define GREEN_R 0.0/255.0
#define GREEN_G 106.0/255.0
#define GREEN_B 78.0/255.0

#define YELLOW_R 255.0/255.0
#define YELLOW_G 206.0/255.0
#define YELLOW_B 0.0/255.0

#define WHITE_R 1.0
#define WHITE_G 1.0
#define WHITE_B 1.0

const int WIDTH = 800;
const int HEIGHT = 480; // Approximate 3:5 ratio

void drawStar(float centerX, float centerY, float innerRadius, float outerRadius, int points) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY);
    for (int i = 0; i <= 2 * points; ++i) {
        float angle = M_PI * i / points;
        float r = (i % 2 == 0) ? outerRadius : innerRadius;
        glVertex2f(centerX + r * cos(angle), centerY + r * sin(angle));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set up orthographic projection to use coordinates from 0 to 5 for width, and 0 to 3 for height
    gluOrtho2D(0.0, 5.0, 0.0, 3.0);

    // Draw the five horizontal stripes
    float stripeHeight = 3.0 / 5.0;

    // Stripe 1 (Green)
    glColor3f(GREEN_R, GREEN_G, GREEN_B);
    glRectf(0.0, 4.0 * stripeHeight, 5.0, 5.0 * stripeHeight);
    // Stripe 2 (Yellow)
    glColor3f(YELLOW_R, YELLOW_G, YELLOW_B);
    glRectf(0.0, 3.0 * stripeHeight, 5.0, 4.0 * stripeHeight);
    // Stripe 3 (Green)
    glColor3f(GREEN_R, GREEN_G, GREEN_B);
    glRectf(0.0, 2.0 * stripeHeight, 5.0, 3.0 * stripeHeight);
    // Stripe 4 (Yellow)
    glColor3f(YELLOW_R, YELLOW_G, YELLOW_B);
    glRectf(0.0, 1.0 * stripeHeight, 5.0, 2.0 * stripeHeight);
    // Stripe 5 (Green)
    glColor3f(GREEN_R, GREEN_G, GREEN_B);
    glRectf(0.0, 0.0, 5.0, 1.0 * stripeHeight);


    // Draw the red canton (a square with side length 3/5 of total height, positioned in the top-left)
    float cantonSize = 3.0 / 5.0 * 3.0; // The canton is a square
    glColor3f(RED_R, RED_G, RED_B);
    glRectf(0.0, 3.0 - cantonSize, cantonSize, 3.0);

    // Draw the white star in the center of the canton
    glColor3f(WHITE_R, WHITE_G, WHITE_B);
    float starCenterX = cantonSize / 2.0;
    float starCenterY = 3.0 - cantonSize / 2.0;
    float outerRadius = stripeHeight * 0.4; // Adjust star size as needed
    float innerRadius = outerRadius / 2.5; // Standard star inner radius ratio
    drawStar(starCenterX, starCenterY, innerRadius, outerRadius, 5);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Togo Flag");
    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutMainLoop();
    return 0;
}
