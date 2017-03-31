#include <stdio.h>
#include <GL/glut.h>
#include "math.h"

static int window;

//ORDER = MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE

//DISTANCE FROM SUN
static float mercuryDist = 3.5, venusDist = 3.9, earthDist = 4.5, marsDist = 5.5, jupiterDist = 7.0, saturnDist = 10.0, uranusDist = 13.0, neptuneDist = 15.0;

//RELATIVE SIZE
static float mercuryScale = .095, venusScale = .18, earthScale = .20, marsScale = .1, jupiterScale = 1.12, saturnScale = .945, uranusScale = .40, neptuneScale = .388;

//STARTING POSITIONS (POSITIVE X, 0 Z after sin of each)
static float mercuryX = M_PI/2, venusX = M_PI/2, earthX = M_PI/2, marsX = M_PI/2, jupiterX = M_PI/2, saturnX = M_PI/2, uranusX = M_PI/2, neptuneX = M_PI/2;
static float mercuryZ = 0.0, venusZ = 0.0, earthZ = 0.0, marsZ = 0.0, jupiterZ = 0.0, saturnZ = 0.0, uranusZ = 0.0, neptuneZ = 0.0;

//RELATIVE SPEED
static float mercurySpeed = .0016, venusSpeed = .0012, earthSpeed = .001, marsSpeed = .0008, jupiterSpeed = .0004, saturnSpeed = .0003, uranusSpeed = .0002, neptuneSpeed = .0002;

//CAMERA POSITION COORDINATES
static int camX = 0, camY = 0, camZ = 20;

//BOOLS FOR SPECIAL CAMERA ANGLES (DOESNT WORK)
static int outIn = 0, inOut = 0;

//BOOL FOR SHADING (Using emission light) (not perfect but it looks alright)
static int light = 0;

//INCREASE ALL X AND Z COORDINATES BASED ON RELATIVE SPEED
void rotate()
{
	mercuryX += mercurySpeed; 	mercuryZ += mercurySpeed;
	venusX += venusSpeed; 		venusZ += venusSpeed;
	earthX += earthSpeed; 		earthZ += earthSpeed;
	marsX += marsSpeed; 		marsZ += marsSpeed;
	jupiterX += jupiterSpeed; 	jupiterZ += jupiterSpeed;
	saturnX += saturnSpeed; 	saturnZ += saturnSpeed;
	uranusX += uranusSpeed; 	uranusZ += uranusSpeed;
	neptuneX += neptuneSpeed; 	neptuneZ += neptuneSpeed;


// ATTEMPT AT PUTTING THE CAMERA IN NEPTUNE/SUN (COULDNT GET IT TO WORK)
//	if (outIn)
//	{
//		camX = neptuneDist * sin(neptuneX);
//		camY = 0;
//		camZ = -1 * neptuneDist * sin(neptuneZ);
//	}
//	else if (inOut)
//	{
//		camX = 0;
//		camY = 0;
//		camZ = 0;
//	}

	glutPostRedisplay();
}

//CHANGE GLULOOKAT COORDINATES BASED ON VIEWING ANGLE
void menu(int c)
{

	outIn = 0;
	inOut = 0;

	switch(c)
	{
		case(0):	//ABOVE
			camX = 0;	camY = 20;	camZ = 1;
			break;
		case(1):	//EYE LEVEL
			camX = 0;	camY = 0;	camZ = 20;
			break;
		case(2):	//BELOW
			camX = 0;	camY = -20;	camZ = 1;
			break;
		case(3):
			break;
		case(4):
			inOut = 1;
			break;
		case(5):
			outIn = 1;
			break;
		case(6):
			break;
		case(7):
			light = 1;
			break;
		case(8):
			light = 0;
			break;
		case(9):
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

    glutAddMenuEntry("VIEW FROM ABOVE", 0);
    glutAddMenuEntry("VIEW FROM EYE LEVEL", 1);
    glutAddMenuEntry("VIEW FROM BELOW", 2);
//    glutAddMenuEntry("----------------", 3);
//    glutAddMenuEntry("SUN LOOKING OUT (WIP)", 4);
//    glutAddMenuEntry("NEPTUNE LOOKING IN (WIP)", 5);
    glutAddMenuEntry("----------------", 6);
    glutAddMenuEntry("ENABLE SHADING", 7);
    glutAddMenuEntry("DISABLE SHADING", 8);
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

	if (light)
	{
	  glEnable(GL_LIGHTING);
	  glEnable(GL_LIGHT0);
	}

	else
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
	}

	//SUN
	glPushMatrix();

	//CREATE EMISSION IF SHADING IS ON
	if (light)
	{
		GLfloat lightEmiss[] = {1.0, 1.0, 0.0, 1.5};
		glMaterialfv(GL_FRONT, GL_EMISSION, lightEmiss);
	}
	glColor3f(0.86, 0.75, 0.0);
	glutSolidSphere(2, 150.0, 150.0);
	glPopMatrix();


	//REST OF PLANETS
	if (light)
	{
		GLfloat noEmiss[] = {0.0, 0.0, 0.0, 0.0};
		glMaterialfv(GL_FRONT, GL_EMISSION, noEmiss);
	}

	//MERCURY
	glPushMatrix();
	glTranslatef(mercuryDist * sin(mercuryX), 0.0, -1 * mercuryDist * sin(mercuryZ));
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere(mercuryScale, 50.0, 50.0);
	glPopMatrix();

	//VENUS
	glPushMatrix();
	glTranslatef(venusDist * sin(venusX), 0.0, -1 * venusDist * sin(venusZ));
	glColor3f(0.5, 0.5, 0.5);
	glutSolidSphere(venusScale, 50.0, 50.0);
	glPopMatrix();

	//EARTH
	glPushMatrix();
	glTranslatef(earthDist * sin(earthX), 0.0, -1 * earthDist * sin(earthZ));
	glColor3f(0.0, 1.0, 0.1);
	glutSolidSphere(earthScale, 50.0, 50.0);
	glPopMatrix();

	//MARS
	glPushMatrix();
	glTranslatef(marsDist * sin(marsX), 0.0, -1 * marsDist * sin(marsZ));
	glColor3f(1.0, 0.0, 0.1);
	glutSolidSphere(marsScale, 50.0, 50.0);
	glPopMatrix();

	//JUPITER
	glPushMatrix();
	glTranslatef(jupiterDist * sin(jupiterX), 0.0, -1 * jupiterDist * sin(jupiterZ));
	glColor3f(0.6, 1.0, 0.1);
	glutSolidSphere(jupiterScale, 50.0, 50.0);
	glPopMatrix();

	//SATURN
	glPushMatrix();
	glTranslatef(saturnDist * sin(saturnX), 0.0, -1 * saturnDist * sin(saturnZ));
	glColor3f(1.0, 0.5, 0.4);
	glutSolidSphere(saturnScale, 50.0, 50.0);
	glPopMatrix();

	//URANUS
	glPushMatrix();
	glTranslatef(uranusDist * sin(uranusX), 0.0, -1 * uranusDist * sin(uranusZ));
	glColor3f(0.0, 0.0, 0.7);
	glutSolidSphere(uranusScale, 50.0, 50.0);
	glPopMatrix();

	//NEPTUNE
	glPushMatrix();
	glTranslatef(neptuneDist * sin(neptuneX), 0.0, -1 * neptuneDist * sin(neptuneZ));
	glColor3f(0.0, 0.0, 0.7);
	glutSolidSphere(neptuneScale, 50.0, 50.0);
	glPopMatrix();

	//POSITION CAMERA BASED ON USER SELECTED CHOICE, ALWAYS LOOK AT ORIGIN (SUN)
	glLoadIdentity();
	gluLookAt(camX, camY, camZ, 0, 0, 0, 0, 1, 0);
	glFlush();

	glutSwapBuffers();
}

//SAME RESHAPE AS LAST ASSIGNMENT
void reshape(int w, int h)
{
  glViewport(0, 0, w, h);										//SET THE VIEWPORT TO THE WINDOW SIZE
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();												//CLEAR PROJECTION MATRIX
  gluPerspective(40.0, (GLfloat) w / (GLfloat) h, 2.0, 50.0);	//KEEP CUBE CENTERED IN SCENE
  glMatrixMode(GL_MODELVIEW);
}

//USUAL MAIN
int main(int argc, char **argv)									//USUAL MAIN METHOD WITH ADDED IDLE FUNCTION FOR ROTATION
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1500, 500);
  glutCreateWindow("Assignment 5 - Solar System Model");
  init();
  createMenu();
  glutReshapeFunc(reshape);
  glutIdleFunc(rotate);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
