#include <GL/glut.h>
#include <cmath>
#include <iostream>

void drawCircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;

    glPointSize(2.0);
    glBegin(GL_POINTS);

    while (x >= y)
    {
        glVertex2i(x0 + x, y0 + y);
        glVertex2i(x0 + y, y0 + x);
        glVertex2i(x0 - y, y0 + x);
        glVertex2i(x0 - x, y0 + y);
        glVertex2i(x0 - x, y0 - y);
        glVertex2i(x0 - y, y0 - x);
        glVertex2i(x0 + y, y0 - x);
        glVertex2i(x0 + x, y0 - y);

        y++;
        err += 1 + 2 * y;
        if (2 * (err - x) + 1 > 0)
        {
            x--;
            err += 1 - 2 * x;
        }
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // set up coordinates
    gluOrtho2D(0, 400, 0, 400);

    // dibujo del circulo circle
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(200, 200, 50);

    // dibujo lineas vertical
    glColor3f(0.0, 1.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2i(200 - 50, 200 + 50);
    glVertex2i(200 + 50, 200 - 50);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circulo y linea diagonal");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
