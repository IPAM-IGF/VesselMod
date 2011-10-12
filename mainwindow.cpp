#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	//MainWindow::uiStat=&ui;
    QAction::connect(ui.actionRun, SIGNAL(triggered()), this, SLOT(launchApp()));
}

MainWindow::~MainWindow()
{

}
/*void MainWindow::addLog(const std::string &txt){

	//QString qs=uiStat->LogPanel->toPlainText().append(&txt);
	//uiStat->LogPanel->setPlainText(qs);
}*/
void MainWindow::launchApp(){
	Box customBox(200,200,200);
	int nbcells=40;
	int radius=20;
	float dt=1;
	float maxtime=150;
	std::vector<Force> listForces;

	CVector coord;
	// instantiate new cells
	for(int i=0;i<nbcells;i++){
		coord.setX(rand()%200);
		coord.setY(rand()%200);
		coord.setZ(rand()%200);
		Cell* aCell=new Cell();
		aCell->setCoord(coord);
		aCell->setRadius(radius);
		customBox.addCell(aCell);
	}

	//2 tests cells
	/*coord.setX(100);
	coord.setY(100);
	coord.setZ(11);
	Cell* aCell=new Cell();
	aCell->setCoord(coord);
	aCell->setRadius(radius);
	customBox.addCell(aCell);


	coord.setX(110);
	coord.setY(100);
	coord.setZ(11);
	Cell* aCell2=new Cell();
	aCell2->setCoord(coord);
	aCell2->setRadius(radius);
	customBox.addCell(aCell2);
	customBox.printBox();*/
	customBox.updateForces();

	for(int i=0;i<=maxtime;i+=dt){
		customBox.reduceDepth(1.0f);
	}

	//customBox.reduceDepth(20);
	std::cout<<"next"<<customBox.getDepth()<<std::endl;
	customBox.printBox();
	/*DisplayWindow window(&customBox);
		window.displayScene();*/
	customBox.deleteCells();
}
