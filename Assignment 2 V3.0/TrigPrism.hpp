
#ifndef TRIGPRISM_H
#define TRIGPRISM_H 

#include "Messages.hpp"
#include "Shape.hpp"

class TrigPrism : public Shape {
protected:
	double A_length; // Side A length (bottom)
	double B_length; // Side B Length  (left)
	double Angle; // Angle (degrees) between side A and B
	double Depth; // length along z-axis
public:
	TrigPrism() {}
	TrigPrism(double a_length, double b_length, double angle, double depth);
	virtual void draw();
	virtual ~TrigPrism() {};    
						  
};
#endif
