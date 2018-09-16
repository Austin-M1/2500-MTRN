#ifdef __APPLE__
#include <OpenGL/gl.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#else
#include <GL/glut.h>
#endif


#include "Cylinder.hpp"
#include <iostream>
#include "Math.h"

#define PI 3.14159


Cylinder::Cylinder(double radius, double depth, bool IsRolling, bool IsSteering)
{
	Radius = radius; 
	Depth = depth;
	isRolling = IsRolling;
	isSteering =IsSteering; 
}

void Cylinder::draw()
{
	glPushMatrix();
	positionInGL();
	glTranslatef(0, Radius, 0); 
	setColorInGL();

	if (isSteering == FALSE && isRolling == TRUE) {

		glRotated(-Speed/5, 0, 0, 1);
	}

	if (isSteering == TRUE && isRolling == TRUE) {
		glRotated(-Steering, 0, 1, 0);
		glRotated(-Speed / 5, 0, 0, 1);
	}

	GLUquadric* Quad = gluNewQuadric();
	glTranslatef(0, 0, -(Depth / 2.0));

	gluCylinder(Quad, Radius, Radius, Depth, 5, 50);
	glRotatef(180, 1, 0, 0);
	gluDisk(Quad, 0.0f, Radius, 5, 1);
	glRotatef(180, 1, 0, 0); 
	glTranslatef(0.0f, 0.0f, Depth); 
	gluDisk(Quad, 0.0f, Radius, 5, 1); 
	glTranslatef(0.0f, 0.0f, Depth);
	glFlush();

	glPopMatrix();
	glFlush();

}


double Cylinder::getRadius()
{
	return Radius;
}


void Cylinder::setSpeed(double _speed)
{
	Speed = _speed; 

}

void Cylinder::setSteering(double _steering)
{
	Steering = _steering; 
}


