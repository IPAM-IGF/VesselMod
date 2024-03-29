/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Oct 18 16:31:52 2011
**      by: Qt User Interface Compiler version 4.7.4
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
#include <QtGui/QComboBox>
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
#include <QtGui/QPushButton>
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
    QAction *actionDelete_cells;
    QAction *actionClear;
    QAction *actionRedraw;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *LogPanel;
    QProgressBar *ProcessProgressBar;
    QLabel *ProcessStatus;
    QFrame *frame1;
    QGridLayout *gridLayout_3;
    QTreeWidget *CellTree;
    QGraphicsView *graphicsView;
    QToolBox *RightToolbox;
    QWidget *simopt;
    QGridLayout *gridLayout_2;
    QLabel *nbcellslab;
    QSpinBox *spinNbcells;
    QLabel *Radiuslab;
    QDoubleSpinBox *radiusSpin;
    QLabel *boxsizelab;
    QLabel *heightlab;
    QLabel *depthlab;
    QLabel *timeLab;
    QDoubleSpinBox *maxtimeSpin;
    QLabel *label;
    QDoubleSpinBox *stepSpin;
    QLabel *label_2;
    QDoubleSpinBox *reduceFX;
    QDoubleSpinBox *reduceFY;
    QDoubleSpinBox *reduceFZ;
    QLabel *label_6;
    QLabel *label_7;
    QSpacerItem *verticalSpacer;
    QCheckBox *isocheckBox;
    QLabel *label_5;
    QLabel *containerlab;
    QComboBox *containerComboBox;
    QDoubleSpinBox *spinDepth;
    QDoubleSpinBox *spinWidth;
    QDoubleSpinBox *spinHeight;
    QWidget *othopt;
    QPushButton *relaxButton;
    QTreeWidget *containerTree;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuLaunch;
    QMenu *menuCache;
    QMenu *menuView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1023, 668);
        MainWindowClass->setStyleSheet(QString::fromUtf8(""));
        actionRun = new QAction(MainWindowClass);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icoRun/images/fleche verte.gif"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon);
        actionRun->setIconVisibleInMenu(true);
        actionDelete_cells = new QAction(MainWindowClass);
        actionDelete_cells->setObjectName(QString::fromUtf8("actionDelete_cells"));
        actionClear = new QAction(MainWindowClass);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        actionRedraw = new QAction(MainWindowClass);
        actionRedraw->setObjectName(QString::fromUtf8("actionRedraw"));
        centralwidget = new QWidget(MainWindowClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"/*background-color:white;\n"
"background-image: url(:/backgroundimg/background.jpg);*/\n"
"} \n"
""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 100));
        frame->setSizeIncrement(QSize(0, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        LogPanel = new QPlainTextEdit(frame);
        LogPanel->setObjectName(QString::fromUtf8("LogPanel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LogPanel->sizePolicy().hasHeightForWidth());
        LogPanel->setSizePolicy(sizePolicy);
        LogPanel->setSizeIncrement(QSize(0, 0));
        LogPanel->setReadOnly(true);

        gridLayout_4->addWidget(LogPanel, 0, 0, 1, 2);

        ProcessProgressBar = new QProgressBar(frame);
        ProcessProgressBar->setObjectName(QString::fromUtf8("ProcessProgressBar"));
        ProcessProgressBar->setValue(0);

        gridLayout_4->addWidget(ProcessProgressBar, 1, 0, 1, 1);

        ProcessStatus = new QLabel(frame);
        ProcessStatus->setObjectName(QString::fromUtf8("ProcessStatus"));
        ProcessStatus->setMinimumSize(QSize(200, 0));
        ProcessStatus->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(ProcessStatus, 1, 1, 1, 1);


        gridLayout->addWidget(frame, 1, 0, 1, 1);

        frame1 = new QFrame(centralwidget);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setFrameShape(QFrame::StyledPanel);
        gridLayout_3 = new QGridLayout(frame1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        CellTree = new QTreeWidget(frame1);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        CellTree->setHeaderItem(__qtreewidgetitem);
        CellTree->setObjectName(QString::fromUtf8("CellTree"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CellTree->sizePolicy().hasHeightForWidth());
        CellTree->setSizePolicy(sizePolicy1);
        CellTree->setMinimumSize(QSize(250, 0));
        CellTree->setMaximumSize(QSize(200, 16777215));
        CellTree->setLineWidth(1);
        CellTree->setSortingEnabled(true);
        CellTree->setAnimated(true);
        CellTree->setHeaderHidden(false);
        CellTree->header()->setVisible(true);
        CellTree->header()->setCascadingSectionResizes(false);
        CellTree->header()->setDefaultSectionSize(100);
        CellTree->header()->setHighlightSections(false);
        CellTree->header()->setProperty("showSortIndicator", QVariant(true));

        gridLayout_3->addWidget(CellTree, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(frame1);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setStyleSheet(QString::fromUtf8(""));
        graphicsView->setFrameShape(QFrame::StyledPanel);

        gridLayout_3->addWidget(graphicsView, 0, 1, 2, 1);

        RightToolbox = new QToolBox(frame1);
        RightToolbox->setObjectName(QString::fromUtf8("RightToolbox"));
        RightToolbox->setEnabled(true);
        sizePolicy.setHeightForWidth(RightToolbox->sizePolicy().hasHeightForWidth());
        RightToolbox->setSizePolicy(sizePolicy);
        RightToolbox->setMinimumSize(QSize(250, 0));
        RightToolbox->setMaximumSize(QSize(250, 16777215));
        RightToolbox->setFrameShape(QFrame::StyledPanel);
        simopt = new QWidget();
        simopt->setObjectName(QString::fromUtf8("simopt"));
        simopt->setGeometry(QRect(0, 0, 263, 366));
        gridLayout_2 = new QGridLayout(simopt);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        nbcellslab = new QLabel(simopt);
        nbcellslab->setObjectName(QString::fromUtf8("nbcellslab"));

        gridLayout_2->addWidget(nbcellslab, 0, 0, 1, 1);

        spinNbcells = new QSpinBox(simopt);
        spinNbcells->setObjectName(QString::fromUtf8("spinNbcells"));
        spinNbcells->setMaximum(999);
        spinNbcells->setValue(20);

        gridLayout_2->addWidget(spinNbcells, 0, 1, 1, 1);

        Radiuslab = new QLabel(simopt);
        Radiuslab->setObjectName(QString::fromUtf8("Radiuslab"));

        gridLayout_2->addWidget(Radiuslab, 1, 0, 1, 1);

        radiusSpin = new QDoubleSpinBox(simopt);
        radiusSpin->setObjectName(QString::fromUtf8("radiusSpin"));
        radiusSpin->setMaximum(300);
        radiusSpin->setValue(20);

        gridLayout_2->addWidget(radiusSpin, 1, 1, 1, 1);

        boxsizelab = new QLabel(simopt);
        boxsizelab->setObjectName(QString::fromUtf8("boxsizelab"));

        gridLayout_2->addWidget(boxsizelab, 3, 0, 1, 1);

        heightlab = new QLabel(simopt);
        heightlab->setObjectName(QString::fromUtf8("heightlab"));

        gridLayout_2->addWidget(heightlab, 4, 0, 1, 1);

        depthlab = new QLabel(simopt);
        depthlab->setObjectName(QString::fromUtf8("depthlab"));

        gridLayout_2->addWidget(depthlab, 6, 0, 1, 1);

        timeLab = new QLabel(simopt);
        timeLab->setObjectName(QString::fromUtf8("timeLab"));

        gridLayout_2->addWidget(timeLab, 7, 0, 1, 1);

        maxtimeSpin = new QDoubleSpinBox(simopt);
        maxtimeSpin->setObjectName(QString::fromUtf8("maxtimeSpin"));
        maxtimeSpin->setMaximum(9999);
        maxtimeSpin->setValue(150);

        gridLayout_2->addWidget(maxtimeSpin, 7, 1, 1, 1);

        label = new QLabel(simopt);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 8, 0, 1, 1);

        stepSpin = new QDoubleSpinBox(simopt);
        stepSpin->setObjectName(QString::fromUtf8("stepSpin"));
        stepSpin->setMaximum(200);
        stepSpin->setSingleStep(0.1);
        stepSpin->setValue(1);

        gridLayout_2->addWidget(stepSpin, 8, 1, 1, 1);

        label_2 = new QLabel(simopt);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 9, 0, 1, 2);

        reduceFX = new QDoubleSpinBox(simopt);
        reduceFX->setObjectName(QString::fromUtf8("reduceFX"));
        reduceFX->setMaximum(300);

        gridLayout_2->addWidget(reduceFX, 10, 0, 1, 1);

        reduceFY = new QDoubleSpinBox(simopt);
        reduceFY->setObjectName(QString::fromUtf8("reduceFY"));
        reduceFY->setMaximum(300);

        gridLayout_2->addWidget(reduceFY, 10, 1, 1, 1);

        reduceFZ = new QDoubleSpinBox(simopt);
        reduceFZ->setObjectName(QString::fromUtf8("reduceFZ"));
        reduceFZ->setMaximum(300);
        reduceFZ->setValue(1);

        gridLayout_2->addWidget(reduceFZ, 10, 2, 1, 1);

        label_6 = new QLabel(simopt);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 11, 1, 1, 1);

        label_7 = new QLabel(simopt);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 11, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 12, 1, 1, 1);

        isocheckBox = new QCheckBox(simopt);
        isocheckBox->setObjectName(QString::fromUtf8("isocheckBox"));

        gridLayout_2->addWidget(isocheckBox, 9, 2, 1, 1);

        label_5 = new QLabel(simopt);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 11, 0, 1, 1);

        containerlab = new QLabel(simopt);
        containerlab->setObjectName(QString::fromUtf8("containerlab"));

        gridLayout_2->addWidget(containerlab, 2, 0, 1, 1);

        containerComboBox = new QComboBox(simopt);
        containerComboBox->setObjectName(QString::fromUtf8("containerComboBox"));

        gridLayout_2->addWidget(containerComboBox, 2, 1, 1, 1);

        spinDepth = new QDoubleSpinBox(simopt);
        spinDepth->setObjectName(QString::fromUtf8("spinDepth"));
        spinDepth->setMaximum(9999.99);
        spinDepth->setValue(200);

        gridLayout_2->addWidget(spinDepth, 6, 1, 1, 1);

        spinWidth = new QDoubleSpinBox(simopt);
        spinWidth->setObjectName(QString::fromUtf8("spinWidth"));
        spinWidth->setMaximum(9999.99);
        spinWidth->setValue(200);

        gridLayout_2->addWidget(spinWidth, 3, 1, 1, 1);

        spinHeight = new QDoubleSpinBox(simopt);
        spinHeight->setObjectName(QString::fromUtf8("spinHeight"));
        spinHeight->setMaximum(9999.99);
        spinHeight->setValue(200);

        gridLayout_2->addWidget(spinHeight, 4, 1, 1, 1);

        RightToolbox->addItem(simopt, QString::fromUtf8("Simulation options"));
        othopt = new QWidget();
        othopt->setObjectName(QString::fromUtf8("othopt"));
        othopt->setGeometry(QRect(0, 0, 248, 298));
        relaxButton = new QPushButton(othopt);
        relaxButton->setObjectName(QString::fromUtf8("relaxButton"));
        relaxButton->setGeometry(QRect(10, 0, 121, 27));
        RightToolbox->addItem(othopt, QString::fromUtf8("Other options"));

        gridLayout_3->addWidget(RightToolbox, 0, 2, 2, 1);

        containerTree = new QTreeWidget(frame1);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        containerTree->setHeaderItem(__qtreewidgetitem1);
        containerTree->setObjectName(QString::fromUtf8("containerTree"));
        containerTree->setMinimumSize(QSize(250, 0));
        containerTree->setMaximumSize(QSize(200, 16777215));
        containerTree->setFrameShape(QFrame::StyledPanel);
        containerTree->setSortingEnabled(true);
        containerTree->setAnimated(true);
        containerTree->header()->setProperty("showSortIndicator", QVariant(true));

        gridLayout_3->addWidget(containerTree, 1, 0, 1, 1);


        gridLayout->addWidget(frame1, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1023, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuLaunch = new QMenu(menubar);
        menuLaunch->setObjectName(QString::fromUtf8("menuLaunch"));
        menuCache = new QMenu(menubar);
        menuCache->setObjectName(QString::fromUtf8("menuCache"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindowClass->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowClass->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuLaunch->menuAction());
        menubar->addAction(menuCache->menuAction());
        menubar->addAction(menuView->menuAction());
        menuLaunch->addAction(actionRun);
        menuCache->addAction(actionDelete_cells);
        menuView->addAction(actionClear);
        menuView->addAction(actionRedraw);

        retranslateUi(MainWindowClass);

        RightToolbox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "SpidV", 0, QApplication::UnicodeUTF8));
        actionRun->setText(QApplication::translate("MainWindowClass", "Run", 0, QApplication::UnicodeUTF8));
        actionDelete_cells->setText(QApplication::translate("MainWindowClass", "Delete cells", 0, QApplication::UnicodeUTF8));
        actionClear->setText(QApplication::translate("MainWindowClass", "Clear", 0, QApplication::UnicodeUTF8));
        actionRedraw->setText(QApplication::translate("MainWindowClass", "Redraw", 0, QApplication::UnicodeUTF8));
        LogPanel->setPlainText(QApplication::translate("MainWindowClass", "Welcome to SpidV\n"
"", 0, QApplication::UnicodeUTF8));
        ProcessStatus->setText(QApplication::translate("MainWindowClass", "Unknow", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        CellTree->setToolTip(QApplication::translate("MainWindowClass", "List of generated cells", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        nbcellslab->setText(QApplication::translate("MainWindowClass", "Cells", 0, QApplication::UnicodeUTF8));
        Radiuslab->setText(QApplication::translate("MainWindowClass", "Radius", 0, QApplication::UnicodeUTF8));
        boxsizelab->setText(QApplication::translate("MainWindowClass", "Box width", 0, QApplication::UnicodeUTF8));
        heightlab->setText(QApplication::translate("MainWindowClass", "Box height", 0, QApplication::UnicodeUTF8));
        depthlab->setText(QApplication::translate("MainWindowClass", "Box depth", 0, QApplication::UnicodeUTF8));
        timeLab->setText(QApplication::translate("MainWindowClass", "Max time", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowClass", "Step", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindowClass", "Reduce factor", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindowClass", "Y", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindowClass", "Z", 0, QApplication::UnicodeUTF8));
        isocheckBox->setText(QApplication::translate("MainWindowClass", "iso", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindowClass", "X", 0, QApplication::UnicodeUTF8));
        containerlab->setText(QApplication::translate("MainWindowClass", "Container", 0, QApplication::UnicodeUTF8));
        RightToolbox->setItemText(RightToolbox->indexOf(simopt), QApplication::translate("MainWindowClass", "Simulation options", 0, QApplication::UnicodeUTF8));
        relaxButton->setText(QApplication::translate("MainWindowClass", "Relax constrains", 0, QApplication::UnicodeUTF8));
        RightToolbox->setItemText(RightToolbox->indexOf(othopt), QApplication::translate("MainWindowClass", "Other options", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        containerTree->setToolTip(QApplication::translate("MainWindowClass", "List of used containers", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_ACCESSIBILITY
        containerTree->setAccessibleName(QApplication::translate("MainWindowClass", "Containers", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0, QApplication::UnicodeUTF8));
        menuLaunch->setTitle(QApplication::translate("MainWindowClass", "Launch", 0, QApplication::UnicodeUTF8));
        menuCache->setTitle(QApplication::translate("MainWindowClass", "Cache", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindowClass", "View", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
