/*
 * CellForce.cpp
 *
 *  Created on: 10 oct. 2011
 *      Author: mobilette
 */

#include "CellForce.h"


CellForce::CellForce():Force() {
	// TODO Auto-generated constructor stub

}
CellForce::CellForce(const Cell * c1, const Cell * c2):c1(c1),c2(c2)
{
}
CellForce::~CellForce() {
	// TODO Auto-generated destructor stub
}


const Cell* CellForce::getC1() const
{
    return c1;
}

void CellForce::setC1(const Cell* c1)
{
    this->c1 = c1;
}

const Cell* CellForce::getC2() const
{
    return c2;
}

void CellForce::setC2(const Cell* c2)
{
    this->c2 = c2;
}

void CellForce::evalForce(Cell & c1, Cell & c2)
{

	switch (type)
	{
		case 1:
		{
			evalAttractiveForce(c1,c2);
			break;
		}
		case 2:
		{
			evalRepulsiveForce(c1,c2);
			break;
		}
		default:{std::cout<<"Error, type unknown !"<<std::endl;break;}
	}
}

void CellForce::evalAttractiveForce(Cell & c1, Cell & c2)
{
	float eucliDist=c1.evalDistance(c2);
	//float overlap=c1.evalOverlap(c2);
	float overlap=fmax((c1.getRadius()+c2.getRadius())-eucliDist,0.0f);
	//radius of the circle made by the intersection
	float intersectRadius=(1/(2*eucliDist))*sqrt(4*pow(eucliDist,2)*pow(c1.getRadius(),2)-pow(pow(eucliDist,2)-pow(c2.getRadius(),2)+pow(c1.getRadius(),2),2));
	CVector cv;
	if(overlap==0.0f){ this->setValueXyz(cv);return;}
	c1.addNeighborhood(&c2);
	cv.setX(c2.getCoord().getX()-c1.getCoord().getX());
	cv.setY(c2.getCoord().getY()-c1.getCoord().getY());
	cv.setZ(c2.getCoord().getZ()-c1.getCoord().getZ());
	//std::cout<<c1.getCoord().getX()<<"-Attract--"<<c2.getCoord().getX()<<"-over:"<<overlap<<"dist"<<eucliDist<<std::endl;
	cv=cv*ATTRACTIVE_CONST*(intersectRadius/(c1.getRadius()));
	//cv.print();
	this->setValueXyz(cv);
}



void CellForce::evalRepulsiveForce(Cell & c1, Cell & c2)
{
	float eucliDist=c1.evalDistance(c2);
	float overlap=c1.evalOverlap(c2);
	CVector cv;
	if(overlap==0.0f){ this->setValueXyz(cv);return;}
	cv.setX(c1.getCoord().getX()-c2.getCoord().getX());
	cv.setY(c1.getCoord().getY()-c2.getCoord().getY());
	cv.setZ(c1.getCoord().getZ()-c2.getCoord().getZ());
	cv=cv*REPULSIVE_CONST*(overlap/eucliDist);
	this->setValueXyz(cv);
}


