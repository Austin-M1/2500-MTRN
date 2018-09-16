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

TrigPrism::TrigPrism(double a_length, double b_length, double angle, double depth)
{
	Angle = angle * (PI/180); 
	Depth = depth;
	A_length = a_length;
	B_length = b_length;
}

void TrigPrism::draw()
{

	double BX = (-A_length / 2.0) + B_length*cos(Angle); 
	double BY = B_length*sin(Angle); 

	glPushMatrix();
	positionInGL(); 

	//Draw Trig prism bottom face
	glBegin(GL_QUADS);
	glVertex3f(A_length / 2.0, 0.0, Depth / 2.0);
	glVertex3f(-A_length / 2.0, 0.0, Depth / 2.0);
	glVertex3f(-A_length / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(A_length / 2.0, 0.0, -Depth / 2.0);
	glEnd();

	//Draw trig prism front face 
	glBegin(GL_QUADS);
	glVertex3f(BX, BY, -Depth / 2.0);
	glVertex3f(A_length / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(-A_length / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(BX, BY, -Depth / 2.0);
	glEnd();

	//Draw trig prism back face 
	glBegin(GL_QUADS);
	glVertex3f(BX, BY, Depth / 2.0);
	glVertex3f(A_length / 2.0, 0.0, Depth / 2.0);
	glVertex3f(-A_length / 2.0, 0.0, Depth / 2.0);
	glVertex3f(BX, BY, Depth / 2.0);
	glEnd();

	//Draw trig prism right face
	glBegin(GL_QUADS);
	glVertex3f(-A_length / 2.0, 0.0, Depth / 2.0);
	glVertex3f(-A_length / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(BX, BY, -Depth / 2.0);
	glVertex3f(BX, BY, Depth / 2.0);
	glEnd();

	//Draw trig prism left face 
	glBegin(GL_QUADS);
	glVertex3f(A_length / 2.0, 0.0, Depth / 2.0);
	glVertex3f(A_length / 2.0, 0.0, -Depth / 2.0);
	glVertex3f(BX, BY, -Depth / 2.0);
	glVertex3f(BX, BY, Depth / 2.0);
	glEnd();

	glPopMatrix(); 
	glFlush; 

}