#include "mainwindow.h"
#include <QGraphicsTextItem>
#include <qtimer.h>
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
	QStringList container;
	container << "Box" << "Sphere";
	ui.containerComboBox->addItems(container);
    QAction::connect(ui.actionRun, SIGNAL(triggered()), this, SLOT(launchApp()));
    QAction::connect(ui.isocheckBox, SIGNAL(clicked()), this, SLOT(setIso()));
    QAction::connect(ui.relaxButton, SIGNAL(clicked()), this, SLOT(updateForces()));
    QAction::connect(ui.actionDelete_cells, SIGNAL(triggered()), this, SLOT(deleteCells()));
    QAction::connect(ui.actionClear, SIGNAL(triggered()), this, SLOT(clearQGview()));
    QAction::connect(ui.actionRedraw, SIGNAL(triggered()), this, SLOT(redrawQGview()));
    QAction::connect(ui.containerComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(selectContainer(int)));
}

MainWindow::~MainWindow()
{

}
void MainWindow::selectContainer(int ind){
	if(ind==0){
		ui.boxsizelab->setVisible(true);
		ui.heightlab->setVisible(true);
		ui.depthlab->setVisible(true);
		ui.spinDepth->setVisible(true);
		ui.spinHeight->setVisible(true);
		ui.spinWidth->setVisible(true);
		ui.isocheckBox->setVisible(true);
		ui.reduceFY->setVisible(true);
		ui.reduceFZ->setVisible(true);
		ui.label_5->setText("X");
		ui.label_6->setVisible(true);
		ui.label_7->setVisible(true);
	}else{
		if(ind==1){
			ui.boxsizelab->setVisible(false);
			ui.heightlab->setVisible(false);
			ui.depthlab->setVisible(false);
			ui.spinDepth->setVisible(false);
			ui.spinHeight->setVisible(false);
			ui.spinWidth->setVisible(false);
			ui.isocheckBox->setVisible(false);
			ui.reduceFY->setVisible(false);
			ui.reduceFZ->setVisible(false);
			ui.label_5->setText("Radius");
			ui.label_6->setVisible(false);
			ui.label_7->setVisible(false);
		}
	}
}
void MainWindow::redrawQGview(){
	if(isSphere) redrawQGviewForSphere();
	else if(isBox) redrawQGviewForBox();
}
void MainWindow::redrawQGviewForSphere(){
	//customSphere.splitCells(6);
	std::vector<Cell*> cells=customSphere.getCells();
	float leftbox=220;
	float sphereRadius=customSphere.getOriginRadius();
	//rightbox X Z
	scene.addEllipse(-sphereRadius+leftbox,-sphereRadius,sphereRadius*2,sphereRadius*2,QPen(Qt::blue));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseXZ(scene.addEllipse(cells[i]->getOrigin().getX()-cells[i]->getRadius()+leftbox,cells[i]->getOrigin().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::blue)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextXZ(textItem);
		textItem->setPos(cells[i]->getOrigin().getX()-cells[i]->getRadius()+leftbox, cells[i]->getOrigin().getZ()-cells[i]->getRadius());
	}
	//rightbox Y Z
	scene.addEllipse(-sphereRadius+leftbox*3,-sphereRadius,sphereRadius*2,sphereRadius*2,QPen(Qt::blue));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseYZ(scene.addEllipse(cells[i]->getOrigin().getY()-cells[i]->getRadius()+leftbox*3,cells[i]->getOrigin().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::blue)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextYZ(textItem);
		textItem->setPos(cells[i]->getOrigin().getY()-cells[i]->getRadius()+leftbox*3, cells[i]->getOrigin().getZ()-cells[i]->getRadius());
	}

	//leftbox X Y
	scene.addEllipse(-sphereRadius-leftbox,-sphereRadius,sphereRadius*2,sphereRadius*2,QPen(Qt::blue));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseXY(scene.addEllipse(cells[i]->getOrigin().getX()-cells[i]->getRadius()-leftbox,cells[i]->getOrigin().getY()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::blue)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextXY(textItem);
		textItem->setPos(cells[i]->getOrigin().getX()-cells[i]->getRadius()-leftbox, cells[i]->getOrigin().getY()-cells[i]->getRadius());
	}

	//leftbox X Y
	scene.addEllipse(-customSphere.getRadius()-leftbox,-customSphere.getRadius(),customSphere.getRadius()*2,customSphere.getRadius()*2,QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox,cells[i]->getCoord().getY()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox, cells[i]->getCoord().getY()-cells[i]->getRadius());
	}
	//rightbox X Z
	scene.addEllipse(-customSphere.getRadius()+leftbox,-customSphere.getRadius(),customSphere.getRadius()*2,customSphere.getRadius()*2,QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}
	//rightbox Y Z
	scene.addEllipse(-customSphere.getRadius()+leftbox*3,-customSphere.getRadius(),customSphere.getRadius()*2,customSphere.getRadius()*2,QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		scene.addEllipse(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		textItem->setPos(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}
}
void MainWindow::redrawQGviewForBox(){
	std::vector<Cell*> cells=customBox.getCells();
	float leftbox=220;
	//rightbox X Z
	scene.addRect(leftbox,0,customBox.getOriginWidth(),customBox.getOriginDepth(),QPen(Qt::blue));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseXZ(scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::blue)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextXZ(textItem);
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}
	//rightbox Y Z
	scene.addRect(leftbox*3,0,customBox.getOriginHeight(),customBox.getOriginDepth(),QPen(Qt::blue));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseYZ(scene.addEllipse(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::blue)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextYZ(textItem);
		textItem->setPos(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}

	//leftbox X Y
	scene.addRect(-leftbox,0,customBox.getOriginWidth(),customBox.getOriginHeight(),QPen(Qt::blue));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseXY(scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox,cells[i]->getCoord().getY()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::blue)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextXY(textItem);
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox, cells[i]->getCoord().getY()-cells[i]->getRadius());
	}

	//leftbox X Y
	scene.addRect(0-leftbox,0,customBox.getWidth(),customBox.getHeight(),QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox,cells[i]->getCoord().getY()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox, cells[i]->getCoord().getY()-cells[i]->getRadius());
	}
	//rightbox X Z
	scene.addRect(leftbox,0,customBox.getWidth(),customBox.getDepth(),QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}
	//rightbox Y Z
	scene.addRect(leftbox*3,0,customBox.getHeight(),customBox.getDepth(),QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		scene.addEllipse(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		textItem->setPos(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}
}

void MainWindow::clearQGview(){
	scene.clear();
}
void MainWindow::deleteCells(){
	if(isSphere){
		customSphere.deleteCells();
		customSphere.updateCellTree(*ui.CellTree);
	}else{
		customBox.deleteCells();
		customBox.updateCellTree(*ui.CellTree);
	}
	scene.update(-200,-200,800,800);
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

void MainWindow::updateForces(){
	scene.clear();
	if(isSphere) updateForcesInSphere();
	else if(isBox) updateForcesInBox();
	ui.ProcessStatus->setText("Updating trees");
	customSphere.updateCellTree(*ui.CellTree);
	customSphere.updateContainerTree(*ui.containerTree);
	ui.ProcessProgressBar->setVisible(false);
	ui.ProcessStatus->setVisible(false);
}
void MainWindow::updateForcesInSphere(){
	customSphere.setRadius(10000.0f);
	int nbtours=100;
	std::vector<Cell*> cells=customSphere.getCells();
	ui.ProcessProgressBar->setVisible(true);
	ui.ProcessStatus->setVisible(true);
	ui.ProcessProgressBar->setMaximum(nbtours);
	ui.ProcessStatus->setText("Calculate forces");
	for(int i=0;i<nbtours;i++) {
		customSphere.updateForces();
		ui.ProcessProgressBar->setValue((ui.ProcessProgressBar->value())+1);
	}
	ui.ProcessStatus->setText("Drawing");
	float leftbox=220;
	//leftbox X Y
	scene.addEllipse(-customSphere.getRadius()-leftbox,-customSphere.getRadius(),customSphere.getRadius()*2,customSphere.getRadius()*2,QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseXY(scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox,cells[i]->getCoord().getY()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextXY(textItem);
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox, cells[i]->getCoord().getY()-cells[i]->getRadius());
	}
	//rightbox X Z
	scene.addEllipse(-customSphere.getRadius()+leftbox,-customSphere.getRadius(),customSphere.getRadius()*2,customSphere.getRadius()*2,QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseXZ(scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextXZ(textItem);
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}
	//rightbox Y Z
	scene.addEllipse(-customSphere.getRadius()+leftbox*3,-customSphere.getRadius(),customSphere.getRadius()*2,customSphere.getRadius()*2,QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseYZ(scene.addEllipse(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextYZ(textItem);
		textItem->setPos(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}
}

void MainWindow::updateForcesInBox(){
	int nbtours=100;
	std::vector<Cell*> cells=customBox.getCells();
	ui.ProcessProgressBar->setVisible(true);
	ui.ProcessStatus->setVisible(true);
	ui.ProcessProgressBar->setMaximum(nbtours);
	ui.ProcessStatus->setText("Calculate forces");
	customBox.setWidth(10000);
	customBox.setHeight(10000);
	customBox.setDepth(10000);
	for(int i=0;i<nbtours;i++) {
		customBox.updateForces();
		ui.ProcessProgressBar->setValue((ui.ProcessProgressBar->value())+1);
	}
	ui.ProcessStatus->setText("Drawing");
	float leftbox=220;
	//leftbox X Y
	scene.addRect(0-leftbox,0,customBox.getWidth(),customBox.getHeight(),QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseXY(scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox,cells[i]->getCoord().getY()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextXY(textItem);
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox, cells[i]->getCoord().getY()-cells[i]->getRadius());
	}
	//rightbox X Z
	scene.addRect(leftbox,0,customBox.getWidth(),customBox.getDepth(),QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseXZ(scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextXZ(textItem);
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}
	//rightbox Y Z
	scene.addRect(leftbox*3,0,customBox.getHeight(),customBox.getDepth(),QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseYZ(scene.addEllipse(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextYZ(textItem);
		textItem->setPos(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3, cells[i]->getCoord().getZ()-cells[i]->getRadius());
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
	deleteCells();
	scene.clear();
	if(ui.containerComboBox->currentIndex()==1) launchSphere();
	else if(ui.containerComboBox->currentIndex()==0) launchBox();
	ui.ProcessProgressBar->setVisible(false);
	ui.ProcessStatus->setVisible(false);
	ui.ProcessProgressBar->setValue(0);
}

void MainWindow::launchSphere(){
	isSphere=true;
	isBox=false;
	CVector c;
	float sphereRadius=200.0f;
	customSphere.setCentroid(c);
	customSphere.setRadius(sphereRadius);
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
	customSphere.generateRandomCells(nbcells,radius);

	addLog("Launching forces calculation ...");
	std::vector<Cell*> cells=customSphere.getCells();
	float leftbox=220;
	//rightbox X Z
	scene.addEllipse(-sphereRadius+leftbox,-sphereRadius,sphereRadius*2,sphereRadius*2,QPen(Qt::blue));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseXZ(scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::blue)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextXZ(textItem);
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}
	//rightbox Y Z
	scene.addEllipse(-sphereRadius+leftbox*3,-sphereRadius,sphereRadius*2,sphereRadius*2,QPen(Qt::blue));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseYZ(scene.addEllipse(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::blue)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextYZ(textItem);
		textItem->setPos(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}

	//leftbox X Y
	scene.addEllipse(-sphereRadius-leftbox,-sphereRadius,sphereRadius*2,sphereRadius*2,QPen(Qt::blue));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseXY(scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox,cells[i]->getCoord().getY()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::blue)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextXY(textItem);
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox, cells[i]->getCoord().getY()-cells[i]->getRadius());
	}
	customSphere.updateForces();

	/*for(int i=0;i<=maxtime;i+=dt){
			if(isoReduce) customSphere.reduceISO(ui.reduceFX->value());
			else customSphere.reduce(ui.reduceFX->value(),ui.reduceFY->value(),ui.reduceFZ->value());
			ui.ProcessProgressBar->setValue((ui.ProcessProgressBar->value())+1);
		}*/

	for(int i=0;i<=maxtime;i+=dt){
		customSphere.reduce(ui.reduceFX->value());
		ui.ProcessProgressBar->setValue((ui.ProcessProgressBar->value())+1);
	}
	addLog("Done.");
	customSphere.updateCellTree(*ui.CellTree);
	customSphere.updateContainerTree(*ui.containerTree);
	cells=customSphere.getCells();
	//leftbox X Y
	scene.addEllipse(-customSphere.getRadius()-leftbox,-customSphere.getRadius(),customSphere.getRadius()*2,customSphere.getRadius()*2,QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox,cells[i]->getCoord().getY()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox, cells[i]->getCoord().getY()-cells[i]->getRadius());
	}
	//rightbox X Z
	scene.addEllipse(-customSphere.getRadius()+leftbox,-customSphere.getRadius(),customSphere.getRadius()*2,customSphere.getRadius()*2,QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}
	//rightbox Y Z
	scene.addEllipse(-customSphere.getRadius()+leftbox*3,-customSphere.getRadius(),customSphere.getRadius()*2,customSphere.getRadius()*2,QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		scene.addEllipse(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		textItem->setPos(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}


	/*scene.addText("ola");

		//customSphere.reduceDepth(20);
		DisplayWindow window(&customSphere);
			window.displayScene();*/
	//customSphere.deleteCells();
	//customSphere.deleteCells();
}

void MainWindow::launchBox(){
	isSphere=false;
	isBox=true;
	customBox.setSize(ui.spinWidth->value(),ui.spinHeight->value(),ui.spinDepth->value());
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

	addLog("Launching forces calculation ...");
	std::vector<Cell*> cells=customBox.getCells();
	float leftbox=220;
	//rightbox X Z
	scene.addRect(leftbox,0,customBox.getWidth(),customBox.getDepth(),QPen(Qt::blue));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseXZ(scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::blue)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextXZ(textItem);
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}
	//rightbox Y Z
	scene.addRect(leftbox*3,0,customBox.getHeight(),customBox.getDepth(),QPen(Qt::blue));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseYZ(scene.addEllipse(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::blue)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextYZ(textItem);
		textItem->setPos(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}

	//leftbox X Y
	scene.addRect(-leftbox,0,customBox.getWidth(),customBox.getHeight(),QPen(Qt::blue));
	for(int i=cells.size()-1;i>=0;i--){
		cells[i]->setSceneEllipseXY(scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox,cells[i]->getCoord().getY()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::blue)));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		cells[i]->setSceneTextXY(textItem);
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox, cells[i]->getCoord().getY()-cells[i]->getRadius());
	}
	customBox.updateForces();

	for(int i=0;i<=maxtime;i+=dt){
		if(isoReduce) customBox.reduceISO(ui.reduceFX->value());
		else customBox.reduce(ui.reduceFX->value(),ui.reduceFY->value(),ui.reduceFZ->value());
		ui.ProcessProgressBar->setValue((ui.ProcessProgressBar->value())+1);
	}
	addLog("Done.");
	customBox.updateCellTree(*ui.CellTree);
	customBox.updateContainerTree(*ui.containerTree);
	cells=customBox.getCells();
	//leftbox X Y
	scene.addRect(0-leftbox,0,customBox.getWidth(),customBox.getHeight(),QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox,cells[i]->getCoord().getY()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()-leftbox, cells[i]->getCoord().getY()-cells[i]->getRadius());
	}
	//rightbox X Z
	scene.addRect(leftbox,0,customBox.getWidth(),customBox.getDepth(),QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		scene.addEllipse(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		textItem->setPos(cells[i]->getCoord().getX()-cells[i]->getRadius()+leftbox, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}
	//rightbox Y Z
	scene.addRect(leftbox*3,0,customBox.getHeight(),customBox.getDepth(),QPen(Qt::red));
	for(int i=cells.size()-1;i>=0;i--){
		scene.addEllipse(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3,cells[i]->getCoord().getZ()-cells[i]->getRadius(),cells[i]->getRadius()*2,cells[i]->getRadius()*2,QPen(Qt::red));
		QGraphicsTextItem *textItem = scene.addText(cells[i]->getID().c_str(), QFont());
		textItem->setPos(cells[i]->getCoord().getY()-cells[i]->getRadius()+leftbox*3, cells[i]->getCoord().getZ()-cells[i]->getRadius());
	}


	/*scene.addText("ola");

		//customBox.reduceDepth(20);
		DisplayWindow window(&customBox);
			window.displayScene();*/
	//customBox.deleteCells();
	//customBox.deleteCells();
}



