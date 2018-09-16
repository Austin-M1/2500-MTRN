#pragma once

#ifndef TRIANGULAR_PRISM_H
#define TRIANGULAR_PRISM_H

#include "Shape.hpp"

class TriangularPrism : public Shape {
private:
	float alen;
	float blen;
	float angle;
	float depth;

public:
	TriangularPrism();
	TriangularPrism(float _alen, float _blen, float _angle, float _depth, float _xPos, float _yPos, float _zPos, float R, float G, float B);

	float getALen();
	float getBLen();
	float getAngle();
	float getDepth();

	void setALen(float _alen);
	void setBLen(float _blen);
	void setAngle(float _angle);
	void setDepth(float _depth);

	virtual void draw();

	~TriangularPrism();
};

#endif
