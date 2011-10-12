TEMPLATE = app
TARGET = Vessel
QT += core \
    gui \
    opengl
HEADERS += lib/GlobalDef.h \
    classes/Box.h \
    classes/BoxForce.h \
    classes/CVector.h \
    classes/Cell.h \
    classes/CellForce.h \
    classes/DisplayWindow.h \
    classes/Force.h \
    classes/protoClass.h \
    mainwindow.h
SOURCES += classes/Box.cpp \
    classes/BoxForce.cpp \
    classes/CVector.cpp \
    classes/Cell.cpp \
    classes/CellForce.cpp \
    classes/DisplayWindow.cpp \
    classes/Force.cpp \
    main.cpp \
    mainwindow.cpp
FORMS += mainwindow.ui
RESOURCES += icones.qrc
