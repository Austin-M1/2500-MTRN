#ifdef APPLE
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




MyVehicle::MyVehicle()
{
	ShapeInit part;


	//base
	part.type = RECTANGULAR_PRISM;
	part.params.rect.xlen = 3.74;
	part.params.rect.ylen = 0.43;
	part.params.rect.zlen = 1.41;
	part.rgb[0] = 0.6;
	part.rgb[1] = 0.0;
	part.rgb[2] = 0.0;
	part.rotation = 0.0; //means perfectly aligned in x dir
	part.xyz[0] = 0.0;
	part.xyz[1] = 0.2;
	part.xyz[2] = 0.0;
	Model.shapes.push_back(part);

	part.type = CYLINDER;
	part.params.cyl.isRolling = TRUE;
	part.params.cyl.isSteering = TRUE;
	part.params.cyl.radius = 0.42;
	part.params.cyl.depth = 0.19;
	part.rgb[0] = 0.2;
	part.rgb[1] = 0.2;
	part.rgb[2] = 0.2;
	part.rotation = 0.0; //means perfectly aligned in x dir
	part.xyz[0] = 1.28;
	part.xyz[1] = 0.0;
	part.xyz[2] = 0.705;
	Model.shapes.push_back(part);

	part.type = CYLINDER;
	part.params.cyl.isRolling = TRUE;
	part.params.cyl.isSteering = TRUE;
	part.params.cyl.radius = 0.42;
	part.params.cyl.depth = 0.19;
	part.rgb[0] = 0.2;
	part.rgb[1] = 0.2;
	part.rgb[2] = 0.2;
	part.rotation = 0.0; //means perfectly aligned in x dir
	part.xyz[0] = 1.28;
	part.xyz[1] = 0.0;
	part.xyz[2] = -0.705;
	Model.shapes.push_back(part);

	part.type = CYLINDER;
	part.params.cyl.isRolling = TRUE;
	part.params.cyl.isSteering = FALSE;
	part.params.cyl.radius = 0.42;
	part.params.cyl.depth = 0.19;
	part.rgb[0] = 0.2;
	part.rgb[1] = 0.2;
	part.rgb[2] = 0.2;
	part.rotation = 0.0; //means perfectly aligned in x dir
	part.xyz[0] = -1.04;
	part.xyz[1] = 0.0;
	part.xyz[2] = -0.705;
	Model.shapes.push_back(part);

	part.type = CYLINDER;
	part.params.cyl.isRolling = TRUE;
	part.params.cyl.isSteering = FALSE;
	part.params.cyl.radius = 0.42;
	part.params.cyl.depth = 0.19;
	part.rgb[0] = 0.2;
	part.rgb[1] = 0.2;
	part.rgb[2] = 0.2;
	part.rotation = 0.0; //means perfectly aligned in x dir
	part.xyz[0] = -1.04;
	part.xyz[1] = 0.0;
	part.xyz[2] = 0.705;
	Model.shapes.push_back(part);


	//shoulder/torso
	part.type = TRAPEZOIDAL_PRISM;
	part.params.trap.alen = 1.61;
	part.params.trap.blen = 0.51;
	part.params.trap.height = 0.4;
	part.params.trap.aoff = 0.55;
	part.params.trap.depth = 1.41;
	part.rgb[0] = 0.7;
	part.rgb[1] = 0.0;
	part.rgb[2] = 0.0;
	part.rotation = 0.0; //means perfectly aligned in x dir
	part.xyz[0] = 0.0;
	part.xyz[1] = 0.64;
	part.xyz[2] = 0.0;
	Model.shapes.push_back(part);

	part.type = TRIANGULAR_PRISM;
	part.params.tri.alen = 0.15;
	part.params.tri.blen = 0.15;
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
	Shape *sh; //pointer to the shape, base 
	shapes.clear();
	int i = 0;
	//pointer to each object 
	for (vector<ShapeInit>::iterator iter = Model.shapes.begin(); iter != Model.shapes.end(); ++iter)
	{
		switch (iter->type) //look at pointer and ask for type could be cylinder, rectangle etc 
		{
		case RECTANGULAR_PRISM:
			sh = new RectPrism(iter->params.rect.xlen, iter->params.rect.ylen, iter->params.rect.zlen);
			sh->setRotation(iter->rotation);
			break;

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
			break;  //need to make sure if turning, stationary or other cylinder 

		}
		//all elements added to array
		sh->setColor(iter->rgb[0], iter->rgb[1], iter->rgb[2]);
		sh->setPosition(iter->xyz[0], iter->xyz[1], iter->xyz[2]);
		addShape(sh);

		i++;
	}
}


//void MyVehicle::getspeed()
//{
	//float prevtime = time - difference;
	//difference = time - prevtime;


//}

void MyVehicle::draw()
{

	for (int i = 0; i < shapes.size(); i++)
	{
		 

		//move to the vehicle's local frame of reference 
		glPushMatrix();
		positionInGL();

		Cylinder* w = dynamic_cast<Cylinder*>(shapes[i]);

		if (w != nullptr) {
			double _radius = w->getRadius();
			double Angle;
			//double ElapsedTime;
			//ElapsedTime = 0.0;
			Angle = 0.0;

			//need to getAngle 
			Angle += (speed * GLUT_ELAPSED_TIME * 180) / (_radius*PI);

			if (fabs(Angle) > 360) {
				Angle = 0;
			}

			if (speed != NULL) {
				//Cylinder::Cylinder::Cylinder(0, 0, TRUE, TRUE);
				//Cylinder::Cylinder::isRolling = TRUE;
				glRotatef(speed, 0, 1, 5);
				//glRotatef(steering/5, 0, 1, 5);
			   // glRotatef(-steering, 0, 1, 0);
				//glRotated(-speed / 5, 0, 0, 1);

				/*
				glColor3f(0, 0, 0);
				glPushMatrix();
				glTranslatef(0, 0, -(0.19)+0.02);
				gluPartialDisk(0, 0.0f, 0.42, 5, 1, 0, 30);
				gluPartialDisk(0, 0.0f, 0.42, 5, 1, 120, 30);
				gluPartialDisk(0, 0.0f, 0.42, 5, 1, 240, 30);
				glTranslatef(0, 0, -(0.19)-0.04);
				gluPartialDisk(0, 0.0f, 0.42, 5, 1, 0, 30);
				gluPartialDisk(0, 0.0f, 0.42, 5, 1, 120, 30);
				gluPartialDisk(0, 0.0f, 0.42, 5, 1, 240, 30);
				*/

				//glColor3f(0, 0, 0);
				//glPushMatrix();
				//glTranslatef(0, 0, -(0.19)+0.02);
				//glTranslatef(0, 0, -(0.19)-0.04);


				glRotatef(speed, 1.28, 0.0, 0.705);
				glRotatef(speed, 1.28, 0.0, -0.705);
				glRotatef(speed, -1.04, 0.0, -0.705);
				glRotatef(speed, -1.04, 0.0, 0.705);
				
			}
			
			w->setSteering(steering);
			w->setSpeed(Angle);
			w->setRotation(speed);
			//w->isRolling = TRUE
			//w->glRotatef(rotation, 0.0, 1.0, 0.0);
		}

		//draw in local frame 
		shapes[i]->draw();
		//move back to global frame of reference 
		glPopMatrix();  //this is a pointer to pointer situation because 
						//it is an array of pointers 
	}

}