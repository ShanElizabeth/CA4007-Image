#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

// This program draws a sphere using the Quadric functions.

void display(void)
{	//background color
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//make a matrix
	glMatrixMode(GL_MODELVIEW);
	//gets rid of previous values, clean slate set = to identity matrix
	glLoadIdentity();
	//eye , center, up
	gluLookAt(3.0,3.0,3.0,2.0,2.0,2.0,0.0,1.0,0.0);


	GLUquadricObj *MySphere;
	MySphere = gluNewQuadric();
	gluQuadricDrawStyle(MySphere, GLU_LINE);
	//(SIZE,vertical lines,horizontal lines)
	gluSphere(MySphere,0.5,20,10);

	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); //gets rid of previous values, clean slate set = to identity matrix
	//glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glFrustum(-1.0,1.0,-1.0,1.0,4.0,6.0);
	

	glViewport(0,0,w,h);
	return;
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("sphere");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);


	glutMainLoop();
}