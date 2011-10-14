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

void Container::updateCellTree(QTreeWidget* qt){}

void Container::updateContainerTree(QTreeWidget* qt){}

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
