/*
 * Container.h
 *
 *  Created on: 14 oct. 2011
 *      Author: mobilette
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "protoClass.h"
#include "Cell.h"
#include <qtreewidget.h>
#include <QTreeWidgetItem>
#include <vector>
#include <iostream>
#include <lib/GlobalDef.h>


class Container {
public:
	Container();
	Container(std::vector<Cell*> c);
	virtual ~Container();
	virtual void updateCellTree(QTreeWidget& qt);
	void setCells(std::vector<Cell*> cells);
	std::vector<Cell*> getCells() const;
	void addCell(Cell* cell);
	void deleteCells();
protected:
	std::vector<Cell*> cells;
};

#endif /* CONTAINER_H_ */
