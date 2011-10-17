#include "mainwindow.h"
Ui::MainWindowClass* MainWindow::uiStat;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	isoReduce=false;
	ui.setupUi(this);
	ui.ProcessProgressBar->setVisible(false);
	ui.ProcessStatus->setVisible(false);
	uiStat=&ui;
	ui.graphicsView->setScene(&scene);
    QAction::connect(ui.actionRun, SIGNAL(triggered()), this, SLOT(launchApp()));
    QAction::connect(ui.isocheckBox, SIGNAL(clicked()), this, SLOT(setIso()));
}

MainWindow::~MainWindow()
{

}
void MainWindow::setIso(){
	isoReduce=!isoReduce;
	if(isoReduce){
		ui.reduceFY->setEnabled(false);
		ui.reduceFZ->setEnabled(false);
        QObject::connect(ui.reduceFX, SIGNAL(valueChanged(double)), ui.reduceFY, SLOT(setValue(double)));
        QObject::connect(ui.reduceFY, SIGNAL(valueChanged(double)), ui.reduceFZ, SLOT(setValue(double)));
	}else{
		ui.reduceFY->setEnabled(true);
		ui.reduceFZ->setEnabled(true);
		QObject::disconnect(ui.reduceFX, SIGNAL(valueChanged(double)), ui.reduceFY, SLOT(setValue(double)));
		QObject::disconnect(ui.reduceFY, SIGNAL(valueChanged(double)), ui.reduceFZ, SLOT(setValue(double)));
	}
}
void MainWindow::addLog(const char txt[]){

	//char s[1000];
	uiStat->ProcessStatus->setText(txt);
	std::string s=to_string(txt)+to_string("\n");
	//strcat( s, txt );
	//strcat( s, "\n");
	QString qs=uiStat->LogPanel->toPlainText().append(s.c_str());
	uiStat->LogPanel->setPlainText(qs);
}

void MainWindow::launchApp(){
	CVector c;
	float sphereRadius=200.0f;
	Sphere customBox(c, sphereRadius);
	srand((unsigned)time(0));
	ui.ProcessStatus->setText("Initializing");
	ui.ProcessProgressBar->setVisible(true);
	ui.ProcessStatus->setVisible(true);
	ui.ProcessProgressBar->setValue(0);
	int nbcells=ui.spinNbcells->value();
	float radius=ui.radiusSpin->value();
	float dt=ui.stepSpin->value();
	float maxtime=ui.maxtimeSpin->value();
	ui.ProcessProgressBar->setMaximum(nbcells+(maxtime/dt));
	std::vector<Force> listForces;
	customBox.generateRandomCells(nbcells,radius);

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
	addLog("Launching forces calculation ...");
	std::vector<Cell*> cells=customBox.getCells();
	scene.addEllipse(-sphereRadius,-sphereRadius,sphereRadius*2,sphereRadius*2,QPen(Qt::blue));
	for(int i=cells.size()-1;i>=0;i--){
		scene.addEllipse(cells[i]->getCoord().getX(),cells[i]->getCoord().getY(),cells[i]->getRadius(),cells[i]->getRadius(),QPen(Qt::blue));
	}
	customBox.updateForces();

	/*for(int i=0;i<=maxtime;i+=dt){
		if(isoReduce) customBox.reduceISO(ui.reduceFX->value());
		else customBox.reduce(ui.reduceFX->value(),ui.reduceFY->value(),ui.reduceFZ->value());
		ui.ProcessProgressBar->setValue((ui.ProcessProgressBar->value())+1);
	}*/

	for(int i=0;i<=maxtime;i+=dt){
		customBox.reduce(ui.reduceFX->value());
		ui.ProcessProgressBar->setValue((ui.ProcessProgressBar->value())+1);
	}
	addLog("Done.");
	customBox.updateCellTree(*ui.CellTree);
	customBox.updateContainerTree(*ui.containerTree);
	cells=customBox.getCells();
	scene.addEllipse(-customBox.getRadius(),-customBox.getRadius(),customBox.getRadius()*2,customBox.getRadius()*2,QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		if(cells[i]->getCoord().getX()==cells[i]->getCoord().getX())
			scene.addEllipse(cells[i]->getCoord().getX(),cells[i]->getCoord().getY(),cells[i]->getRadius(),cells[i]->getRadius(),QPen(Qt::red));
	}


	/*scene.addText("ola");

	//customBox.reduceDepth(20);
	DisplayWindow window(&customBox);
		window.displayScene();*/
	customBox.deleteCells();
	ui.ProcessProgressBar->setVisible(false);
	ui.ProcessStatus->setVisible(false);
}
