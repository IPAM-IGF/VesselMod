/*
 * SphereForce.cpp
 *
 *  Created on: 17 oct. 2011
 *      Author: mobilette
 */

#include "SphereForce.h"
#include "Sphere.h"

SphereForce::SphereForce() {
	// TODO Auto-generated constructor stub

}

SphereForce::~SphereForce() {
	// TODO Auto-generated destructor stub
}


void SphereForce::evalForce(Cell & c1, const Sphere & s)
{

	switch (type)
	{
		case 1:
		{
			evalAttractiveForce(c1,s);
			break;
		}
		case 2:
		{
			evalRepulsiveForce(c1,s);
			break;
		}
		default:{std::cout<<"Error, type unknown !"<<std::endl;break;}
	}
}

void SphereForce::evalAttractiveForce(Cell & /*c1*/, const Sphere & /*c2*/)
{

}

void SphereForce::evalRepulsiveForce(Cell & c1, const Sphere & s)
{
	float overlap=fmax(((c1.getCoord().distanceTo(s.getCentroid())+c1.getRadius())-s.getRadius()),0.0f);
	CVector cv;
	cv=(c1.getCoord()/fmax(c1.getCoord().getAbsoluteMax(),1))*overlap;
	std::cout<<"overlap : "<<overlap<<"----"<<c1.getCoord().getAbsoluteMax()<<std::endl;
	cv.reverseSign();
	cv.print();
	c1.resetBoxCol();
	if(cv.getX()>0.0f) c1.setWl(true);
	if(cv.getX()<0.0f) c1.setWr(true);
	if(cv.getY()>0.0f) c1.setHl(true);
	if(cv.getY()<0.0f) c1.setHr(true);
	if(cv.getZ()>0.0f) c1.setDl(true);
	if(cv.getZ()<0.0f) c1.setDr(true);
	this->setValueXyz(cv*REPULSIVE_CONST);
}
