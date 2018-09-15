#include <iostream>
#include "Shape.hpp"
#include "myVehicle.hpp"

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

myVehicle::myVehicle() {
	vX = 0;
	vY = 0;
	vZ = 0;
}

myVehicle::myVehicle(float _vX, float _vY, float _vZ) {
	vX = _vX;
	vY = _vY;
	vZ = _vZ;
}

float myVehicle::getVX() {
	return vX;
}

float myVehicle::getVY() {
	return vY;
}

float myVehicle::getVZ() {
	return vZ;
}


void myVehicle::setVX(float _vX) {
	vX = _vX;
}

void myVehicle::setVY(float _vY) {
	vY = _vY;
}

void myVehicle::setVZ(float _vZ) {
	vZ = _vZ;
}

void myVehicle::draw() {
	// move to the vehicle's local frame of reference
	glPushMatrix();
	positionInGL();
	// all the local drawing code
	// move back to global frame of reference
	glPopMatrix();
}

myVehicle::~myVehicle() {
	
	glPushMatrix();
	glTranslated(0,0,0);
	RectangularPrism CORE(20,5,10,0,0,0,1,1,0);
	CORE.draw();
	
	glTranslated(0, 0, 0);
	glRotated(0,1,1,1);
	RectangularPrism FRONT_HEAD_R(1,1,2,10,3,2.5,1,0,1);
	FRONT_HEAD_R.draw();
	
	glTranslated(0, 0, 0);
	glRotated(0, 1, 1, 1);
	RectangularPrism FRONT_HEAD_L(1, 1, 2, 10, 3, -2.5, 1, 0, 1);
	FRONT_HEAD_L.draw();

	glTranslated(0, 0, 0);
	glRotated(180,0,1,0);
	TrapezoidalPrism TOP(10,7,3,2,10,1,5,0,1,0,1);
	TOP.draw();

	glTranslated(0, 0, 0);
	glRotated(0, 1, 1, 1);
	Cylinder FRONT_TYRE_L(1, 1, 2, 10, 3, 2.5, 1, 1);
	FRONT_TYRE_L.draw();

	glPopMatrix();
}