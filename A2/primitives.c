#include <stdio.h>
#include <GL/glut.h>

static int window;
static int menu_id;
static int choice = 20;							//SET BLANK SCREEN BEFORE CHOICE IS MADE

void menu(int c)
{
  if(c == 11)									//IF THEY CHOOSE TO QUIT, CLOSE WINDOW
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

    glutAddMenuEntry("GL_POINTS", 0);
    glutAddMenuEntry("GL_LINES", 1);
    glutAddMenuEntry("GL_LINE_STRIP", 2);
    glutAddMenuEntry("GL_POLYGON", 3);
    glutAddMenuEntry("GL_TRIANGLES", 4);
    glutAddMenuEntry("GL_TRIANGLE_STRIP", 5);
    glutAddMenuEntry("GL_TRIANGLE_FAN", 6);
    glutAddMenuEntry("GL_QUADS", 7);
    glutAddMenuEntry("GL_QUAD_STRIP", 8);
    glutAddMenuEntry("GL_BITMAP_9_BY_15", 9);
    glutAddMenuEntry("----------------", 10);
    glutAddMenuEntry("QUIT APPLICATION", 11);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (choice < 9)
	{
		glColor3f(0.0, 0.0, 0.0);					//DIVIDING LINE FOR ALL (EXCEPT FOR NAME)
		glBegin(GL_LINES);
			glVertex2i(100, 5);
			glVertex2i(100, 95);
		glEnd();
	}

if (choice == 0)									//FOR EACH PRIMITIVE, POINTS ARE ON LEFT, PRIMITIVES ARE ON RIGHT (+100px in x direction)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(50, 40);
		glVertex2i(50, 60);
		glVertex2i(50, 80);
		glVertex2i(60, 30);
		glVertex2i(60, 50);
		glVertex2i(60, 70);
	glEnd();

	glBegin(GL_POINTS);
		glVertex2i(150, 40);
		glVertex2i(150, 60);
		glVertex2i(150, 80);
		glVertex2i(160, 30);
		glVertex2i(160, 50);
		glVertex2i(160, 70);
	glEnd();
}
else if (choice == 1)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(50, 40);
		glVertex2i(50, 60);
		glVertex2i(50, 80);
		glVertex2i(60, 30);
		glVertex2i(60, 50);
		glVertex2i(60, 70);
	glEnd();

	glBegin(GL_LINES);
		glVertex2i(160, 30);
		glVertex2i(150, 40);
		glVertex2i(160, 50);
		glVertex2i(150, 60);
		glVertex2i(160, 70);
		glVertex2i(150, 80);
	glEnd();
}

else if (choice == 2)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(50, 40);
		glVertex2i(50, 60);
		glVertex2i(50, 80);
		glVertex2i(60, 30);
		glVertex2i(60, 50);
		glVertex2i(60, 70);
	glEnd();

	glBegin(GL_LINE_STRIP);
		glVertex2i(160, 30);
		glVertex2i(150, 40);
		glVertex2i(160, 50);
		glVertex2i(150, 60);
		glVertex2i(160, 70);
		glVertex2i(150, 80);
	glEnd();
}

else if (choice == 3)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(40, 40);
		glVertex2i(60, 40);
		glVertex2i(70, 60);
		glVertex2i(60, 80);
		glVertex2i(40, 80);
		glVertex2i(30, 60);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2i(140, 40);
		glVertex2i(160, 40);
		glVertex2i(170, 60);
		glVertex2i(160, 80);
		glVertex2i(140, 80);
		glVertex2i(130, 60);
	glEnd();
}

else if (choice == 4)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(50, 40);
		glVertex2i(50, 60);
		glVertex2i(50, 80);
		glVertex2i(60, 30);
		glVertex2i(60, 50);
		glVertex2i(60, 70);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2i(160, 30);
		glVertex2i(150, 40);
		glVertex2i(160, 50);
		glVertex2i(150, 60);
		glVertex2i(160, 70);
		glVertex2i(150, 80);
	glEnd();
}

else if (choice == 5)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(50, 40);
		glVertex2i(50, 60);
		glVertex2i(50, 80);
		glVertex2i(60, 30);
		glVertex2i(60, 50);
		glVertex2i(60, 70);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2i(160, 30);
		glVertex2i(150, 40);
		glVertex2i(160, 50);
		glVertex2i(150, 60);
		glVertex2i(160, 70);
		glVertex2i(150, 80);
	glEnd();
}

else if (choice == 6)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(50, 60);
		glVertex2i(40, 40);
		glVertex2i(60, 40);
		glVertex2i(70, 60);
		glVertex2i(60, 80);
		glVertex2i(40, 80);
		glVertex2i(30, 60);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glVertex2i(150, 60);
		glVertex2i(140, 40);
		glVertex2i(160, 40);
		glVertex2i(170, 60);
		glVertex2i(160, 80);
		glVertex2i(140, 80);
		glVertex2i(130, 60);
		glVertex2i(140, 40);
	glEnd();
}

else if (choice == 7)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(50, 30);
		glVertex2i(50, 45);
		glVertex2i(60, 45);
		glVertex2i(60, 30);

		glVertex2i(50, 60);
		glVertex2i(50, 75);
		glVertex2i(60, 75);
		glVertex2i(60, 60);
	glEnd();

	glBegin(GL_QUADS);
		glVertex2i(150, 30);
		glVertex2i(160, 30);
		glVertex2i(160, 45);
		glVertex2i(150, 45);

		glVertex2i(150, 60);
		glVertex2i(150, 75);
		glVertex2i(160, 75);
		glVertex2i(160, 60);
	glEnd();
}

else if (choice == 8)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(50, 30);
		glVertex2i(70, 30);

		glVertex2i(50, 45);
		glVertex2i(70, 45);

		glVertex2i(50, 60);
		glVertex2i(70, 60);

		glVertex2i(50, 75);
		glVertex2i(70, 75);
	glEnd();

	glBegin(GL_QUAD_STRIP);
		glVertex2i(150, 30);
		glVertex2i(170, 30);

		glVertex2i(150, 45);
		glVertex2i(170, 45);

		glVertex2i(150, 60);
		glVertex2i(170, 60);

		glVertex2i(150, 75);
		glVertex2i(170, 75);
	glEnd();
}

else if (choice == 9)
{
	glRasterPos2i(85,55);										//SET RASTER TO MIDDLE OF SCREEN
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
}

  glFlush();													//SEND TO DISPLAY
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 200, 0, 100);									//200x100 makes for easy integer values
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);					//DO NOT FILL POLYGONS (Show outlines)
	glPointSize(3.0);											//MAKE POINTS MORE VISIBLE
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(1000,500);								//RECTANGULAR WINDOW (To show before and after on left/right)
    glutInitWindowPosition(100,100);
    window = glutCreateWindow("Assignment 2 - Output Primitives");
    createMenu();												//GENERATE MENU OPTIONS ON RIGHT CLICK
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
