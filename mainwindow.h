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

private:
    Ui::MainWindowClass ui;
    bool isoReduce;
    QGraphicsScene scene;

};

#endif // MAINWINDOW_H
