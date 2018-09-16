
#ifndef RECTPRISM_H
#define RECTPRISM_H 

#include "Messages.hpp"
#include "Shape.hpp"

class RectPrism : public Shape {
protected:
	double X_length;  //length, or you could have called these xlen, ylen, zlen in order to avoid confusion like page 8 
	double Y_length; //height
	double Z_length;	//depth
public:
	RectPrism() {}
	RectPrism(double x_length, double y_length, double z_length);
	virtual ~RectPrism() {}; //descrtuctor, because it is part of the class heirarchy put virtual 
	virtual void draw();  //= 0;
						  //because you will be uding a pointer toa class abstract shape. 
						  //thats why u need void draw. 
	//pointer to the abstract class shape to draw all these things.



};
#endif