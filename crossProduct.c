#include <GL/gl.h>
#include <GL/glext.h>
#include <H:/glut.h>
#include <math.h>


void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,3.0,0.0,0.0,0.0,0.0,1.0,0.0);
	
	GLfloat u1, u2, u3, v1, v2, v3, theta, mag;
	u1=0.0;
	u2=0.0;
	u3=1.0;
	v1=1.0/ sqrt(2.0);
	v2=0.0/ sqrt(2.0);
	v3=1.0/sqrt(2.0);
	GLfloat uvi, uvj, uvk;
    uvi = u2 * v3 - v2 * u3;
    uvj = v1 * u3 - u1 * v3;
    uvk = u1 * v2 - v1 * u2;
	mag = sqrt(uvi*uvi + uvj*uvj + uvk*uvk);
	theta = asin(mag) * 180 / M_PI;
	
	glRotatef(theta, uvi,uvj,uvk);
	glutWireCube(0.5);
	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2.0,2.0,-2.0,2.0,0.3,5.0);
//	glFrustum(-1.0,1.0,-1.0,1.0,9.5,12.0);
	gluPerspective(60,1.0,0.3,10.0);
	glViewport(0,0,w,h);
	return;
}




int main(int argc, char **argv)
{
	
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);


	glutMainLoop();
}