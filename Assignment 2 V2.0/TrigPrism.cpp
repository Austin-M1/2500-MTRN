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
#include "TrigPrism.hpp"
#include "Math.h"

#define PI 3.14159

TrigPrism::TrigPrism(double alen, double blen, double angle, double depth)
{
	Alen = alen; 
	Blen = blen;
	Angle = angle * (PI / 180);
	Depth = depth;
}

void TrigPrism::draw()
{

	double BX = (-Alen / 2.0) + Blen * cos(Angle);
	double BY = Blen * sin(Angle);

	glPushMatrix();
	setColorInGL();
	setColor(0, 1, 0);
	positionInGL();

	//bottom face
	glBegin(GL_QUADS);
	glVertex3f(Alen / 2.0, 0.0, Depth / 2.0);
	glVertex3f(-Alen / 2.0, 0.0, Depth / 2.0);
	glVertex3f(-Alen / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(Alen / 2.0, 0.0, -Depth / 2.0);
	glEnd();

	//front face 
	glBegin(GL_QUADS);
	glVertex3f(BX, BY, -Depth / 2.0);
	glVertex3f(Alen / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(-Alen / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(BX, BY, -Depth / 2.0);
	glEnd();

	//back face 
	glBegin(GL_QUADS);
	glVertex3f(BX, BY, Depth / 2.0);
	glVertex3f(Alen / 2.0, 0.0, Depth / 2.0);
	glVertex3f(-Alen / 2.0, 0.0, Depth / 2.0);
	glVertex3f(BX, BY, Depth / 2.0);
	glEnd();

	//right face
	glBegin(GL_QUADS);
	glVertex3f(-Alen / 2.0, 0.0, Depth / 2.0);
	glVertex3f(-Alen / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(BX, BY, -Depth / 2.0);
	glVertex3f(BX, BY, Depth / 2.0);
	glEnd();

	//left face 
	glBegin(GL_QUADS);
	glVertex3f(Alen / 2.0, 0.0, Depth / 2.0);
	glVertex3f(Alen / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(BX, BY, -Depth / 2.0);
	glVertex3f(BX, BY, Depth / 2.0);
	glEnd();

	glPopMatrix();
	glFlush;

}