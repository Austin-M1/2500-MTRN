#include <iostream>
#include "RectangularPrism.hpp"
#include "Shape.hpp"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <unistd.h>
#include <sys/time.h>
#elif defined(WIN32)
#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <sys/time.h>
#endif

using namespace std;

RectangularPrism::RectangularPrism() {
	xlen = 0.0;
	ylen = 0.0;
	zlen = 0.0;
	
	x = 0;
	y = 0;
	z = 0;

}

RectangularPrism::RectangularPrism(float _xlen, float _ylen, float _zlen, float xPos, float yPos, float zPos, float R, float G, float B) {
	xlen = _xlen;
	ylen = _ylen;
	zlen = _zlen;

	x = xPos;
	y = yPos;
	z = zPos;

	red = R;
	green = G;
	blue = B;

	setColor(R, G, B);
}

//Getters
float RectangularPrism::getXLen() {
	return xlen;
}

float RectangularPrism::getYLen() {
	return ylen;
}

float RectangularPrism::getZLen() {
	return zlen;
}

//Setters
void RectangularPrism::setXLen(float _xlen) {
	xlen = _xlen;
}

void RectangularPrism::setYLen(float _ylen) {
	ylen = _ylen;
}

void RectangularPrism::setZLen(float _zlen) {
	zlen = _zlen;
}

void RectangularPrism::draw() {
	glPushMatrix();
	setColorInGL();
	positionInGL();
	glBegin(GL_QUADS);

	//There are 6 faces right? so 4x glVertex3d for each face
	
	//FRONT
	glVertex3d(-xlen / 2, 0, zlen / 2); 
	glVertex3d(-xlen / 2, ylen, zlen / 2);
	glVertex3d(xlen / 2, ylen, zlen / 2);
	glVertex3d(xlen / 2, 0, zlen / 2);

	//BACK
	glVertex3d(-xlen / 2, 0, -zlen / 2);  
	glVertex3d(-xlen / 2, ylen, -zlen / 2);
	glVertex3d(xlen / 2, ylen, -zlen / 2);
	glVertex3d(xlen / 2, 0, -zlen / 2);

	//TOP
	glVertex3d(-xlen / 2, ylen, -zlen / 2);  
	glVertex3d(-xlen / 2, ylen, zlen / 2);
	glVertex3d(xlen / 2, ylen, zlen / 2);
	glVertex3d(xlen / 2, ylen, -zlen / 2);

	//BOTTOM
	glVertex3d(-xlen / 2, 0, -zlen / 2); 
	glVertex3d(-xlen / 2, 0, zlen / 2);
	glVertex3d(xlen / 2, 0, zlen / 2);
	glVertex3d(xlen / 2, 0, -zlen / 2);

	//PORT
	glVertex3d(-xlen / 2, 0, -zlen / 2); 
	glVertex3d(-xlen / 2, 0, zlen / 2);
	glVertex3d(-xlen / 2, ylen, zlen / 2);
	glVertex3d(-xlen / 2, ylen, -zlen / 2);

	//STARBOARD
	glVertex3d(xlen / 2, 0, -zlen / 2); 
	glVertex3d(xlen / 2, 0, zlen / 2);
	glVertex3d(xlen / 2, ylen, zlen / 2);
	glVertex3d(xlen / 2, ylen, -zlen / 2);

	glEnd();
	glPopMatrix();
}

//Destructor
RectangularPrism::~RectangularPrism() {

}
