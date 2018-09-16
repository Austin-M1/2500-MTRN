#pragma once

#ifndef MY_VEHICLE
#define MY_VEHICLE

#include "Shape.hpp"
#include "Vehicle.hpp"
#include "Messages.hpp"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "TrapezoidalPrism.hpp"
#include "Cylinder.hpp"

class myVehicle : public Vehicle {
private:
	float vX;
	float vY;
	float vZ;

public:
	myVehicle();
	myVehicle(float _vX, float _vY, float _vZ);
	myVehicle(VehicleModel vm);

	float getVX();
	float getVY();
	float getVZ();

	void setVX(float _vX);
	void setVY(float _vY);
	void setVZ(float _vZ);

	//Need to write a function to make the thing move
	void fillShapes();

	VehicleModel Model;

	virtual void draw();
	virtual ~myVehicle();

};

#endif
