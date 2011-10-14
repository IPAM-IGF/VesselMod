#include "Box.h"
#include <iostream>

using namespace std;
Box::Box(void)
{
}

Box::Box(float width,float height, float depth):width(width),height(height), depth(depth)
{
}


Box::Box(float width,float height, float depth, std::vector<Cell*> c):width(width),height(height), depth(depth), Container(c)
{
}

Box::~Box(void)
{
}


float Box::getWidth() const{return this->width;}
float Box::getHeight() const{return this->height;}
float Box::getDepth() const{return this->depth;}
std::vector<Cell*> Box::getCells() const{return this->cells;}
void Box::setWidth(float width){
	this->width=width;
}
void Box::setHeight(float height){
	this->height=width;
}
void Box::setDepth(float depth){
	this->depth=depth;
}

void Box::printBox() const{
	std::string s="Box : "+(int)this->width+(int)this->height+(int)this->depth;
	std::cout << s << std::endl;
	for(unsigned int i=0;i<this->cells.size();i++){
		this->cells[i]->printCell();
	}
}

void Box::reduceISO(const float pas)
{
	setSize(width-pas,height-pas,depth-pas);
}

void Box::setSize(float w, float h, float d)
{
	width=w;
	height=h;
	depth=d;
	updateForces();
}

void Box::reduce(const float px, const float py, const float pz)
{
	setSize(width-px,height-py,depth-pz);
}

void Box::reduceWidth(const float pas)
{
	setSize(width-pas,height,depth);
}



void Box::reduceHeight(const float pas)
{
	setSize(width,height-pas,depth);
}



void Box::reduceDepth(const float pas)
{
	setSize(width,height,depth-pas);
}

void Box::updateForces()
{
	Box* tmpb=this;
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

void Box::applyForces()
{
	for(unsigned int i=0;i<cells.size();i++){
		cells[i]->applyForces();
	}
}

void Box::updateCellTree(QTreeWidget & qt){
	qt.clear();
	for(int i=cells.size()-1;i>=0;i--){
		QTreeWidgetItem* item=new QTreeWidgetItem();
		item->setIcon(0, QIcon(QString::fromUtf8(":/ico/cells.gif")));
		item->setText(0, (std::string("Cell ")+to_string(cells[i]->getID())).c_str());
		QTreeWidgetItem* itemX=new QTreeWidgetItem(item);
		itemX->setText(0, (std::string("X : ")+to_string(cells[i]->getCoord().getX())).c_str());
		itemX->setIcon(0, QIcon(QString::fromUtf8(":/ico/axis.png")));
		QTreeWidgetItem* itemY=new QTreeWidgetItem(item);
		itemY->setText(0, (std::string("Y : ")+to_string(cells[i]->getCoord().getY())).c_str());
		itemY->setIcon(0, QIcon(QString::fromUtf8(":/ico/axis.png")));
		QTreeWidgetItem* itemZ=new QTreeWidgetItem(item);
		itemZ->setText(0, (std::string("Z : ")+to_string(cells[i]->getCoord().getZ())).c_str());
		itemZ->setIcon(0, QIcon(QString::fromUtf8(":/ico/axis.png")));
		QTreeWidgetItem* itemR=new QTreeWidgetItem(item);
		itemR->setText(0, (std::string("R : ")+to_string(cells[i]->getRadius())).c_str());
		itemR->setIcon(0, QIcon(QString::fromUtf8(":/ico/radius.gif")));
		qt.insertTopLevelItem(0,item);

	}
}


void Box::updateContainerTree(QTreeWidget & qt){
	qt.clear();
	QTreeWidgetItem* item=new QTreeWidgetItem();
	item->setIcon(0, QIcon(QString::fromUtf8(":/ico/box.png")));
	item->setText(0, (std::string("Box ")+to_string(this)).c_str());
	QTreeWidgetItem* itemWidth=new QTreeWidgetItem(item);
	itemWidth->setText(0, (std::string("Width : ")+to_string(getWidth())).c_str());
	itemWidth->setIcon(0, QIcon(QString::fromUtf8(":/ico/axis.png")));
	QTreeWidgetItem* itemHeight=new QTreeWidgetItem(item);
	itemHeight->setText(0, (std::string("Height : ")+to_string(getHeight())).c_str());
	itemHeight->setIcon(0, QIcon(QString::fromUtf8(":/ico/axis.png")));
	QTreeWidgetItem* itemDepth=new QTreeWidgetItem(item);
	itemDepth->setText(0, (std::string("Depth : ")+to_string(getDepth())).c_str());
	itemDepth->setIcon(0, QIcon(QString::fromUtf8(":/ico/axis.png")));
	QTreeWidgetItem* itemNCells=new QTreeWidgetItem(item);
	itemNCells->setText(0, (std::string("Cells : ")+to_string(cells.size())).c_str());
	itemNCells->setIcon(0, QIcon(QString::fromUtf8(":/ico/cells.gif")));
	qt.insertTopLevelItem(0,item);
}










