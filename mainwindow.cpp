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

	char s[1000];
	uiStat->ProcessStatus->setText(txt);
	strcat( s, txt );
	strcat( s, "\n");
	QString qs=uiStat->LogPanel->toPlainText().append(s);
	uiStat->LogPanel->setPlainText(qs);
}

void MainWindow::launchApp(){
	Box customBox(ui.spinWidth->value(),ui.spinHeight->value(),ui.spinDepth->value());
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
	CVector coord;

	// instantiate new cells
	addLog("Instantiate cells...");
	for(int i=0;i<nbcells;i++){
		coord.setX(rand()%(int)customBox.getWidth());
		coord.setY(rand()%(int)customBox.getHeight());
		coord.setZ(rand()%(int)customBox.getDepth());
		Cell* aCell=new Cell(i+1);
		aCell->setCoord(coord);
		aCell->setRadius(radius);
		customBox.addCell(aCell);
		ui.ProcessProgressBar->setValue((ui.ProcessProgressBar->value())+1);
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
	addLog("Launching forces calculation ...");

	customBox.updateForces();

	for(int i=0;i<=maxtime;i+=dt){
		if(isoReduce) customBox.reduceISO(ui.reduceFX->value());
		else customBox.reduce(ui.reduceFX->value(),ui.reduceFY->value(),ui.reduceFZ->value());
		ui.ProcessProgressBar->setValue((ui.ProcessProgressBar->value())+1);
	}
	addLog("Done.");
	customBox.updateCellTree(*ui.CellTree);
	customBox.updateContainerTree(*ui.containerTree);
	scene.addText("ola");

	//customBox.reduceDepth(20);
	/*DisplayWindow window(&customBox);
		window.displayScene();*/
	customBox.deleteCells();
	ui.ProcessProgressBar->setVisible(false);
	ui.ProcessStatus->setVisible(false);
}
