/*
 * Container.cpp
 *
 *  Created on: 14 oct. 2011
 *      Author: mobilette
 */

#include "Container.h"
#include "Sphere.h"
#include "../mainwindow.h"
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
		QTreeWidgetItem* itemBef=new QTreeWidgetItem(item);
		itemBef->setIcon(0, QIcon(QString::fromUtf8(":/ico/checkred.gif")));
		itemBef->setText(0, ("Before"));
		QTreeWidgetItem* itemX=new QTreeWidgetItem(itemBef);
		itemX->setText(0, (std::string("X : ")+to_string(cells[i]->getOrigin().getX())).c_str());
		itemX->setIcon(0, QIcon(QString::fromUtf8(":/ico/axis.png")));
		QTreeWidgetItem* itemY=new QTreeWidgetItem(itemBef);
		itemY->setText(0, (std::string("Y : ")+to_string(cells[i]->getOrigin().getY())).c_str());
		itemY->setIcon(0, QIcon(QString::fromUtf8(":/ico/axis.png")));
		QTreeWidgetItem* itemZ=new QTreeWidgetItem(itemBef);
		itemZ->setText(0, (std::string("Z : ")+to_string(cells[i]->getOrigin().getZ())).c_str());
		itemZ->setIcon(0, QIcon(QString::fromUtf8(":/ico/axis.png")));
		QTreeWidgetItem* itemR=new QTreeWidgetItem(itemBef);
		itemR->setText(0, (std::string("R : ")+to_string(cells[i]->getRadius())).c_str());
		itemR->setIcon(0, QIcon(QString::fromUtf8(":/ico/radius.gif")));
		QTreeWidgetItem* itemAft=new QTreeWidgetItem(item);
		itemAft->setIcon(0, QIcon(QString::fromUtf8(":/ico/checkgreen.gif")));
		itemAft->setText(0, ("After"));
		itemX=new QTreeWidgetItem(itemAft);
		itemX->setText(0, (std::string("X : ")+to_string(cells[i]->getCoord().getX())).c_str());
		itemX->setIcon(0, QIcon(QString::fromUtf8(":/ico/axis.png")));
		itemY=new QTreeWidgetItem(itemAft);
		itemY->setText(0, (std::string("Y : ")+to_string(cells[i]->getCoord().getY())).c_str());
		itemY->setIcon(0, QIcon(QString::fromUtf8(":/ico/axis.png")));
		itemZ=new QTreeWidgetItem(itemAft);
		itemZ->setText(0, (std::string("Z : ")+to_string(cells[i]->getCoord().getZ())).c_str());
		itemZ->setIcon(0, QIcon(QString::fromUtf8(":/ico/axis.png")));
		itemR=new QTreeWidgetItem(itemAft);
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
		MainWindow::addLog(("Cell "+cells[i]->getID()+" deleted.").c_str());
		cells[i]->deleteGraphicalView();
		delete(this->cells[i]);
	}
	this->cells.clear();
}

void Container::splitCells(int val){
	if(val==1) return;
	std::vector<Cell*> cellstmp;
	for(unsigned int i=0;i<this->cells.size();i++){
		cells.erase(cells.begin()+i);
		std::vector<Cell *>* tmp=cells[i]->splitIn(val);
		for(unsigned int j=0;j<tmp->size();j++)
			cellstmp.push_back(tmp->at(j));
		delete(tmp);
	}
	std::copy(cellstmp.begin(), cellstmp.end(), std::back_inserter(cells));
}


