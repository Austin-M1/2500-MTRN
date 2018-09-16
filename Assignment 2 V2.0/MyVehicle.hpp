#ifndef MY_VEHICLE_H
#define MY_VEHICLE_H

#include "Vehicle.hpp"
#include "Shape.hpp"
#include "Messages.hpp"

class MyVehicle : public Vehicle
{
	
	VehicleModel Model;  //constructor X  //variable
public:
	MyVehicle();
	MyVehicle(VehicleModel vm);
	virtual ~MyVehicle() {} //destructor 
	virtual void draw();
	//the above draw is about drawing the code for the vehicle NOT for say the rectangular prism. 
	void fillShapes();
	//void getspeed();
	//virtual void drawSpokes();
};

//first check point is getting the three shapes. then you draw the vehicle. 
//


/*Struct shapeInit
{ shape type type;
shape paramenter params;  //specified above, UNION shape paramenter if it is a rectangular parameter go to shape parameter struct, look atht the rec t
//field the x , y , z field. if it happens to be a triangle, go to triangle field and go to alen, b leng etc.
//all these coors are described on moodle.
//still don't know what shape type means.
//its at the top of page 8. can be triangle, rect etc.
float xyz[3];  // can specify
flost rotation; //only 1 rotation, only in horizontal plane, not all.

flost rgb[3]; //can specify colour of that particular shape init objectt

*/
//look at page 8/12 of the assignment 
//when we design our vehicle we want all the data to conform to our vehicle
/*struct VehicleModel
{
int remoteID;
std::vector<ShapeInit> shapes;  //shapes is the name of the vector
//and it is a vector fo ShapeInit, it is a vector of 5 diffe
}; //in your own vehicle set it to zero,everyone elses vehicles
//set it 1, 2 , 3 4, 5, etc
//form a vehicle model by filling in our shapes in to this vector
//take shapes out of this vector and draw them.
//UNDERSTND PAGE 8 very clearly.
next rcreate these parts
*/
#endif