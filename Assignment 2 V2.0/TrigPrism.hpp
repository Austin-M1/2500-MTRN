
#ifndef TRIGPRISM_H
#define TRIGPRISM_H 

#include "Messages.hpp"
#include "Shape.hpp"

class TrigPrism : public Shape {
protected:
	double Alen; // length of side A (bottom part of shape)
	double Blen; // length of side B (left)
	double Angle; // angle (degrees) between side A and B
	double Depth; // length along z-axis
public:
	TrigPrism() {}
	TrigPrism(double alen, double blen, double angle, double depth);
	virtual ~TrigPrism() {};  
	virtual void draw();  

};
#endif
