
#ifndef TRAPPRISM_H
#define TRAPPRISM_H 

#include "Messages.hpp"
#include "Shape.hpp"

class TrapPrism : public Shape {
protected:

	double A_length; // side A Length (bottom)
	double B_length; // side B length (top)
	double Depth; // z-axis length           
	double Height; // distance between side A & B 
	double Aoff; // distance A is shifted from B by, from the left
public:
	TrapPrism() {}
	TrapPrism(double a_length, double b_length, double height, double aoff, double depth);  
	virtual void draw();  
	virtual ~TrapPrism() {};
};
#endif
