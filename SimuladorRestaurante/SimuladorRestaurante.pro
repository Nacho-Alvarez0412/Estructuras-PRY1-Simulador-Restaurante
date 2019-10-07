QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chefthread.cpp \
    clientassignergenerator.cpp \
    clientgeneratorthread.cpp \
    clientthread.cpp \
    dialog.cpp \
    dialogmenu.cpp \
    dialogmenuporcentages.cpp \
    dialogreserves.cpp \
    formconfiguration.cpp \
    main.cpp \
    refreshthread.cpp \
    simuladorwindow.cpp \
    threadlaststation.cpp \
    waiterdialog.cpp \
    waiterthread.cpp

HEADERS += \
    RestaurantStructs.h \
    StructHeaders.h \
    Structs.h \
    chefthread.h \
    clientassignergenerator.h \
    clientgeneratorthread.h \
    clientthread.h \
    dialog.h \
    dialogmenu.h \
    dialogmenuporcentages.h \
    dialogreserves.h \
    formconfiguration.h \
    refreshthread.h \
    simuladorwindow.h \
    threadlaststation.h \
    waiterdialog.h \
    waiterthread.h

FORMS += \
    dialog.ui \
    dialogmenu.ui \
    dialogmenuporcentages.ui \
    dialogreserves.ui \
    formconfiguration.ui \
    simuladorwindow.ui \
    waiterdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
