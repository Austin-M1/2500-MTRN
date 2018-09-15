#pragma once
#include "Shape.hpp"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "TrapezoidalPrism.hpp"
#include "Cylinder.hpp"
#include "Vehicle.hpp"

class myVehicle : public Vehicle {
private:
	float vX;
	float vY;
	float vZ;

public:
	myVehicle();
	myVehicle(float _vX, float _vY, float _vZ);

	float getVX();
	float getVY();
	float getVZ();

	void setVX(float _vX);
	void setVY(float _vY);
	void setVZ(float _vZ);

	virtual void draw();

	~myVehicle();
};