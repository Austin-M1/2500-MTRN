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


RectPrism::RectPrism(double xlen, double ylen, double zlen)
{
	Xlen = xlen; 
	Ylen = ylen;
	Zlen = zlen;

}

void RectPrism::draw()
{
	glPushMatrix();
	setColorInGL();
	setColor(1, 0, 0);
	positionInGL();

	// top face
	glBegin(GL_QUADS);
	glVertex3f(Xlen / 2.0, Ylen, Zlen / 2.0);
	glVertex3f(Xlen / 2.0, Ylen, -Zlen / 2.0);
	glVertex3f(-Xlen / 2.0, Ylen, -Zlen / 2.0);
	glVertex3f(-Xlen / 2.0, Ylen, Zlen / 2.0);
	glEnd();

	//bottom face
	glBegin(GL_QUADS);
	glVertex3f(Xlen / 2.0, 0.0, Zlen / 2.0);
	glVertex3f(Xlen / 2.0, 0.0, -Zlen / 2.0);
	glVertex3f(-Xlen / 2.0, 0.0, -Zlen / 2.0);
	glVertex3f(-Xlen / 2.0, 0.0, Zlen / 2.0);
	glEnd();

	//back face
	glBegin(GL_QUADS);
	glVertex3f(Xlen / 2.0, Ylen, Zlen / 2.0);
	glVertex3f(Xlen / 2.0, Ylen, -Zlen / 2.0);
	glVertex3f(Xlen / 2.0, 0.0, -Zlen / 2.0);
	glVertex3f(Xlen / 2.0, 0.0, Zlen / 2.0);
	glEnd();

	//front face
	glBegin(GL_QUADS);
	glVertex3f(-Xlen / 2.0, Ylen, Zlen / 2.0);
	glVertex3f(-Xlen / 2.0, Ylen, -Zlen / 2.0);
	glVertex3f(-Xlen / 2.0, 0.0, -Zlen / 2.0);
	glVertex3f(-Xlen / 2.0, 0.0, Zlen / 2.0);
	glEnd();

	//left face
	glBegin(GL_QUADS);
	glVertex3f(Xlen / 2.0, Ylen, Zlen / 2.0);
	glVertex3f(Xlen / 2.0, 0.0, Zlen / 2.0);
	glVertex3f(-Xlen / 2.0, 0.0, Zlen / 2.0);
	glVertex3f(-Xlen / 2.0, Ylen, Zlen / 2.0);
	glEnd();

	//right face
	glBegin(GL_QUADS);
	glVertex3f(Xlen / 2.0, Ylen, -Zlen / 2.0);
	glVertex3f(Xlen / 2.0, 0.0, -Zlen / 2.0);
	glVertex3f(-Xlen / 2.0, 0.0, -Zlen / 2.0);
	glVertex3f(-Xlen / 2.0, Ylen, -Zlen / 2.0);
	glEnd();
	glPopMatrix();
	glFlush();
}
