#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <classes/Box.h>
#include <classes/Sphere.h>
#include <classes/Force.h>
#include <classes/Cell.h>
#include <classes/CVector.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static void addLog(const char txt[]);
    static Ui::MainWindowClass* uiStat;
private slots:
	void setIso();
	void launchApp();
	void updateForces();
	void deleteCells();
	void clearQGview();
	void redrawQGview();
	void selectContainer(int ind);
private:
	void launchSphere();
	void launchBox();
	void redrawQGviewForSphere();
	void redrawQGviewForBox();
	void updateForcesInSphere();
	void updateForcesInBox();
    Ui::MainWindowClass ui;
    bool isoReduce;
    QGraphicsScene scene;
    Box customBox;
    Sphere customSphere;
    bool isSphere;
    bool isBox;
};

#endif // MAINWINDOW_H
