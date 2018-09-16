#include <iostream>
#include "Shape.hpp"
#include "Cylinder.hpp"

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

Cylinder::Cylinder() {
	radius = 0;
	depth = 0;
}

Cylinder::Cylinder(float _radius, float _depth, float xPos, float yPos, float zPos, float R, float G, float B) {
	radius = _radius;
	depth = _depth;

	x = xPos;
	y = yPos;
	z = zPos;

	red = R;
	green = G;
	blue = B;
}

float Cylinder::getRadius() {
	return radius;
}

float Cylinder::getDepth() {
	return depth;
}

void Cylinder::setRadius(float _radius) {
	radius = _radius;
}

void Cylinder::setDepth(float _depth) {
	depth = _depth;
}

void Cylinder::draw() {
	glPushMatrix();
	setColorInGL();
	positionInGL();

	GLUquadric* Quad = gluNewQuadric();
	glTranslatef(0, 0, -(depth / 2.0));

	gluCylinder(Quad, radius, radius, depth, 20, 50);
	glRotatef(180, 1, 0, 0);
	gluDisk(Quad, 0.0f, radius, 20, 1);
	glRotatef(180, 1, 0, 0);
	glTranslatef(0.0f, 0.0f, depth);
	gluDisk(Quad, 0.0f, radius, 20, 1);
	glTranslatef(0.0f, 0.0f, depth);
	glFlush();

	glEnd();
	glPopMatrix();
}

Cylinder::~Cylinder() {

}
