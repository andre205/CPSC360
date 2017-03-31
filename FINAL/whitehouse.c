#include <stdio.h>
#include <GL/glut.h>
#include "math.h"

static int window;

//ORDER = MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE

//CAMERA POSITION COORDINATES
static float camX = 0.0, camY = 0.0, camZ = M_PI/2;

//CAMERA TARGET COORDINATES
static float tarX = 0.0, tarY = 0.0, tarZ = 0.0;

//BOOL FOR MODE TYPE
static int rotationMode = 1, birdsEyeMode = 0;

//INCREASE ALL X AND Z COORDINATES BASED ON RELATIVE SPEED
void rotate()
{
	if(rotationMode)
	{
		camX += .001;
		camZ += .001;
	}



	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	if(birdsEyeMode)
	{
		if (key == 'w')
		{
			camZ -= .01;
			//tarZ -= .01;
		}
		if (key == 'a')
		{
			camX -= .01;
			//tarX -= .01;
		}
		if (key == 's')
		{
			camZ += .01;
			//tarZ += .01;
		}
		if (key == 'd')
		{
			camX += .01;
			//tarX += .01;
		}
	}
}

//CHANGE GLULOOKAT COORDINATES BASED ON VIEWING ANGLE
void menu(int c)
{
	rotationMode = 0;
	birdsEyeMode = 0;
	tarX = 0; tarY = 0; tarZ = 0;

	switch(c)
	{
		case(0):	//BIRDS EYE
			birdsEyeMode = 1;
			tarX = 0;	tarY = -10;	tarZ = -30;
			camX = 0;	camY = 20;	camZ = .75;
			break;
		case(1):	//EYE LEVEL
			camX = 0;	camY = 0;	camZ = 40;
			break;
		case(2):	//ROTATION MODE
			camX = 0;	camY = 0;	camZ = M_PI/2;
			rotationMode = 1;
			break;

		case(10):	//QUIT
			glutDestroyWindow(window);
			exit(0);
			break;
		default:
			break;
	}
}

//SAME MENU METHOD AS BEFORE
void createMenu(void)
{
    glutCreateMenu(menu);

    glutAddMenuEntry("BIRDS EYE VIEW", 0);
    glutAddMenuEntry("VIEW FROM EYE LEVEL", 1);
    glutAddMenuEntry("ROTATE", 2);
    glutAddMenuEntry("----------------", 9);
    glutAddMenuEntry("QUIT APPLICATION", 10);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void init(void)
{
  glEnable(GL_DEPTH_TEST);

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLUquadric* cyl = gluNewQuadric();
	GLUquadric* disk = gluNewQuadric();

	glColor3f(1.0, 1.0, 1.0);


	//FRONT CYLINDERS
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(-7.75, -2.75+4, 0.0);
	gluCylinder(cyl, .5, .5, 8.0, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(-5.5, 1.25+4, 0.0);
	gluCylinder(cyl, .5, .5, 8.0, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(-2.5, 3.0+4, 0.0);
	gluCylinder(cyl, .5, .5, 8.0, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(2.5, 3.0+4, 0.0);
	gluCylinder(cyl, .5, .5, 8.0, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(5.5, 1.25+4, 0.0);
	gluCylinder(cyl, .5, .5, 8.0, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(7.75, -2.75+4, 0.0);
	gluCylinder(cyl, .5, .5, 8.0, 50, 50);
	glPopMatrix();

	//COLUMN ROOF
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.0);
	gluCylinder(disk, 8.5, 8.5, 1.0, 50, 50);
	glPopMatrix();

	//COLUMN FLOOR
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 8.0);
	gluCylinder(disk, 8.5, 8.5, 1.0, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 8.0);
	gluDisk(disk, 0, 8.5, 50, 50);
	glPopMatrix();

	//BUILDING STRUCTURE
//	glPushMatrix();
//	glTranslatef(0.0, -3.0, 0.0);
//	glutSolidCube(10.0);
//	glPopMatrix();

//	glPushMatrix();
//	glColor3f(0.0, 1.0, .5);
//	glBegin(GL_QUADS);
//		glVertex4f(-10, -10, 0, 0);
//		glVertex4f(-10, 10, 0, 0);
//		glVertex4f(10, 10, 0, 0);
//		glVertex4f(10, -10, 0, 0);
//	glEnd();
//	glPopMatrix();

	//POSITION CAMERA BASED ON USER SELECTED CHOICE, LOOK AT TARGET
	glLoadIdentity();
	gluLookAt(40*sin(camX), camY, 40*sin(camZ), tarX, tarY, tarZ, 0, 1, 0);
	glFlush();

	glutSwapBuffers();
}

//SAME RESHAPE AS LAST ASSIGNMENT
void reshape(int w, int h)
{
  glViewport(0, 0, w, h);										//SET THE VIEWPORT TO THE WINDOW SIZE
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();												//CLEAR PROJECTION MATRIX
  gluPerspective(80.0, (GLfloat) w / (GLfloat) h, 2.0, 50.0);	//KEEP CUBE CENTERED IN SCENE
  glMatrixMode(GL_MODELVIEW);
}

//USUAL MAIN
int main(int argc, char **argv)									//USUAL MAIN METHOD WITH ADDED IDLE FUNCTION FOR ROTATION
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(10, 10);
  glutInitWindowSize(1300, 790);
  glutCreateWindow("Assignment 5 - Solar System Model");
  init();
  createMenu();
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(rotate);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
