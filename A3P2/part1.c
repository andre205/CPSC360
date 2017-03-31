#include <GL/glut.h>

GLfloat width = 800;
GLfloat height = 600;

GLfloat v1[] = {0.0, 0.0, 0.0};
GLfloat v2[] = {5.0, 0.0, -5.0};
GLfloat v3[] = {-5.0, 0.0, -5.0};
GLfloat v4[] = {0.0, 5.0, -5.0};

GLfloat middle[] = {0.0, .5, -.5};

GLfloat temp[] = {0.0, 0.0, 0.0};

int vertexPick = 1;

void pickVertex()												//GENERATE RANDOM NUMBER 0-3 (THIS IS 1 OF THE 4 VERTICES)
{
	int x = rand() % 4;
	vertexPick = x;
}

GLfloat calcAvg(GLfloat point1, GLfloat point2)					//CALCULATE FLOAT MIDPOINT (Couldnt get this working for arrays)
{
	float a;
	a = (point1 + point2) / 2.0;
	return a;
}

// Clears the window and draws the tetrahedron.
void display() {												//YOUR CODE FOR A TETRAHEDRON
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.1, 0.5, 10.0);
	glRotatef(5.0, 1, 1, 0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f(1.0, 0.0, 0.0); glVertex3fv(v1);
		glColor3f(1.0, 0.0, 0.0); glVertex3fv(v2);
		glColor3f(1.0, 0.0, 0.0); glVertex3fv(v3);
		glColor3f(1.0, 0.0, 0.0); glVertex3fv(v4);
		glColor3f(1.0, 0.0, 0.0); glVertex3fv(v1);
		glColor3f(1.0, 0.0, 0.0); glVertex3fv(v2);
	glEnd();

	for (int i = 0; i < 1000000; ++i)							//PLOT 1,000,000 POINTS BASED ON THE ALGORITHM
	{
		pickVertex();											//CHOOSE A VERTEX

		if (vertexPick == 0)									//CALCULATE MIDPOINT
		{
			middle[0] = calcAvg(middle[0], v1[0]);
			middle[1] = calcAvg(middle[1], v1[1]);
			middle[2] = calcAvg(middle[2], v1[2]);
		}

		else if (vertexPick == 1)
		{
			middle[0] = calcAvg(middle[0], v2[0]);
			middle[1] = calcAvg(middle[1], v2[1]);
			middle[2] = calcAvg(middle[2], v2[2]);
		}

		else if (vertexPick == 2)
		{
			middle[0] = calcAvg(middle[0], v3[0]);
			middle[1] = calcAvg(middle[1], v3[1]);
			middle[2] = calcAvg(middle[2], v3[2]);
		}

		else if (vertexPick == 3)
		{
			middle[0] = calcAvg(middle[0], v4[0]);
			middle[1] = calcAvg(middle[1], v4[1]);
			middle[2] = calcAvg(middle[2], v4[2]);
		}

		glBegin(GL_POINTS);
			glVertex3fv(middle);								//PLOT MIDPOINT
		glEnd();
	}


  glFlush();
}

// Initialize the application.
void init() {
	// Set the current clear color to white.
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// Set the camera lens to have a 0 degree (vertical) field of view, an
	// aspect ratio of 4/3, and have everything closer than 1 unit to the
	// camera and greater than 100 units distant clipped away.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(0.0, width/height, 1, 100);

	// Position camera at (0, 0, 10) looking at (0, 0, 0) with the vector
	// <0, 1, 0> pointing upward.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 1, 10, 0, 0, 0, 0, 1, 0);

	glEnable(GL_DEPTH_TEST);

	glPointSize(2.0);													//MAKE POINTS A LITTLE EASIER TO SEE
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize((GLint)width, (GLint)height);
  glutCreateWindow("Assignment 3 Part 2 - Sierpinksy Gasket Tetrahedron");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
