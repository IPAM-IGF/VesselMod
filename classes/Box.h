#ifndef BOX_H
#define BOX_H

#include "Container.h"
#include <qtreewidget.h>

class Box:  public Container{
public:
	Box(void);
	Box(float width, float height, float depth);
	Box(std::vector<Cell*>,float width,float height, float depth);
	~Box(void);
	float getWidth() const;
	float getHeight() const;
	float getDepth() const;
	std::vector<Cell*> getCells() const;
	void setWidth(float width);
	void setHeight(float height);
	void setDepth(float depth);
	void printBox() const;
	void setSize(float w,float h,float d);
	void reduceISO(const float pas);
	void reduce(const float px, const float py, const float pz);
	void reduceWidth(const float pas);
	void reduceHeight(const float pas);
	void reduceDepth(const float pas);
	void generateRandomCells(int nbcells, float radius);
	void updateContainerTree(QTreeWidget & qt);
	void updateForces();
	void applyForces();
private:
	float width, height, depth;
};

#endif
