#include <iostream>
#include "Shape.hpp"
#include "TrapezoidalPrism.hpp"

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

TrapezoidalPrism::TrapezoidalPrism() {
	alen = 0;
	blen = 0;
	height = 0;
	aoff = 0;
	depth = 0;

	x = 0;
	y = 0; 
	z = 0;
}

TrapezoidalPrism::TrapezoidalPrism(float _alen, float _blen, float _height, float _aoff, float _depth, float xPos, float yPos, float zPos, float R, float G, float B) {
	alen = _alen;
	blen = _blen;
	height = _height;
	aoff = _aoff;
	depth = _depth;

	x = xPos;
	y = yPos;
	z = zPos;

	setColor(R, G, B);
}

float TrapezoidalPrism::getALen() {
	return alen;
}

float TrapezoidalPrism::getBLen() {
	return blen;
}

float TrapezoidalPrism::getHeight() {
	return height;
}

float TrapezoidalPrism::getAOff() {
	return aoff;
}

float TrapezoidalPrism::getDepth() {
	return depth;
}

void TrapezoidalPrism::setALen(float _alen) {
	alen = _alen;
}

void TrapezoidalPrism::setBLen(float _blen) {
	blen = _blen;
}

void TrapezoidalPrism::setHeight(float _height) {
	height = _height;
}

void TrapezoidalPrism::setAOff(float _aoff) {
	aoff = _aoff;
}

void TrapezoidalPrism::setDepth(float _depth) {
	depth = _depth;
}

void TrapezoidalPrism::draw() {
	glPushMatrix();
	setColorInGL();
	positionInGL();
	glBegin(GL_QUADS);

	//FRONT
	glVertex3d(alen/2, 0, -depth/2);
	glVertex3d(blen/2,height,-depth/2);
	glVertex3d(blen/2,height,depth/2);
	glVertex3d(alen/2,0,depth/2);

	//BACK
	glVertex3d(-alen/2,0,-depth/2);
	glVertex3d(-blen/2+aoff,height,-depth/2);
	glVertex3d(-blen/2+aoff,height,depth/2);
	glVertex3d(-alen/2,0,depth/2);

	//TOP
	glVertex3d(blen/2,height,-depth/2);
	glVertex3d(-blen/2+aoff,height,-depth/2);
	glVertex3d(-blen/2+aoff,height,depth/2);
	glVertex3d(blen/2,height,depth/2);

	//BOTTOM
	glVertex3d(alen/2,0,-depth/2);
	glVertex3d(-alen/2,0,-depth/2);
	glVertex3d(-alen/2,0,depth/2);
	glVertex3d(alen/2,0,depth/2);

	//LEFT
	glVertex3d(alen/2,0,depth/2);
	glVertex3d(-alen/2,0,depth/2);
	glVertex3d(-blen/2+aoff,height,depth/2);
	glVertex3d(blen/2,height,depth/2);

	//RIGHT
	glVertex3d(alen/2,0,-depth/2);
	glVertex3d(-alen/2,0,-depth/2);
	glVertex3d(-blen/2+aoff,height,-depth/2);
	glVertex3d(blen/2,height,-depth/2);

	glEnd();
	glPopMatrix;
}

TrapezoidalPrism::~TrapezoidalPrism() {

}
