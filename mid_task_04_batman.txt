#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void lines();
void boxes();

void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    gluOrtho2D(0, 660, 0, 520);

    boxes();
    lines(); // pink grid drawn on top as a planning/debug reference tool

    glFlush();
}

void boxes() {

    // =========================================================
    // STEP 3: OUTER BORDER — Top and Bottom black/yellow rows
    // The logo is framed by 2 rows on top and 2 rows on bottom:
    //   rowNumber 0  → Black (outermost bottom)
    //   rowNumber 1  → Yellow (inner bottom)
    //   rowNumber 19 → Yellow (inner top)
    //   rowNumber 20 → Black (outermost top)
    // x spans from 160 to 480 (horizontal center of logo)
    // =========================================================
    for (int y = 40; y <= 460; y += 20) {
        int rowNumber = (y - 40) / 20; // 0-based row index from bottom
        for (int x = 160; x <= 480; x += 20) {

            if (rowNumber == 0 || rowNumber == 1 || rowNumber == 20 || rowNumber == 19) {
                glBegin(GL_QUADS);

                if (rowNumber == 0) {
                    glColor3f(0, 0, 0);        // Black — outermost bottom border
                }
                else if (rowNumber == 1) {
                    glColor3f(0.969, 0.91, 0); // Yellow — inner bottom border
                }
                else if (rowNumber == 19) {
                    glColor3f(0.969, 0.91, 0); // Yellow — inner top border
                }
                else if (rowNumber == 20) {
                    glColor3f(0, 0, 0);        // Black — outermost top border
                }

                glVertex2f(x, y);
                glVertex2f(x + 20, y);
                glVertex2f(x + 20, y + 20);
                glVertex2f(x, y + 20);
                glEnd();
            }
        }
    }


    // =========================================================
    // STEP 3: OUTER BORDER — Left and Right black/yellow columns
    // Same framing idea but for the sides of the logo:
    //   colNumber 0  → Black (outermost left)
    //   colNumber 1  → Yellow (inner left)
    //   colNumber 29 → Yellow (inner right)
    //   colNumber 30 → Black (outermost right)
    // y spans from 180 to 300 (vertical middle band of logo)
    // =========================================================
    for (int x = 20; x <= 620; x += 20) {
        int colNumber = (x - 20) / 20; // 0-based column index from left
        for (int y = 180; y <= 300; y += 20) {

            if (colNumber == 0 || colNumber == 1 || colNumber == 29 || colNumber == 30) {
                glBegin(GL_QUADS);

                if (colNumber == 0) {
                    glColor3f(0, 0, 0);        // Black — outermost left border
                }
                else if (colNumber == 1) {
                    glColor3f(0.969, 0.91, 0); // Yellow — inner left border
                }
                else if (colNumber == 29) {
                    glColor3f(0.969, 0.91, 0); // Yellow — inner right border
                }
                else if (colNumber == 30) {
                    glColor3f(0, 0, 0);        // Black — outermost right border
                }

                glVertex2f(x, y);
                glVertex2f(x + 20, y);
                glVertex2f(x + 20, y + 20);
                glVertex2f(x, y + 20);
                glEnd();
            }
        }
    }


    // =========================================================
    // STEP 4: CENTRAL HORIZONTAL BLACK BAR
    // This is the thick black band in the middle of the logo —
    // it represents the bat's body/wing underside and serves
    // as the anchor for the entire shape.
    // Spans full width x=60 to x=580, across 5 rows y=200 to y=280.
    // All squares are black — no conditions needed.
    // =========================================================
    for (int y = 200; y <= 280; y += 20) {
        int rowNumber = (y - 200) / 20; // 0-based, rows 0 through 4
        for (int x = 60; x <= 580; x += 20) {

            if (rowNumber >= 0 && rowNumber <= 4) {
                glBegin(GL_QUADS);
                glColor3f(0, 0, 0); // Black — solid central bar
                glVertex2f(x, y);
                glVertex2f(x + 20, y);
                glVertex2f(x + 20, y + 20);
                glVertex2f(x, y + 20);
                glEnd();
            }
        }
    }


    // =========================================================
    // STEP 5: TOP CORNERS — Staircase zigzag expanding outward
    // The top-left and top-right corners expand outward as they
    // go up, creating a diagonal staircase effect (bat ear tips).
    // Each row shifts the black+yellow pair outward by 20px:
    //   Left black  starts at x = 40 + row*20  (shifts right going up)
    //   Left yellow starts at x = 60 + row*20
    //   Right yellow ends  at x = 600 - row*20
    //   Right black  ends  at x = 620 - row*20 (shifts left going up)
    // 6 rows total, starting from y=320 upward.
    // =========================================================
    for (int row = 0; row < 6; row++) {
        int y = 320 + row * 20;

        // Left black — outermost staircase step
        glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(40 + row * 20, y);
        glVertex2f(60 + row * 20, y);
        glVertex2f(60 + row * 20, y + 20);
        glVertex2f(40 + row * 20, y + 20);
        glEnd();

        // Left yellow — inner staircase step
        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0);
        glVertex2f(60 + row * 20, y);
        glVertex2f(80 + row * 20, y);
        glVertex2f(80 + row * 20, y + 20);
        glVertex2f(60 + row * 20, y + 20);
        glEnd();

        // Right yellow — inner staircase step (mirror of left)
        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0);
        glVertex2f(580 - row * 20, y);
        glVertex2f(600 - row * 20, y);
        glVertex2f(600 - row * 20, y + 20);
        glVertex2f(580 - row * 20, y + 20);
        glEnd();

        // Right black — outermost staircase step (mirror of left)
        glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(600 - row * 20, y);
        glVertex2f(620 - row * 20, y);
        glVertex2f(620 - row * 20, y + 20);
        glVertex2f(600 - row * 20, y + 20);
        glEnd();
    }


    // =========================================================
    // STEP 6: BOTTOM CORNERS — Staircase zigzag shrinking inward
    // Mirror of the top corners but inverted — corners shrink
    // inward as they go down, forming the bat's lower wing tips.
    //   Left black  starts at x = 140 - row*20  (shifts left going down)
    //   Left yellow starts at x = 160 - row*20
    //   Right yellow starts at x = 480 + row*20
    //   Right black  starts at x = 500 + row*20 (shifts right going down)
    // 6 rows total, starting from y=60 upward.
    // =========================================================
    for (int row = 0; row < 6; row++) {
        int y = 60 + row * 20;

        // Bottom-Left black — outermost shrinking step
        glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(140 - row * 20, y);
        glVertex2f(160 - row * 20, y);
        glVertex2f(160 - row * 20, y + 20);
        glVertex2f(140 - row * 20, y + 20);
        glEnd();

        // Bottom-Left yellow — inner shrinking step
        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0);
        glVertex2f(160 - row * 20, y);
        glVertex2f(180 - row * 20, y);
        glVertex2f(180 - row * 20, y + 20);
        glVertex2f(160 - row * 20, y + 20);
        glEnd();

        // Bottom-Right yellow — inner shrinking step (mirror of left)
        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0);
        glVertex2f(480 + row * 20, y);
        glVertex2f(500 + row * 20, y);
        glVertex2f(500 + row * 20, y + 20);
        glVertex2f(480 + row * 20, y + 20);
        glEnd();

        // Bottom-Right black — outermost shrinking step (mirror of left)
        glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(500 + row * 20, y);
        glVertex2f(520 + row * 20, y);
        glVertex2f(520 + row * 20, y + 20);
        glVertex2f(500 + row * 20, y + 20);
        glEnd();
    }


    // =========================================================
    // STEP 7: UPPER WING ROWS (m1 to m6) — Top bat silhouette
    // These 6 rows define the upper wing shape, going from
    // y=400 (m1, widest) down to y=300 (m6, meets center bar).
    // Each row was mapped by counting squares on the pink grid
    // to determine which column indices are black vs yellow.
    // Black regions form the bat wing "holes" and outline.
    // The row widens as it goes down toward the center bar.
    // =========================================================

    // m1 (y=400): Narrowest top row — only 2 black dips in wing top
    for (int x = 160; x <= 480; x += 20) {
        int colNumber = (x - 160) / 20;
        int y = 400;
        if (colNumber != 6 && colNumber != 10) {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black — wing dip markers
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }

    // m2 (y=380): Wing widens — 3 black bands begin to form
    for (int x = 140; x <= 500; x += 20) {
        int colNumber = (x - 140) / 20;
        int y = 380;
        if ((colNumber >= 1 && colNumber <= 3) || (colNumber >= 7 && colNumber <= 11) || (colNumber >= 15 && colNumber <= 17)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black — left edge, center gap, right edge
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }

    // m3 (y=360): Wing continues to widen outward
    for (int x = 120; x <= 520; x += 20) {
        int colNumber = (x - 120) / 20;
        int y = 360;
        if ((colNumber >= 1 && colNumber <= 3) || (colNumber >= 8 && colNumber <= 12) || (colNumber >= 17 && colNumber <= 19)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }

    // m4 (y=340): Black bands grow wider
    for (int x = 100; x <= 540; x += 20) {
        int colNumber = (x - 100) / 20;
        int y = 340;
        if ((colNumber >= 1 && colNumber <= 4) || (colNumber >= 9 && colNumber <= 13) || (colNumber >= 18 && colNumber <= 21)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }

    // m5 (y=320): Row overlaps with top corner staircase zone
    for (int x = 80; x <= 560; x += 20) {
        int colNumber = (x - 80) / 20;
        int y = 320;
        if ((colNumber >= 1 && colNumber <= 5) || (colNumber >= 10 && colNumber <= 14) || (colNumber >= 19 && colNumber <= 23)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }

    // m6 (y=300): Widest upper row — connects directly to center bar
    for (int x = 60; x <= 580; x += 20) {
        int colNumber = (x - 60) / 20;
        int y = 300;
        if ((colNumber >= 1 && colNumber <= 7) || (colNumber >= 10 && colNumber <= 16) || (colNumber >= 19 && colNumber <= 25)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }


    // =========================================================
    // STEP 7: LOWER WING ROWS (m7 to m12) — Bottom bat silhouette
    // Mirror of upper wings but going downward from the center bar.
    // y=180 (m7, widest) down to y=80 (m12, narrowest bottom tip).
    // The row narrows as it descends, forming the lower wing curve.
    // =========================================================

    // m7 (y=180): Widest lower row — connects directly to center bar
    // Almost entirely black across full width
    for (int x = 60; x <= 580; x += 20) {
        int colNumber = (x - 60) / 20;
        int y = 180;
        if ((colNumber >= 1 && colNumber <= 25)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black — nearly full width
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow — just the border edges
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }

    // m8 (y=160): Row begins to narrow from both sides
    for (int x = 80; x <= 560; x += 20) {
        int colNumber = (x - 80) / 20;
        int y = 160;
        if ((colNumber >= 1 && colNumber <= 23)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }

    // m9 (y=140): Black bands split into 3 separate sections
    for (int x = 100; x <= 540; x += 20) {
        int colNumber = (x - 100) / 20;
        int y = 140;
        if ((colNumber >= 1 && colNumber <= 7) || (colNumber >= 9 && colNumber <= 13) || (colNumber >= 15 && colNumber <= 21)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black — 3 descending wing sections
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }

    // m10 (y=120): Sections continue narrowing
    for (int x = 120; x <= 520; x += 20) {
        int colNumber = (x - 120) / 20;
        int y = 120;
        if ((colNumber >= 1 && colNumber <= 5) || (colNumber >= 9 && colNumber <= 11) || (colNumber >= 15 && colNumber <= 19)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }

    // m11 (y=100): Near the bottom tips — sections very narrow
    for (int x = 140; x <= 500; x += 20) {
        int colNumber = (x - 140) / 20;
        int y = 100;
        if ((colNumber >= 1 && colNumber <= 3) || (colNumber >= 8 && colNumber <= 10) || (colNumber >= 15 && colNumber <= 17)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }

    // m12 (y=80): Narrowest bottom row — 3 single black tip squares
    // These are the 3 lowest points of the bat's lower wing
    for (int x = 160; x <= 480; x += 20) {
        int colNumber = (x - 160) / 20;
        int y = 80;
        if (colNumber == 2 || colNumber == 8 || colNumber == 14) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black — 3 single tip squares
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }
}


void lines() {
    // =========================================================
    // PLANNING/DEBUG TOOL — Pink grid overlay
    // This grid was used during development to count squares
    // and verify x/y positions of every row and column.
    // Each cell = 20x20 units, matching the drawing grid.
    // =========================================================

    // Horizontal grid lines
    for (int y = 0; y < 520; y += 20) {
        glBegin(GL_LINES);
        glColor3f(0.969, 0, 0.373); // Pink
        glVertex2f(0, y);
        glVertex2f(660, y);
        glEnd();
    }

    // Vertical grid lines
    for (int x = 20; x < 660; x += 20) {
        glBegin(GL_LINES);
        glColor3f(0.969, 0, 0.373); // Pink
        glVertex2f(x, 0);
        glVertex2f(x, 660);
        glEnd();
    }
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(660, 520);
    glutInitWindowPosition(350, 130);
    glutCreateWindow("Task Batman LOGO");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
