/********************************************************************************
** Form generated from reading UI file 'dialogreserves.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGRESERVES_H
#define UI_DIALOGRESERVES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogReserves
{
public:
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QDialog *DialogReserves)
    {
        if (DialogReserves->objectName().isEmpty())
            DialogReserves->setObjectName(QString::fromUtf8("DialogReserves"));
        DialogReserves->resize(487, 323);
        label = new QLabel(DialogReserves);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 10, 371, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        label->setFont(font);
        label_2 = new QLabel(DialogReserves);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 100, 451, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        label_2->setFont(font1);
        spinBox = new QSpinBox(DialogReserves);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(210, 150, 61, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        spinBox->setFont(font2);
        spinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(DialogReserves);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 200, 191, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font3.setPointSize(14);
        font3.setItalic(true);
        pushButton->setFont(font3);
        label_3 = new QLabel(DialogReserves);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 260, 451, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font4.setPointSize(10);
        font4.setItalic(true);
        label_3->setFont(font4);

        retranslateUi(DialogReserves);

        QMetaObject::connectSlotsByName(DialogReserves);
    } // setupUi

    void retranslateUi(QDialog *DialogReserves)
    {
        DialogReserves->setWindowTitle(QCoreApplication::translate("DialogReserves", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogReserves", "Solicitar Reserva", nullptr));
        label_2->setText(QCoreApplication::translate("DialogReserves", "Indique el ID del cliente que desea reservar una mesa:", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogReserves", "Realzar Reserva", nullptr));
        label_3->setText(QCoreApplication::translate("DialogReserves", "El restaurante no tiene mesas disponibles ahora. Favor intentar mas tarde", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogReserves: public Ui_DialogReserves {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRESERVES_H
