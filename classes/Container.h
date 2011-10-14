/*
 * Container.h
 *
 *  Created on: 14 oct. 2011
 *      Author: mobilette
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "protoClass.h"
#include <qtreewidget.h>
#include <vector>
#include <iostream>


class Container {
public:
	Container();
	Container(std::vector<Cell*> c);
	virtual ~Container();
	virtual void updateCellTree(QTreeWidget* qt);
	virtual void updateContainerTree(QTreeWidget* qt);
	void setCells(std::vector<Cell*> cells);
	void addCell(Cell* cell);
	void deleteCells();
protected:
	std::vector<Cell*> cells;
};

#endif /* CONTAINER_H_ */
