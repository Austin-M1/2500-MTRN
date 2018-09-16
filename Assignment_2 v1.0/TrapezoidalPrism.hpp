#pragma once

#ifndef TRAPEZOIDAL_PRISM_H
#define TRAPEZOIDAL_PRISM_H

#include "Shape.hpp"

class TrapezoidalPrism : public Shape {
private:
	float alen;
	float blen;
	float height;
	float aoff;
	float depth;

public:
	TrapezoidalPrism();
	TrapezoidalPrism(float _alen, float _blen, float _height, float _aoff, float _depth, float xPos, float yPos, float zPos, float R, float G, float B);

	float getALen();
	float getBLen();
	float getHeight();
	float getAOff();
	float getDepth();

	void setALen(float _alen);
	void setBLen(float _blen);
	void setHeight(float _height);
	void setAOff(float _aoff);
	void setDepth(float _depth);

	virtual void draw();

	~TrapezoidalPrism();
};

#endif
