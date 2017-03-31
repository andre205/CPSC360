#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <GL/glut.h>

static float lightHeight = 0.0;

void keyboardFunction(unsigned char key, int x, int y)		//ADJUSTS LIGHT HEIGHT BASED ON KEY PRESS (U for up, D for down)
{
	if (key == 'u')
	{
		if (lightHeight < 5)
			lightHeight = lightHeight + .5;
	}

	else if (key == 'd')
	{
		if (lightHeight > -5)
			lightHeight = lightHeight - .5;
	}

	glutPostRedisplay();
}

void init(void)
{
  glEnable(GL_LIGHTING);									//USED TO LIGHT TEAPOT
  glEnable(GL_LIGHT0);										//ONLY NEED ONE LIGHT
  glEnable(GL_DEPTH_TEST);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);								//SET PERSPECTIVE FOR SCENE IN MODELVIEW

  glPushMatrix();
  glTranslatef(0.0, 0.0, -5.0);								//MOVE TEAPOT SO IT IS VISIBLE IN SCENE (ZOOM OUT)

  glPushMatrix();											//CREATE LIGHT BASED ON lightHeight
  //glColor3f(0.0,0.0,1.0);									//Make light blue? Doesn't work
  GLfloat lightPosition[] = {0.0, lightHeight, 1.5, 1.0};
  glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
  glPopMatrix();

  glutSolidTeapot(1.0);										//CREATE TEAPOT (ALWAYS IN SAME POSITION)
  glPopMatrix();

  glPushAttrib(GL_ENABLE_BIT);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();											//CLEAR PROJECTION MATRIX
  gluOrtho2D(0, 3000, 0, 3000);								//RESET CLIPPING PANES
  glPopMatrix();
  glPopAttrib();

  glutSwapBuffers();
}

void reshape(int w, int h)										//RESHAPE FUNCTION FOR IF WINDOW IS RESIZED
{
  glViewport(0, 0, w, h);										//SET THE VIEWPORT TO THE WINDOW SIZE
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();												//CLEAR PROJECTION MATRIX
  gluPerspective(40.0, (GLfloat) w / (GLfloat) h, 2.0, 50.0);	//KEEP TEAPOT CENTERED IN SCENE
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)									//USUAL MAIN METHOD WITH ADDED KEYBOARD/RESHAPE FUNCTIONS
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Assignment 3 Part 2 - Teapot Lighting");
  init();
  glutKeyboardFunc(keyboardFunction);
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
