/*
 * Container.cpp
 *
 *  Created on: 14 oct. 2011
 *      Author: mobilette
 */

#include "Container.h"

Container::Container() {
	// TODO Auto-generated constructor stub

}

Container::Container(std::vector<Cell*> c):cells(c) {
	// TODO Auto-generated constructor stub

}

Container::~Container() {
	// TODO Auto-generated destructor stub
}
//void Container::generateRandomCells(int nbcells, float radius){}
void Container::updateCellTree(QTreeWidget & qt){
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
//void Container::updateContainerTree(QTreeWidget* qt){}

std::vector<Cell*> Container::getCells() const{
	return cells;
}
void Container::setCells(std::vector<Cell*> cells){
	this->cells=cells;
}
void Container::addCell(Cell* cell){
	this->cells.push_back(cell);
}
void Container::deleteCells(){
	for(unsigned int i=0;i<this->cells.size();i++){
		delete(this->cells[i]);
	}
	this->cells.clear();
}
