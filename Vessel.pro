TEMPLATE = app
TARGET = SpidV
QT += core \
    gui \
    opengl
HEADERS += classes/SphereForce.h \
    classes/Sphere.h \
    classes/Container.h \
    lib/GlobalDef.h \
    classes/Box.h \
    classes/BoxForce.h \
    classes/CVector.h \
    classes/Cell.h \
    classes/CellForce.h \
    classes/DisplayWindow.h \
    classes/Force.h \
    classes/protoClass.h \
    mainwindow.h
SOURCES += classes/SphereForce.cpp \
    classes/Sphere.cpp \
    classes/Container.cpp \
    classes/Box.cpp \
    classes/BoxForce.cpp \
    classes/CVector.cpp \
    classes/Cell.cpp \
    classes/CellForce.cpp \
    classes/DisplayWindow.cpp \
    classes/Force.cpp \
    main.cpp \
    mainwindow.cpp
FORMS += mainwindow.ui
RESOURCES += images/generalImages.qrc \
    icones.qrc
