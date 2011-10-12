/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Oct 12 14:22:18 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBox>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionRun;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QTreeWidget *CellTree;
    QTreeWidget *treeWidget;
    QGraphicsView *graphicsView;
    QToolBox *RightToolbox;
    QWidget *simopt;
    QGridLayout *gridLayout_2;
    QLabel *nbcellslab;
    QSpinBox *spinNbcells;
    QLabel *boxsizelab;
    QDoubleSpinBox *spinDepth;
    QLabel *label_3;
    QDoubleSpinBox *spinWidth;
    QLabel *label_4;
    QDoubleSpinBox *spinHeight;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_2;
    QCheckBox *checkBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpacerItem *verticalSpacer;
    QWidget *othopt;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *LogPanel;
    QProgressBar *ProcessProgressBar;
    QLabel *ProcessStatus;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuLaunch;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1061, 745);
        actionRun = new QAction(MainWindowClass);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icoRun/fleche verte.gif"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon);
        actionRun->setIconVisibleInMenu(true);
        centralwidget = new QWidget(MainWindowClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        CellTree = new QTreeWidget(widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        CellTree->setHeaderItem(__qtreewidgetitem);
        CellTree->setObjectName(QString::fromUtf8("CellTree"));
        CellTree->setMaximumSize(QSize(200, 16777215));
        CellTree->setLineWidth(1);

        gridLayout_3->addWidget(CellTree, 0, 0, 1, 1);

        treeWidget = new QTreeWidget(widget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem1);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMaximumSize(QSize(200, 16777215));

        gridLayout_3->addWidget(treeWidget, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setFrameShape(QFrame::StyledPanel);

        gridLayout_3->addWidget(graphicsView, 0, 1, 2, 1);

        RightToolbox = new QToolBox(widget);
        RightToolbox->setObjectName(QString::fromUtf8("RightToolbox"));
        RightToolbox->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(RightToolbox->sizePolicy().hasHeightForWidth());
        RightToolbox->setSizePolicy(sizePolicy1);
        RightToolbox->setMaximumSize(QSize(250, 16777215));
        RightToolbox->setFrameShape(QFrame::StyledPanel);
        simopt = new QWidget();
        simopt->setObjectName(QString::fromUtf8("simopt"));
        simopt->setGeometry(QRect(0, 0, 254, 313));
        gridLayout_2 = new QGridLayout(simopt);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        nbcellslab = new QLabel(simopt);
        nbcellslab->setObjectName(QString::fromUtf8("nbcellslab"));

        gridLayout_2->addWidget(nbcellslab, 0, 0, 1, 1);

        spinNbcells = new QSpinBox(simopt);
        spinNbcells->setObjectName(QString::fromUtf8("spinNbcells"));
        spinNbcells->setMaximum(999);
        spinNbcells->setValue(20);

        gridLayout_2->addWidget(spinNbcells, 0, 2, 1, 2);

        boxsizelab = new QLabel(simopt);
        boxsizelab->setObjectName(QString::fromUtf8("boxsizelab"));

        gridLayout_2->addWidget(boxsizelab, 1, 0, 1, 1);

        spinDepth = new QDoubleSpinBox(simopt);
        spinDepth->setObjectName(QString::fromUtf8("spinDepth"));
        spinDepth->setMaximum(9999.99);
        spinDepth->setValue(200);

        gridLayout_2->addWidget(spinDepth, 1, 2, 1, 2);

        label_3 = new QLabel(simopt);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        spinWidth = new QDoubleSpinBox(simopt);
        spinWidth->setObjectName(QString::fromUtf8("spinWidth"));
        spinWidth->setMaximum(9999.99);
        spinWidth->setValue(200);

        gridLayout_2->addWidget(spinWidth, 2, 2, 1, 2);

        label_4 = new QLabel(simopt);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        spinHeight = new QDoubleSpinBox(simopt);
        spinHeight->setObjectName(QString::fromUtf8("spinHeight"));
        spinHeight->setMaximum(9999.99);
        spinHeight->setValue(200);

        gridLayout_2->addWidget(spinHeight, 3, 2, 1, 2);

        label = new QLabel(simopt);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 4, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(simopt);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximum(200);
        doubleSpinBox->setSingleStep(0.1);
        doubleSpinBox->setValue(1);

        gridLayout_2->addWidget(doubleSpinBox, 4, 2, 1, 2);

        label_2 = new QLabel(simopt);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 5, 0, 1, 2);

        checkBox = new QCheckBox(simopt);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_2->addWidget(checkBox, 5, 2, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(simopt);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setMaximum(300);

        gridLayout_2->addWidget(doubleSpinBox_2, 6, 0, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(simopt);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setMaximum(300);

        gridLayout_2->addWidget(doubleSpinBox_3, 6, 1, 1, 2);

        doubleSpinBox_4 = new QDoubleSpinBox(simopt);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setMaximum(300);
        doubleSpinBox_4->setValue(1);

        gridLayout_2->addWidget(doubleSpinBox_4, 6, 3, 1, 1);

        label_5 = new QLabel(simopt);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 7, 0, 1, 1);

        label_6 = new QLabel(simopt);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 7, 1, 1, 2);

        label_7 = new QLabel(simopt);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 7, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 8, 1, 1, 1);

        RightToolbox->addItem(simopt, QString::fromUtf8("Simulation options"));
        othopt = new QWidget();
        othopt->setObjectName(QString::fromUtf8("othopt"));
        othopt->setGeometry(QRect(0, 0, 248, 326));
        RightToolbox->addItem(othopt, QString::fromUtf8("Other options"));

        gridLayout_3->addWidget(RightToolbox, 0, 2, 2, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 100));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        LogPanel = new QPlainTextEdit(frame);
        LogPanel->setObjectName(QString::fromUtf8("LogPanel"));
        LogPanel->setReadOnly(true);

        gridLayout_4->addWidget(LogPanel, 0, 0, 1, 2);

        ProcessProgressBar = new QProgressBar(frame);
        ProcessProgressBar->setObjectName(QString::fromUtf8("ProcessProgressBar"));
        ProcessProgressBar->setValue(24);

        gridLayout_4->addWidget(ProcessProgressBar, 1, 0, 1, 1);

        ProcessStatus = new QLabel(frame);
        ProcessStatus->setObjectName(QString::fromUtf8("ProcessStatus"));

        gridLayout_4->addWidget(ProcessStatus, 1, 1, 1, 1);


        gridLayout->addWidget(frame, 1, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1061, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuLaunch = new QMenu(menubar);
        menuLaunch->setObjectName(QString::fromUtf8("menuLaunch"));
        MainWindowClass->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowClass->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuLaunch->menuAction());
        menuLaunch->addAction(actionRun);

        retranslateUi(MainWindowClass);

        RightToolbox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionRun->setText(QApplication::translate("MainWindowClass", "Run", 0, QApplication::UnicodeUTF8));
        nbcellslab->setText(QApplication::translate("MainWindowClass", "Cells", 0, QApplication::UnicodeUTF8));
        boxsizelab->setText(QApplication::translate("MainWindowClass", "Box width", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindowClass", "Box height", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindowClass", "Box depth", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowClass", "Step", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindowClass", "Reduce factor", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindowClass", "iso", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindowClass", "X", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindowClass", "Y", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindowClass", "Z", 0, QApplication::UnicodeUTF8));
        RightToolbox->setItemText(RightToolbox->indexOf(simopt), QApplication::translate("MainWindowClass", "Simulation options", 0, QApplication::UnicodeUTF8));
        RightToolbox->setItemText(RightToolbox->indexOf(othopt), QApplication::translate("MainWindowClass", "Other options", 0, QApplication::UnicodeUTF8));
        LogPanel->setPlainText(QApplication::translate("MainWindowClass", "Welcome to SpidV", 0, QApplication::UnicodeUTF8));
        ProcessStatus->setText(QApplication::translate("MainWindowClass", "Unknow", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0, QApplication::UnicodeUTF8));
        menuLaunch->setTitle(QApplication::translate("MainWindowClass", "Launch", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
