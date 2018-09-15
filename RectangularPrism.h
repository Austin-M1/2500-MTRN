#pragma once
#include "Shape.hpp"
class RectangularPrism : public Shape {
private:
	float xlen; // length along x-axis
	float ylen; // length along y-axis
	float zlen; // length along z-axis

public:
	RectangularPrism();

	float getXLen();
	float getYLen();
	float getZLen();

	void setXLen(float _xlen);
	void setYLen(float _ylen);
	void setZLen(float _zlen);

	~RectangularPrism();
};