#include <stdio.h>
#include <GL/glut.h>
#include "math.h"

void init(void);
void sinandcos(void);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);								// Initialize GLUT.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		// Set display mode.
	glutInitWindowPosition(200, 100);					// Set top-left display-window position.
	glutInitWindowSize(800, 400);						// Set display-window width and height.
	glutCreateWindow("Sine and Cosine Visualization");	// Create display window with given title.
	init();												// Execute initialization procedure.
	glutDisplayFunc(sinandcos);							// Send graphics to display window.
	glutMainLoop();										// Display everything and wait.
    return 0;
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);					// Set display-window color to white.
	glMatrixMode(GL_PROJECTION);						// Set project parameters.
	gluOrtho2D(-2*M_PI-1, 2*M_PI+1, -1.25, 1.25);		// Set vertical and horizontal clipping planes.
}

void sinandcos(void)
{
	glClear(GL_COLOR_BUFFER_BIT);						// Clear display window.

	glColor3f(1.0, 0.0, 0.0);							//SET X AND Y AXIS AND Y HASH MARKS
	glBegin(GL_LINES);
		glVertex2d(-2*(M_PI), 0);
		glVertex2d(2*(M_PI), 0);

		glVertex2d(0, -1);
		glVertex2d(0, 1);

		glVertex2d(-.1, 1);								//Y HASHES
		glVertex2d(.1, 1);
		glVertex2d(-.1, -1);
		glVertex2d(.1, -1);
	glEnd();

	for (float i = -2*M_PI; i <= 7; i += M_PI/2)		//X HASHES
	{
		glBegin(GL_LINES);
			glVertex2d(i, .04);
			glVertex2d(i, -.04);
		glEnd();
	}

	for (float i = -2*M_PI; i < 2*M_PI; i += .00001)
	{
		glColor3f(0.0, 0.0, 1.0);						//PLOT SINE (Blue)
		glBegin(GL_POINTS);
			glVertex2d(i, sin(i));
		glEnd();

		glColor3f(0.0, 1.0, 0.0);						//PLOT COSINE (Green)
		glBegin(GL_POINTS);
			glVertex2d(i, cos(i));
		glEnd();
	}

	glFlush();											// Process all OpenGL routines ASAP.
}
