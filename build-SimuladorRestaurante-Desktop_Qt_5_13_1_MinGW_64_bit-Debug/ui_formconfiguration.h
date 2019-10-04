/********************************************************************************
** Form generated from reading UI file 'formconfiguration.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCONFIGURATION_H
#define UI_FORMCONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormConfiguration
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *SpinBoxCantMesas;
    QSpinBox *SpinBoxCantMeseros;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;

    void setupUi(QWidget *FormConfiguration)
    {
        if (FormConfiguration->objectName().isEmpty())
            FormConfiguration->setObjectName(QString::fromUtf8("FormConfiguration"));
        FormConfiguration->resize(669, 358);
        label = new QLabel(FormConfiguration);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 80, 451, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        font.setItalic(true);
        label->setFont(font);
        label_2 = new QLabel(FormConfiguration);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 170, 191, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Black"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_3 = new QLabel(FormConfiguration);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 240, 191, 41));
        label_3->setFont(font1);
        SpinBoxCantMesas = new QSpinBox(FormConfiguration);
        SpinBoxCantMesas->setObjectName(QString::fromUtf8("SpinBoxCantMesas"));
        SpinBoxCantMesas->setGeometry(QRect(290, 250, 43, 25));
        SpinBoxCantMesas->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        SpinBoxCantMesas->setMinimum(1);
        SpinBoxCantMesas->setMaximum(20);
        SpinBoxCantMeseros = new QSpinBox(FormConfiguration);
        SpinBoxCantMeseros->setObjectName(QString::fromUtf8("SpinBoxCantMeseros"));
        SpinBoxCantMeseros->setGeometry(QRect(290, 180, 43, 25));
        SpinBoxCantMeseros->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255)"));
        SpinBoxCantMeseros->setMinimum(1);
        SpinBoxCantMeseros->setMaximum(20);
        label_4 = new QLabel(FormConfiguration);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(410, 180, 221, 151));
        label_5 = new QLabel(FormConfiguration);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 20, 501, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(22);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_5->setFont(font2);
        pushButton = new QPushButton(FormConfiguration);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 280, 171, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(FormConfiguration);

        QMetaObject::connectSlotsByName(FormConfiguration);
    } // setupUi

    void retranslateUi(QWidget *FormConfiguration)
    {
        FormConfiguration->setWindowTitle(QCoreApplication::translate("FormConfiguration", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormConfiguration", "<html><head/><body><p><span style=\" color:#ffffff;\">Favor digite la siguiente configuracion antes de emezar</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("FormConfiguration", "<html><head/><body><p><span style=\" color:#ffffff;\">Cantidad de Meseros:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("FormConfiguration", "<html><head/><body><p><span style=\" color:#ffffff;\">Cantidad de Mesas:</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        SpinBoxCantMeseros->setToolTip(QCoreApplication::translate("FormConfiguration", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_4->setText(QString());
        label_5->setText(QCoreApplication::translate("FormConfiguration", "<html><head/><body><p><span style=\" color:#ffffff;\">Simulador de Restaurante</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("FormConfiguration", "Comenzar Simulacion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormConfiguration: public Ui_FormConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCONFIGURATION_H
