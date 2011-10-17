/*
 * Sphere.cpp
 *
 *  Created on: 17 oct. 2011
 *      Author: mobilette
 */

#include "Sphere.h"
#include <math.h>
#include <mainwindow.h>

Sphere::Sphere() {
	// TODO Auto-generated constructor stub

}
Sphere::Sphere(CVector cent,float radius):centroid(cent),radius(radius)
{

}
Sphere::Sphere(std::vector<Cell*> c,CVector cent,float radius):Container(c),centroid(cent),radius(radius)
{

}


Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}
float Sphere::getRadius() const{
	return radius;
}
void Sphere::setRadius(float r){
	radius=r;
}
CVector Sphere::getCentroid() const{
	return this->centroid;
}
void Sphere::setCentroid(CVector cv){
	this->centroid=cv;
}
void Sphere::generateRandomCells(int nbcells, float r){
	CVector coord;
	for(int i=0;i<nbcells;i++){
		MainWindow::addLog(("Instantiate cells..."+to_string(i+1)).c_str());
		do{
			coord.random(radius);
		}while(coord.distanceTo(0,0,0)>radius);
		Cell* aCell=new Cell(i+1);
		aCell->setCoord(coord);
		aCell->setRadius(r);
		addCell(aCell);
		MainWindow::uiStat->ProcessProgressBar->setValue((MainWindow::uiStat->ProcessProgressBar->value())+1);
	}
}

void Sphere::updateContainerTree(QTreeWidget & qt){
	qt.clear();
	QTreeWidgetItem* item=new QTreeWidgetItem();
	item->setIcon(0, QIcon(QString::fromUtf8(":/ico/sphere.png")));
	item->setText(0, (std::string("Sphere ")+to_string(this)).c_str());
	QTreeWidgetItem* itemWidth=new QTreeWidgetItem(item);
	itemWidth->setText(0, (std::string("Radius : ")+to_string(getRadius())).c_str());
	itemWidth->setIcon(0, QIcon(QString::fromUtf8(":/ico/radius.gif")));
	qt.insertTopLevelItem(0,item);
}
void Sphere::reduce(const float pix){
	radius=radius-pix;
	updateForces();
}

void Sphere::updateForces()
{
	std::cout<<"------------------"<<std::endl;
	Sphere* tmpb=this;
	for(unsigned int i=0;i<cells.size();i++){
		cells[i]->checkAndSetForceWith(*tmpb);
		for(unsigned int j=0;j<cells.size();j++){
			if(i!=j){
				cells[i]->checkAndSetForceWith(*cells[j]);
			}
		}
	}
	applyForces();
}

void Sphere::applyForces()
{
	for(unsigned int i=0;i<cells.size();i++){
		cells[i]->applyForces();
	}
}
