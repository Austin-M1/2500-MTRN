#include <iostream>
#include "TriangularPrism.hpp"
#include "Shape.hpp"
#include <math.h>

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

TriangularPrism::TriangularPrism() {
	alen = 0.0;
	blen = 0.0;
	angle = 0.0;
	depth = 0.0;

	x = 0;
	y = 0;
	z = 0; 
}

TriangularPrism::TriangularPrism(float _alen, float _blen, float _angle, float _depth, float xPos, float yPos, float zPos, float R, float G, float B) {
	alen = _alen;
	blen = _blen;
	angle = _angle;
	depth = _depth;

	x = xPos;
	y = yPos;
	z = zPos;

	setColor(R, G, B);
}

float TriangularPrism::getALen() {
	return alen;
}

float TriangularPrism::getBLen() {
	return blen;
}

float TriangularPrism::getAngle() {
	return angle;
}

float TriangularPrism::getDepth() {
	return depth;
}

void TriangularPrism::setALen(float _alen) {
	alen = _alen;
}

void TriangularPrism::setBLen(float _blen) {
	blen = _blen;
}

void TriangularPrism::setAngle(float _angle) {
	angle = _angle;
}


void TriangularPrism::setDepth(float _depth) {
	depth = _depth;
}

void TriangularPrism::draw() {
	glPushMatrix();
	setColorInGL();
	positionInGL();
	glBegin(GL_QUADS);

	//BOTTOM
	glVertex3d(alen / 2, 0, -depth / 2);
	glVertex3d(alen / 2, 0, -depth / 2);
	glVertex3d(-alen / 2, 0, depth / 2);
	glVertex3d(alen / 2, 0, depth / 2);

	//TOP
	glVertex3d(alen / 2, 0, -depth / 2);
	glVertex3d(alen / 2, 0, depth / 2);
	glVertex3d(-alen / 2 + blen * cos(angle), blen*sin(angle), depth / 2);
	glVertex3d(-alen / 2 + blen * cos(angle), blen*sin(angle), -depth / 2);

	//STARBOARD
	glVertex3d(-alen / 2, 0, -depth / 2);
	glVertex3d(-alen / 2, 0, depth / 2);
	glVertex3d(-alen / 2 + blen * cos(angle), blen*sin(angle), depth / 2);
	glVertex3d(-alen / 2 + blen * cos(angle), blen*sin(angle), -depth / 2);

	//BACK
	glVertex3d(-alen / 2, 0, depth / 2); 
	glVertex3d(alen / 2, 0, depth / 2);
	glVertex3d(alen / 2, 0, depth / 2);
	glVertex3d(-alen / 2 + blen * cos(angle), blen*sin(angle), depth / 2);

	//FRONT
	glVertex3d(alen / 2, 0, -depth / 2);
	glVertex3d(-alen / 2, 0, -depth / 2);
	glVertex3d(-alen / 2, 0, -depth / 2);
	glVertex3d(-alen / 2 + blen * cos(angle), blen*sin(angle), -depth / 2);

	glEnd();
	glPopMatrix();
}

TriangularPrism::~TriangularPrism() {

}