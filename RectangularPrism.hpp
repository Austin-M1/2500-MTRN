#pragma once

#ifndef RECTANGULAR_PRISM_H
#define RECTANGULAR_PRISM_H

#include "Shape.hpp"

class RectangularPrism : public Shape {
private:
	float xlen; // length along x-axis
	float ylen; // length along y-axis
	float zlen; // length along z-axis

	//This stuff us unique to rectangularPrism. It defines it's dimensions. (x, y and z of Shape is the coordinates and orientation.

public:
	RectangularPrism();
	RectangularPrism(float _xlen, float _ylen, float _zlen, float xPos, float yPos, float zPos, float R, float G, float B);

	float getXLen();
	float getYLen();
	float getZLen();

	void setXLen(float _xlen);
	void setYLen(float _ylen);
	void setZLen(float _zlen);

	virtual void draw(); //vitrual, since Shape is a virtual function

	~RectangularPrism();

};

#endif