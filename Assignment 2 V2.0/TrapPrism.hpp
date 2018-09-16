#ifndef TRAPPRISM_H
#define TRAPPRISM_H 

#include "Messages.hpp"
#include "Shape.hpp"

class TrapPrism : public Shape {
protected:

	double Alen; // length of side A (bottom)
	double Blen; // length of side B (top)
	double Depth; // length along z-axis            
	double Height; // distance between side A and B 
	double Aoff; // distance A is shifted from B by, from the left
public:
	TrapPrism() {}
	TrapPrism(double alen, double blen, double height, double aoff, double depth);
	virtual ~TrapPrism() {};
	virtual void draw();

};
#endif
