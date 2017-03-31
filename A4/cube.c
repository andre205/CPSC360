#include <stdio.h>
#include <GL/glut.h>

static int window;
static int rotationAxis = 1;					//FOR ROTATION AXIS, 1 = X, 2 = Y, 3 = Z
static float rotationAmt = 0.0, scaleAmt = 1.0, x = 0.0, y = 0.0, z = -5.0;

void rotate()
{
	rotationAmt = rotationAmt + .05;			//CONSTANTLY INCREASE ROTATION AMOUNT
	glutPostRedisplay();						//REFRESH IMAGE
}

void menu(int c)
{
  switch(c)
  {
		case(0):	//UP
			y++;
			break;
		case(1):	//DOWN
			y--;
			break;
		case(2):	//LEFT
			x--;
			break;
		case(3):	//RIGHT
			x++;
			break;
		case(4):
			break;
		case(5):	//ROTATE X
			rotationAxis = 1;
			break;
		case(6):	//ROTATE Y
			rotationAxis = 2;
			break;
		case(7):	//ROTATE Z
			rotationAxis = 3;
			break;
		case(8):
			break;
		case(9):	//SCALE X2
			scaleAmt = scaleAmt * 2.0;
			break;
		case(10):	//SCALE X.5
			scaleAmt = scaleAmt * 0.5;
			break;
		case(11):
			break;
		case(12):	//RESET
			x = 0.0;
			y = 0.0;
			z = -5.0;
			scaleAmt = 1.0;
			rotationAxis = 1;
			rotationAmt = 0.0;
			break;
		case(13):
			break;
		case(14):	//QUIT
			glutDestroyWindow(window);
		    exit(0);
		    break;
		default:
			break;
  }
}
void createMenu(void)
{
    glutCreateMenu(menu);						//DISPLAY MENU

    glutAddMenuEntry("UP", 0);					//MENU OPTIONS
    glutAddMenuEntry("DOWN", 1);
    glutAddMenuEntry("LEFT", 2);
    glutAddMenuEntry("RIGHT", 3);
    glutAddMenuEntry("----------------", 4);
    glutAddMenuEntry("ROTATE AROUND X AXIS", 5);
    glutAddMenuEntry("ROTATE AROUND Y AXIS", 6);
    glutAddMenuEntry("ROTATE AROUND Z AXIS", 7);
    glutAddMenuEntry("----------------", 8);
    glutAddMenuEntry("SCALE x2", 9);
    glutAddMenuEntry("SCALE x.5", 10);
    glutAddMenuEntry("----------------", 11);
    glutAddMenuEntry("RESET", 12);
    glutAddMenuEntry("----------------", 13);
    glutAddMenuEntry("QUIT APPLICATION", 14);

    glutAttachMenu(GLUT_RIGHT_BUTTON);			//TIE TO RIGHT CLICK
}

void init(void)
{
  glEnable(GL_DEPTH_TEST);						//ALLOW FOR DEPTH IN Z DIRECTION
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);								//SET PERSPECTIVE FOR SCENE IN MODELVIEW

	glPushMatrix();

	glTranslatef(x, y, z);									//MOVE CUBE ACCORDING TO USER SPECIFIED AMOUNT

	switch (rotationAxis)									//CONSTANTLY ROTATE CUBE ALONG DESIRED AXIS
	{
		case(1):
			glRotatef(rotationAmt,1.0,0.0,0.0);
			break;
		case(2):
			glRotatef(rotationAmt,0.0,1.0,0.0);
			break;
		case(3):
			glRotatef(rotationAmt,0.0,0.0,1.0);
			break;
		default:
			glRotatef(rotationAmt,1.0,0.0,0.0);
			break;
	}

	glScalef(scaleAmt, scaleAmt, scaleAmt);					//SCALE CUBE BY USER SPECIFIED AMOUNT

	glColor3f(1.0, 1.0, 1.0);
	glutWireCube(1.0);										//CREATE CUBE

	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
  glViewport(0, 0, w, h);										//SET THE VIEWPORT TO THE WINDOW SIZE
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();												//CLEAR PROJECTION MATRIX
  gluPerspective(40.0, (GLfloat) w / (GLfloat) h, 2.0, 50.0);	//KEEP CUBE CENTERED IN SCENE
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)									//USUAL MAIN METHOD WITH ADDED IDLE FUNCTION FOR ROTATION
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Assignment 4 - Cube Transformations");
  init();
  createMenu();
  glutReshapeFunc(reshape);
  glutIdleFunc(rotate);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
