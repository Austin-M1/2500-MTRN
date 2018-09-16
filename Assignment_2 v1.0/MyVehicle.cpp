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

#include <vector>
#include <iostream>
#include "MyVehicle.hpp"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "TrapezoidalPrism.hpp"
#include "Cylinder.hpp"

#define PI 3.14159

using namespace std;

myVehicle::myVehicle() {
	ShapeInit part;
	vX = 0;
	vY = 0;
	vZ = 0;
	fillShapes();
}

myVehicle::myVehicle(float _vX, float _vY, float _vZ) {
	vX = _vX;
	vY = _vY;
	vZ = _vZ;
}

myVehicle::myVehicle(VehicleModel vm) {
	Model = vm;
	fillShapes();
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

void myVehicle::fillShapes() {
		Shape *sh; //pointer to the shape, base 
		shapes.clear();
		int i = 0;
		//pointer to each object 
		for (std::vector<ShapeInit>::iterator iter = Model.shapes.begin(); iter != Model.shapes.end(); ++iter)
		{
			
			switch (iter->type) //look at pointer and ask for type could be cylinder, rectangle etc 
			{
			case RECTANGULAR_PRISM_H:
				sh = new RectangularPrism(iter->params.rect.xlen, iter->params.rect.ylen, iter->params.rect.zlen, x, y, z, red, green, blue);
				break;

			case TRIANGULAR_PRISM_H:
				sh = new TriangularPrism(iter->params.tri.alen, iter->params.tri.blen, iter->params.tri.angle, iter->params.tri.depth, x, y, z, red, green, blue);
				break;

			case TRAPEZOIDAL_PRISM_H:
				sh = new TrapezoidalPrism(iter->params.trap.alen, iter->params.trap.blen, iter->params.trap.height, iter->params.trap.aoff, iter->params.trap.depth, x, y, z, red, green, blue);
				break;

			case CYLINDER_H:
				sh = new Cylinder(iter->params.cyl.radius, iter->params.cyl.depth, x, y, z, red, green, blue);
				break;  //need to make sure if turning, stationary or other cylinder 

			} 
	
			//all elements added to array
			sh->setColor(iter->rgb[0], iter->rgb[1], iter->rgb[2]);
			sh->setPosition(iter->xyz[0], iter->xyz[1], iter->xyz[2]);
			addShape(sh);

			i++;
		}
}

void myVehicle::draw() {
	ShapeInit part;

	glPushMatrix();
	glTranslated(0, 0, 0);
	RectangularPrism CORE(20, 3.5, 10, 0, 1.5, 0, 1, 1, 0);
	CORE.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	RectangularPrism FRONT_GRILLE(1, 1.5, 4, 10, 3, 0, 0, 1, 0);
	FRONT_GRILLE.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	RectangularPrism FRONT_BUMPER(1, 1, 8, 10, 1.5, 0, 0, 0, 0);
	FRONT_BUMPER.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	RectangularPrism REAR_BUMPER(1, 1, 8, -10, 1.5, 0, 0, 0, 0);
	REAR_BUMPER.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 1, 1, 1);
	RectangularPrism FRONT_HEAD_R(1, 1, 2, 10, 3.5, 3.5, 1, 1, 1);
	FRONT_HEAD_R.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 1, 1, 1);
	RectangularPrism REAR_HEAD_R(1, 1, 2, -10, 3.5, 3.5, 1, 0, 0);
	REAR_HEAD_R.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 1, 1, 1);
	RectangularPrism FRONT_HEAD_L(1, 1, 2, 10, 3.5, -3.5, 1, 1, 1);
	FRONT_HEAD_L.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 1, 1, 1);
	RectangularPrism REAR_HEAD_L(1, 1, 2, -10, 3.5, -3.5, 1, 0, 0);
	REAR_HEAD_L.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(180, 0, 1, 0);
	TrapezoidalPrism TOP(10, 7, 3, 2, 10, 1, 5, 0, 1, 1, 0);
	TOP.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(180, 1, 0, 0);
	glRotated(180, 1, 0, 0);
	TrapezoidalPrism WINDSCREEN_BACK(12, 9, 3, 2.5, 9, 0.5, 4.5, 0, 1, 1, 1);
	WINDSCREEN_BACK.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glRotated(180, 1, 0, 0);
	glRotated(180, 1, 0, 0);
	TrapezoidalPrism SIDE_WINDOWS(8.5, 6, 2, 2.5, 10.5, 0.5, 5, 0, 1, 1, 1);
	SIDE_WINDOWS.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 1, 1, 1);
	Cylinder FRONT_TYRE_R(2, 1.5, -6.5, 2, -4.5, 0, 0, 0);
	FRONT_TYRE_R.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 1, 1, 1);
	Cylinder FRONT_TYRE_RR(1, 1.5, -6.5, 2, -4.6, 1, 1, 1);
	FRONT_TYRE_RR.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	RectangularPrism FRONT_TYRE_RBAR(1.5, 0.5, 1, -6.5, 1.75, -5, 1, 0, 0);
	FRONT_TYRE_RBAR.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 0, 0, 0);
	Cylinder FRONT_TYRE_L(2, 1.5, -5.5, 2, 4.5, 0, 0, 0);
	FRONT_TYRE_L.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 0, 0, 0);
	Cylinder FRONT_TYRE_LR(1, 1.5, -5.5, 2, 4.6, 1, 1, 1);
	FRONT_TYRE_LR.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	RectangularPrism FRONT_TYRE_LBAR(1.5, 0.5, 1, -5.5, 1.75, 5, 1, 0, 0);
	FRONT_TYRE_LBAR.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 1, 1, 1);
	Cylinder REAR_TYRE_R(2, 1.5, 5.5, 2, -4.5, 0, 0, 0);
	REAR_TYRE_R.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 1, 1, 1);
	Cylinder REAR_TYRE_RR(1, 1.5, 5.5, 2, -4.6, 1, 1, 1);
	REAR_TYRE_RR.draw();
	glPopMatrix();
	Model.shapes.push_back(part);
	
	glPushMatrix();
	glTranslated(0, 0, 0);
	RectangularPrism REAR_TYRE_RBAR(1.5, 0.5, 1, 5.5, 1.75, -5, 1, 0, 0);
	REAR_TYRE_RBAR.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 1, 1, 1);
	Cylinder REAR_TYRE_L(2, 1.5, 5.5, 2, 4.5, 0, 0, 0);
	REAR_TYRE_L.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(0, 1, 1, 1);
	Cylinder REAR_TYRE_LR(1, 1.5, 5.5, 2, 4.6, 1, 1, 1);
	REAR_TYRE_LR.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	RectangularPrism REAR_TYRE_LBAR(1.5, 0.5, 1, 5.5, 1.75, 5, 1, 0, 0);
	REAR_TYRE_LBAR.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	glPushMatrix();
	glTranslated(0, 0, 0);
	glRotated(20, 0, 0, 0);
	TriangularPrism SPOILER(1, 1.5, 20, 6, 10, 4.5, 0, 1, 0, 0);
	SPOILER.draw();
	glPopMatrix();
	Model.shapes.push_back(part);

	//glline and glcircle

	glPopMatrix();
}

myVehicle::~myVehicle() {
	
}
