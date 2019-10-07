/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinBoxMin;
    QSpinBox *spinBoxMax;
    QPushButton *pushButton;
    QLabel *label_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 234);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 10, 371, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 100, 81, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 140, 81, 16));
        label_3->setFont(font1);
        spinBoxMin = new QSpinBox(Dialog);
        spinBoxMin->setObjectName(QString::fromUtf8("spinBoxMin"));
        spinBoxMin->setGeometry(QRect(110, 90, 43, 25));
        spinBoxMin->setMinimum(1);
        spinBoxMax = new QSpinBox(Dialog);
        spinBoxMax->setObjectName(QString::fromUtf8("spinBoxMax"));
        spinBoxMax->setGeometry(QRect(110, 130, 43, 25));
        spinBoxMax->setMinimum(1);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 110, 121, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        pushButton->setFont(font2);
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 180, 351, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font3.setPointSize(11);
        font3.setItalic(true);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Configuracion Intervalos ", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Minimo:", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Maximo:", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Configurar", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "El valor maximo debe ser mayor que el minimo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
