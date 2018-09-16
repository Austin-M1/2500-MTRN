
#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.hpp"

class Cylinder : public Shape {
protected:

	double Radius;
	double Depth; 
	bool isSteering; 
	bool isRolling; 
	double Steering; 
	double Speed; 
	double Angle; 
	double Rotation; 
	double ElapsedTime; 

public:
	Cylinder() {}
	Cylinder(double radius, double depth, bool IsRolling, bool IsSteering);

	virtual ~Cylinder() {};
	virtual void draw();

	virtual void setSpeed(double _speed); 
	virtual void setSteering(double _steering); 
	virtual double getRadius(); 

};
#endif


