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

TrapPrism::TrapPrism(double alen, double blen, double height, double aoff, double depth)
{
	Alen = alen;
	Blen = blen;
	Depth = depth;
	Height = height;
	Aoff = aoff;
}

void TrapPrism::draw()
{

	glPushMatrix();
	setColorInGL();
	setColor(0, 0, 1);
	positionInGL();

	//top face
	glBegin(GL_QUADS);
	glVertex3f((-Alen / 2.0) + Aoff, Height, -Depth / 2.0);
	glVertex3f((-Alen / 2.0) + Aoff, Height, Depth / 2.0);
	glVertex3f(((-Alen / 2.0) + Aoff) + Blen, Height, Depth / 2.0);
	glVertex3f(((-Alen / 2.0) + Aoff) + Blen, Height, -Depth / 2.0);
	glEnd();

	//bottom face
	glBegin(GL_QUADS);
	glVertex3f(Alen / 2.0, 0.0, Depth / 2.0);
	glVertex3f(-Alen / 2.0, 0.0, Depth / 2.0);
	glVertex3f(-Alen / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(Alen / 2.0, 0.0, -Depth / 2.0);
	glEnd();

	//front face 
	glBegin(GL_QUADS);
	glVertex3f(Alen / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(((-Alen / 2.0) + Aoff) + Blen, Height, -Depth / 2.0);
	glVertex3f((-Alen / 2.0) + Aoff, Height, -Depth / 2.0);
	glVertex3f(-Alen / 2.0, 0.0, -Depth / 2.0);
	glEnd();

	//back face 
	glBegin(GL_QUADS);
	glVertex3f(Alen / 2.0, 0.0, Depth / 2.0);
	glVertex3f(((-Alen / 2.0) + Aoff) + Blen, Height, Depth / 2.0);
	glVertex3f((-Alen / 2.0) + Aoff, Height, Depth / 2.0);
	glVertex3f(-Alen / 2.0, 0.0, Depth / 2.0);
	glEnd();

	//left face
	glBegin(GL_QUADS);
	glVertex3f(Alen / 2.0, 0.0, Depth / 2.0);
	glVertex3f(((-Alen / 2.0) + Aoff) + Blen, Height, Depth / 2.0);
	glVertex3f(((-Alen / 2.0) + Aoff) + Blen, Height, -Depth / 2.0);
	glVertex3f(Alen / 2.0, 0.0, -Depth / 2.0);
	glEnd();

	//right face 
	glBegin(GL_QUADS);
	glVertex3f(-Alen / 2.0, 0.0, Depth / 2.0);
	glVertex3f((-Alen / 2.0) + Aoff, Height, Depth / 2.0);
	glVertex3f((-Alen / 2.0) + Aoff, Height, -Depth / 2.0);
	glVertex3f(-Alen / 2.0, 0.0, -Depth / 2.0);
	glEnd();

	glPopMatrix();
	glFlush;

}