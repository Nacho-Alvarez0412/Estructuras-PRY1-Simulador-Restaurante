/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Simulador
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Simulador)
    {
        if (Simulador->objectName().isEmpty())
            Simulador->setObjectName(QString::fromUtf8("Simulador"));
        Simulador->resize(800, 602);
        centralwidget = new QWidget(Simulador);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Simulador->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Simulador);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Simulador->setMenuBar(menubar);
        statusbar = new QStatusBar(Simulador);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Simulador->setStatusBar(statusbar);

        retranslateUi(Simulador);

        QMetaObject::connectSlotsByName(Simulador);
    } // setupUi

    void retranslateUi(QMainWindow *Simulador)
    {
        Simulador->setWindowTitle(QCoreApplication::translate("Simulador", "Simulador", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Simulador: public Ui_Simulador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
