#pragma once
#include "Shape.hpp"

class Cylinder : public Shape {
private:
	float radius;
	float depth;
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