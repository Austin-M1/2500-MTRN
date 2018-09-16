#pragma once

#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.hpp"

class Cylinder : public Shape {
private:
	float radius;
	float depth;
	bool isRolling;
	bool isSteering;
public:
	Cylinder();
	Cylinder(float _radius, float _depth, float xPos, float yPos, float zPos, float R, float G, float B);

	float getRadius();
	float getDepth();

	void setRadius(float _radius);
	void setDepth(float _depth);

	virtual void draw();

	~Cylinder();
};

#endif