#ifdef __APPLE__
#include <OpenGL/gl.h> 
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h> 
#include <GL/glut.h> 
#else 
#include <GL/glut.h> 
#endif

#include "MyVehicle.hpp"
#include "RectPrism.hpp"
#include "TrigPrism.hpp"
#include "TrapPrism.hpp"
#include "Cylinder.hpp"
#include "Shape.hpp"
#include "Messages.hpp"
#include <vector>
#include <iostream>

using namespace std;

#define PI 3.14159

using namespace std; 


MyVehicle::MyVehicle()
{
	ShapeInit part;  
	 
	//= 0 because your vehicle. 
	Model.remoteID = 0;             

	//Vehicle Base 
	part.type = RECTANGULAR_PRISM;
	part.params.rect.xlen = 3.74;
	part.params.rect.ylen = 0.43;
	part.params.rect.zlen = 1.41;
	part.rgb[0] = 0.6;
	part.rgb[1] = 0.6;
	part.rgb[2] = 0.0;
	part.rotation = 0.0; 
	part.xyz[0] = 0.0;
	part.xyz[1] = 0.2;
	part.xyz[2] = 0.0;
	Model.shapes.push_back(part);

	//Right Front wheel
	part.type = CYLINDER;
	part.params.cyl.isRolling = TRUE; 
	part.params.cyl.isSteering = TRUE; 
	part.params.cyl.radius = 0.42;
	part.params.cyl.depth = 0.19;
	part.rgb[0] = 0.2;
	part.rgb[1] = 0.2;
	part.rgb[2] = 0.2;
	part.rotation = 0.0; 
	part.xyz[0] = 1.28;
	part.xyz[1] = 0.0;
	part.xyz[2] = 0.705;
	Model.shapes.push_back(part);

	//Left Front Wheel
	part.type = CYLINDER;
	part.params.cyl.isRolling = TRUE;
	part.params.cyl.isSteering = TRUE;
	part.params.cyl.radius = 0.42;
	part.params.cyl.depth = 0.19;
	part.rgb[0] = 0.2;
	part.rgb[1] = 0.2;
	part.rgb[2] = 0.2;
	part.rotation = 0.0; 
	part.xyz[0] = 1.28;
	part.xyz[1] = 0.0;
	part.xyz[2] = -0.705;
	Model.shapes.push_back(part);

	//Left Back Wheel
	part.type = CYLINDER;
	part.params.cyl.isRolling = TRUE;
	part.params.cyl.isSteering = FALSE;
	part.params.cyl.radius = 0.42;
	part.params.cyl.depth = 0.19;
	part.rgb[0] = 0.2;
	part.rgb[1] = 0.2;
	part.rgb[2] = 0.2;
	part.rotation = 0.0; 
	part.xyz[0] = -1.04;
	part.xyz[1] = 0.0;
	part.xyz[2] = -0.705;
	Model.shapes.push_back(part);

	//Right Back Wheel
	part.type = CYLINDER;
	part.params.cyl.isRolling = TRUE;
	part.params.cyl.isSteering = FALSE;
	part.params.cyl.radius = 0.42;
	part.params.cyl.depth = 0.19;
	part.rgb[0] = 0.2;
	part.rgb[1] = 0.2;
	part.rgb[2] = 0.2;
	part.rotation = 0.0; 
	part.xyz[0] = -1.04;
	part.xyz[1] = 0.0;
	part.xyz[2] = 0.705;
	Model.shapes.push_back(part);

	//Shoulder/torso/Car Windscreen
	part.type = TRAPEZOIDAL_PRISM;
	part.params.trap.alen = 1.61;
	part.params.trap.blen = 0.51;
	part.params.trap.height = 0.4;
	part.params.trap.aoff = 0.55;
	part.params.trap.depth = 1.41;
	part.rgb[0] = 0.0;
	part.rgb[1] = 0.0;
	part.rgb[2] = 0.7;
	part.rotation = 0.0; 
	part.xyz[0] = 0.0;
	part.xyz[1] = 0.64;
	part.xyz[2] = 0.0;
	Model.shapes.push_back(part);

	//Back Spoiler
	part.type = TRIANGULAR_PRISM;
	part.params.tri.alen = 0.3;
	part.params.tri.blen = 0.3;
	part.params.tri.depth = 1.03;
	part.params.tri.angle = 60;
	part.rgb[0] = 0.9;
	part.rgb[1] = 0.5;
	part.rgb[2] = 0.0;
	part.rotation = 0.0; 
	part.xyz[0] = -1.75; 
	part.xyz[1] = 0.64;
	part.xyz[2] = 0.0;
	Model.shapes.push_back(part);
	
	fillShapes();
}

MyVehicle::MyVehicle(VehicleModel vm) {
	Model = vm;
	fillShapes();
}


void MyVehicle::fillShapes()
{
	//pointer to the shape, base
	Shape *sh; 
    //shapes array inherited from vehicle class
	shapes.clear();
				 
	int i = 0;

    //pointer to each object 
	for (vector<ShapeInit>::iterator iter = Model.shapes.begin(); iter != Model.shapes.end(); ++iter)
	{
		//Check pointer and ask for type (eg:cylinder, rectangle etc.)
		switch (iter->type)  
		{
		case RECTANGULAR_PRISM:
			//create a nameless object called rect prism
			//and then copy everything from the array.
			sh = new RectPrism(iter->params.rect.xlen, iter->params.rect.ylen, iter->params.rect.zlen);
			sh->setRotation(iter->rotation);
			break;

		//Repeat for other shapes
		case TRIANGULAR_PRISM:  
			sh = new TrigPrism(iter->params.tri.alen, iter->params.tri.blen, iter->params.tri.angle, iter->params.tri.depth);
			sh->setRotation(iter->rotation);
			break;

		case TRAPEZOIDAL_PRISM:
			sh = new TrapPrism(iter->params.trap.alen, iter->params.trap.blen, iter->params.trap.height, iter->params.trap.aoff, iter->params.trap.depth);
			sh->setRotation(iter->rotation);
			break;

		case CYLINDER:
			sh = new Cylinder(iter->params.cyl.radius, iter->params.cyl.depth, iter->params.cyl.isRolling, iter->params.cyl.isSteering);
			sh->setRotation(iter->rotation);
			break;   
					
		}

		//Elements added to array
		sh->setColor(iter->rgb[0], iter->rgb[1], iter->rgb[2]); 
		sh->setPosition(iter->xyz[0], iter->xyz[1], iter->xyz[2]); 
		addShape(sh);  
		i++;
	}
}


void MyVehicle::draw()
{
	
	for (int i = 0; i < shapes.size(); i++) 
	{
		//vehicle local frame of reference 
		glPushMatrix(); 
		positionInGL();
		
		Cylinder* w = dynamic_cast<Cylinder*>(shapes[i]);

		if (w != nullptr) {
			double _radius = w->getRadius();
			//getAngle for cylinder steering 
			angle += (speed * elapsedTime * 180) / (_radius*PI);
			
			if (fabs(angle) > 360) {
				angle = 0;
			}

			w->setSteering(steering);
			w->setSpeed(angle);
		}

		//draw in local frame 
		shapes[i]->draw(); 
		//global frame of reference 
		glPopMatrix();   
	}

}