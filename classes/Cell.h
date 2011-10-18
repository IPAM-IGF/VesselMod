#ifndef CELL_H
#define CELL_H
#include <vector>
#include <iostream>
#include <sstream>

//#include "Force.h"
#include "protoClass.h"
#include "BoxForce.h"
#include "SphereForce.h"
#include "CellForce.h"
#include "CVector.h"
#include "../lib/GlobalDef.h"
#include <QGraphicsTextItem>

class Cell
{
public:
	Cell(void);
	Cell(int id);
	Cell(int id, int type, float radius, CVector coord);
	Cell(int id, int type, float radius, CVector coord,std::vector<Force> forces);
	~Cell(void);
	void setRadius(float radius);
	void setType(int type);
	void setForces(std::vector<Force> forces);
	void setCoord(CVector coord);
	int getType() const;
	CVector getCoord() const;
	CVector getOrigin() const;
	float getRadius() const;
	std::vector<Force> getForces() const;
	float evalDistance(const Cell &c) const;
	float evalOverlap(const Cell &c) const;
	void printCell() const;
	void addForce(Force & f);
	void checkAndSetForceWith(const Cell & c);
	void checkAndSetForceWith(const Box & c);
	void checkAndSetForceWith(const Sphere & c);
	void applyForces();
	void moveTo(float x,float y, float z);
    bool isDl() const;
    bool isDr() const;
    bool isHl() const;
    bool isHr() const;
    bool isWl() const;
    bool isWr() const;
    void setDl(bool dl);
    void setDr(bool dr);
    void setHl(bool hl);
    void setHr(bool hr);
    void setWl(bool wl);
    void setWr(bool wr);
    void setID(int i);
    int getID() const;
    void setSceneTextXY(QGraphicsTextItem*  t);
    void setSceneEllipseXY(QGraphicsEllipseItem* s);
    QGraphicsTextItem* getSceneTextXY() const;
    QGraphicsEllipseItem* getSceneEllipseXY() const;
    void setSceneTextXZ(QGraphicsTextItem*  t);
    void setSceneEllipseXZ(QGraphicsEllipseItem* s);
    void setSceneTextYZ(QGraphicsTextItem*  t);
    void setSceneEllipseYZ(QGraphicsEllipseItem* s);
    QGraphicsTextItem* getSceneTextXZ() const;
    QGraphicsEllipseItem* getSceneEllipseXZ() const;
    QGraphicsTextItem* getSceneTextYZ() const;
    QGraphicsEllipseItem* getSceneEllipseYZ() const;
    void deleteGraphicalView();
    void resetBoxCol();
    std::vector<Cell*>* splitIn(int val) const;
private:
    int ID;
    int type;
    float radius;
    CVector coord;
    CVector origin;
    std::vector<Force> forces;
    QGraphicsTextItem* sceneTextXY;
    QGraphicsEllipseItem* sceneEllipseXY;
    QGraphicsTextItem* sceneTextXZ;
    QGraphicsEllipseItem* sceneEllipseXZ;
    QGraphicsTextItem* sceneTextYZ;
    QGraphicsEllipseItem* sceneEllipseYZ;

    bool WR;
    bool WL;
    bool DR;
    bool DL;
    bool HR;
    bool HL;
};

#endif
