#include "GL\freeglut.h"
#include "HyperCube.h"
#include "Cell_5.h"

HyperCube hc(5);
Cell_5 cell;


/* Runs Once */
void init()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20.0, 20.0, -20.0, 20.0, -1.0, 30.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(-3, 2, 14, 0, 0, 0, 0, 1, 0);

	glRotatef(60, 0, 1, 0);
}

/* Runs per Frame */
void idle()
{
	//glRotatef(-1, 0, 1, 0);

	Sleep(33);
	glutPostRedisplay();
}

/* Runs per Frame */
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* == Render Code == */
	//hc.render(0);
	cell.render(0);
	/* ================= */

	/* == Axis Cross == */
	glPushMatrix();
		glBegin(GL_LINES);
			glColor3f(1.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(10.0, 0.0, 0.0);
		glEnd();
		glBegin(GL_LINES);
			glColor3f(0.0, 1.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 10.0, 0.0);
		glEnd();
		glBegin(GL_LINES);
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 10.0);
		glEnd();
	glPopMatrix();
	/* ================ */

	glFlush();
}

/* Add this to main(int arg, char** argv) */
void initWindow(int arg, char** argv)
{
	glutInit(&arg, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(200, 150);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Tessecrap");

	init();
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	glutMainLoop();
}