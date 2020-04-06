#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>


void display(void)
{	//rb
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat pos[4] = {1.0,1.0,1.0,1.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);

	GLfloat x,y=-1.0,z,theta=0.0;

	glBegin(GL_QUAD_STRIP);
	for(int i=0; i <900; i++)
	{
		theta += 0.1;
		x=0.6*cos(theta); z=0.6*sin(theta);
		y += 0.002;
		glNormal3f(x/0.6,0,z/0.6);
		glVertex3f(x,y,z);
		glVertex3f(x,y+0.07,z);
	}				
	glEnd();


	
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

void MySpecial(GLint key, GLint x, GLint y)
{
	if(key == GLUT_KEY_RIGHT) y+=0.1;
	
	else if(key == GLUT_KEY_LEFT) y-=0.1;
	glutPostRedisplay();
}


int main(int argc, char **argv)
{	
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("spiral");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutSpecialFunc(MySpecial);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}