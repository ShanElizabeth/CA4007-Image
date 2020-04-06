#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
    //used for 3d matrix 
	glMatrixMode(GL_MODELVIEW); //controls relationship from object to viewer
	glLoadIdentity(); //gets rid of previous values, clean slate set = to identity matrix
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0); // to chnage the matrix 
    // eye point(view point) |direction of which youre looking down the z axis towards origin |up vector what we regard as up int his space
			// x ,y,  z  |x,y,z      | y axis set to 1 
	        //            looking at origin
	//on the z axis
	glutWireCube(0.5);
	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION); //edit projectionmatrix current matrix
	glLoadIdentity(); //cleans previous
//	glOrtho(-2.0,2.0,-2.0,2.0,0.3,5.0); //paralell perpendicular to new plane
	//position of left clipping pain, right , bottom, top, distance from eye to near, distance from eye to far clipping pain
	//distance has no impac twhen using paralell projection

	glFrustum(-1.0,1.0,-1.0,1.0,0.5,3.0);
//	gluPerspective(60,1.0,0.3,5.0);//makes further away object slook smaller -also frustrum
	// (view angle, aspect ratio,near distance to near plane, distance from far plane)
	glViewport(0,0,w,h);
	return;
}

void glutSpecialFunc(void (*func)(int key, int x, int y));

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