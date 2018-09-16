#ifdef __APPLE__
#include <OpenGL/gl.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#else
#include <GL/glut.h>
#endif


#include "Shape.hpp"
#include "RectPrism.hpp"


RectPrism::RectPrism(double x_length, double y_length, double z_length)
{
	X_length = x_length;
	Y_length = y_length;
	Z_length = z_length;
}

void RectPrism::draw()
{
	glPushMatrix();
	setColorInGL();
	positionInGL();

	// Draw Rect prism top face
	glBegin(GL_QUADS);  
	glVertex3f(X_length / 2.0, Y_length, Z_length / 2.0);
	glVertex3f(X_length / 2.0, Y_length, -Z_length / 2.0);
	glVertex3f(-X_length / 2.0, Y_length, -Z_length / 2.0);
	glVertex3f(-X_length / 2.0, Y_length, Z_length / 2.0);
	glEnd();

	//Draw Rect prism bottom face
	glBegin(GL_QUADS);
	glVertex3f(X_length / 2.0, 0.0, Z_length / 2.0);
	glVertex3f(X_length / 2.0, 0.0, -Z_length / 2.0);
	glVertex3f(-X_length / 2.0, 0.0, -Z_length / 2.0);
	glVertex3f(-X_length / 2.0, 0.0, Z_length / 2.0);
	glEnd();

	//Draw Rect prism back face
	glBegin(GL_QUADS);
	glVertex3f(X_length / 2.0, Y_length, Z_length / 2.0);
	glVertex3f(X_length / 2.0, Y_length, -Z_length / 2.0);
	glVertex3f(X_length / 2.0, 0.0, -Z_length / 2.0);
	glVertex3f(X_length / 2.0, 0.0, Z_length / 2.0);
	glEnd();

	//Draw Rect prism front face
	glBegin(GL_QUADS);
	glVertex3f(-X_length / 2.0, Y_length, Z_length / 2.0);
	glVertex3f(-X_length / 2.0, Y_length, -Z_length / 2.0);
	glVertex3f(-X_length / 2.0, 0.0, -Z_length / 2.0);
	glVertex3f(-X_length / 2.0, 0.0, Z_length / 2.0);
	glEnd();

	//Draw Rect prism left face
	glBegin(GL_QUADS);
	glVertex3f(X_length / 2.0, Y_length, Z_length / 2.0);
	glVertex3f(X_length / 2.0, 0.0, Z_length / 2.0);
	glVertex3f(-X_length / 2.0, 0.0, Z_length / 2.0);
	glVertex3f(-X_length / 2.0, Y_length, Z_length / 2.0);
	glEnd();

	//Draw Rect prism right face
	glBegin(GL_QUADS);
	glVertex3f(X_length / 2.0, Y_length, -Z_length / 2.0);
	glVertex3f(X_length / 2.0, 0.0, -Z_length / 2.0);
	glVertex3f(-X_length / 2.0, 0.0, -Z_length / 2.0);
	glVertex3f(-X_length / 2.0, Y_length, -Z_length / 2.0);
	glEnd();
	glPopMatrix(); 
	glFlush();
}
