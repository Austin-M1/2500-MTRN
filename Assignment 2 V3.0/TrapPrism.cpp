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
#include "TrapPrism.hpp"
#include "Math.h"

#define PI 3.14159

TrapPrism::TrapPrism(double a_length, double b_length, double height, double aoff, double depth)
{
	A_length = a_length; 
	B_length = b_length;
	Depth = depth;
	Height = height; 
	Aoff = aoff; 
}

void TrapPrism::draw()
{

	glPushMatrix();
	setColorInGL();
	positionInGL();

	//draw trap prism top face
	glBegin(GL_QUADS); 
	glVertex3f((-A_length / 2.0) + Aoff, Height, -Depth / 2.0);
	glVertex3f((-A_length / 2.0) + Aoff, Height, Depth / 2.0);
	glVertex3f(((-A_length / 2.0) + Aoff) + B_length, Height, Depth / 2.0);
	glVertex3f(((-A_length / 2.0) + Aoff) + B_length, Height, -Depth / 2.0);
	glEnd();

	//draw trap prism bottom face
	glBegin(GL_QUADS);
	glVertex3f(A_length / 2.0, 0.0, Depth / 2.0);
	glVertex3f(-A_length / 2.0, 0.0, Depth / 2.0);
	glVertex3f(-A_length / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(A_length / 2.0, 0.0, -Depth / 2.0);
	glEnd();

	//draw trap prism front face 
	glBegin(GL_QUADS);
	glVertex3f(A_length / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(((-A_length / 2.0) + Aoff) + B_length, Height, -Depth / 2.0);
	glVertex3f((-A_length / 2.0) + Aoff, Height, -Depth / 2.0);                
	glVertex3f(-A_length / 2.0, 0.0, -Depth / 2.0);
	glEnd();

	//draw trap prism back face 
	glBegin(GL_QUADS);
	glVertex3f(A_length / 2.0, 0.0, Depth / 2.0);
	glVertex3f(((-A_length / 2.0) + Aoff) + B_length, Height, Depth / 2.0);
	glVertex3f((-A_length / 2.0) + Aoff, Height, Depth / 2.0);
	glVertex3f(-A_length / 2.0, 0.0, Depth / 2.0);
	glEnd();

	//drwa trap prism left face
	glBegin(GL_QUADS);
	glVertex3f(A_length / 2.0, 0.0, Depth / 2.0);
	glVertex3f(((-A_length / 2.0) + Aoff) + B_length, Height, Depth / 2.0);
	glVertex3f(((-A_length / 2.0) + Aoff) + B_length, Height, -Depth / 2.0);
	glVertex3f(A_length / 2.0, 0.0, -Depth / 2.0);
	glEnd();

	//draw trap prism right face 
	glBegin(GL_QUADS);
	glVertex3f(-A_length / 2.0, 0.0, Depth / 2.0);
	glVertex3f((-A_length / 2.0) + Aoff, Height, Depth / 2.0);
	glVertex3f((-A_length / 2.0) + Aoff, Height, -Depth / 2.0);
	glVertex3f(-A_length / 2.0, 0.0, -Depth / 2.0);
	glEnd();

	glPopMatrix(); 
	glFlush;

}