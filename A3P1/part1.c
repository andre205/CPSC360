#include <stdio.h>
#include <GL/glut.h>

static int window;
static int menu_id;
static int choice = 20;							//SET BLANK SCREEN BEFORE CHOICE IS MADE

void menu(int c)
{
  if(c == 3)									//IF THEY CHOOSE TO QUIT, CLOSE WINDOW
  {
    glutDestroyWindow(window);
    exit(0);
  }

  else											//IF NOT, SEND CHOICE TO DISPLAY FUNCTION
  {
    choice = c;
  }

  glutPostRedisplay();							//REFRESH
}
void createMenu(void)
{
    menu_id = glutCreateMenu(menu);				//DISPLAY LIST ON RIGHT CLICK

    glutAddMenuEntry("Bitmap", 0);
    glutAddMenuEntry("Stroke", 1);
    glutAddMenuEntry("----------------", 2);
    glutAddMenuEntry("QUIT APPLICATION", 3);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);


	if (choice == 0)
	{
		glScalef(1.0,1.0,1.0);
		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2i(75,65);										//SET RASTER TO MIDDLE OF SCREEN
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'T');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'Y');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'R');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'A');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'D');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'R');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'W');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'S');

		glRasterPos2i(75,55);
		for (int i = 65; i < 65+26; ++i)
		{
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, i);
		}

		glRasterPos2i(75,45);
		for (int i = 97; i < 97+26; ++i)
		{
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, i);
		}
	}

	else if (choice == 1)
	{
		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glScalef(.05f,.05f,0);
		glTranslatef(1300,1300,0);
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'T');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'Y');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'L');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'E');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'R');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, ' ');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'A');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'N');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'D');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'R');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'E');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'W');
		glutStrokeCharacter(GLUT_STROKE_ROMAN, 'S');

		glTranslatef(-1090,-200,0);

		glRasterPos2i(75,45);
		for (int i = 65; i < 65+26; ++i)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, i);
		}

		glTranslatef(-2090,-200,0);

		glRasterPos2i(75,35);
		for (int i = 97; i < 97+26; ++i)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, i);
		}

		glPopMatrix();
	}

  glFlush();													//SEND TO DISPLAY
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 200, 0, 100);									//200x100 makes for easy integer values	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);					//DO NOT FILL POLYGONS (Show outlines)	glPointSize(3.0);											//MAKE POINTS MORE VISIBLE
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(1000,500);								//RECTANGULAR WINDOW (To show before and after on left/right)
    glutInitWindowPosition(100,100);
    window = glutCreateWindow("Assignment 3 Part 1 - Fonts");
    createMenu();												//GENERATE MENU OPTIONS ON RIGHT CLICK
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
