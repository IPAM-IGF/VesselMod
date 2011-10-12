#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <vector>
#include <classes/Box.h>
#include <classes/Force.h>
#include <classes/Cell.h>
#include <classes/CVector.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void static addLog(const char[] txt);
private slots:
	void launchApp();

private:
    Ui::MainWindowClass ui;
    static Ui::MainWindowClass* uiStat;
};

#endif // MAINWINDOW_H
