#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

GLfloat yshift=0.0,rshift=0.0;

void wheel(GLfloat x, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x,-0.25,z);
	glRotatef(90,0.0,1.0,0.0);
	glRotatef(rshift,0.0,0.0,1.0);
	glutWireTorus(0.05,0.1,12,12);
	glPopMatrix();

	return;
}

void display(void){

	glClearColor(0.0,0.0,1.0,1.0); //baclground color
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //set the matrix
	glLoadIdentity();//clear any previous values
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);

	glTranslatef(0.0,yshift,0.0);
	glutWireCube(0.5); //sets up wire cube

	wheel(0.25,0.25);
	wheel(-0.25,0.25);
	wheel(0.25,-0.25);
	wheel(-0.25,-0.25);


	glFlush();
	return;
}



void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2.0,2.0,-2.0,2.0,0.3,5.0);
	glFrustum(-1.0,1.0,-1.0,1.0,0.3,5.0);
//	gluPerspective(60,1.0,0.3,5.0);
	glViewport(0,0,w,h);
	return;
}

void MyIdle()
{
yshift += 0.0005;
rshift += 5;

if(yshift > 1.0) yshift = -1.0l;
glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("practice room");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutIdleFunc(MyIdle); 


	glutMainLoop();
}