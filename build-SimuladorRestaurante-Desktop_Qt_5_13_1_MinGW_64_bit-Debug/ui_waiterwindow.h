/********************************************************************************
** Form generated from reading UI file 'waiterwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITERWINDOW_H
#define UI_WAITERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaiterWindow
{
public:
    QLabel *waiterLabel;
    QLabel *waiterID;
    QLabel *waiterImage;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPlainTextEdit *WaiterTextField;

    void setupUi(QWidget *WaiterWindow)
    {
        if (WaiterWindow->objectName().isEmpty())
            WaiterWindow->setObjectName(QString::fromUtf8("WaiterWindow"));
        WaiterWindow->resize(675, 489);
        waiterLabel = new QLabel(WaiterWindow);
        waiterLabel->setObjectName(QString::fromUtf8("waiterLabel"));
        waiterLabel->setGeometry(QRect(10, 0, 131, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        waiterLabel->setFont(font);
        waiterID = new QLabel(WaiterWindow);
        waiterID->setObjectName(QString::fromUtf8("waiterID"));
        waiterID->setGeometry(QRect(150, 0, 51, 81));
        waiterID->setFont(font);
        waiterImage = new QLabel(WaiterWindow);
        waiterImage->setObjectName(QString::fromUtf8("waiterImage"));
        waiterImage->setGeometry(QRect(400, 120, 251, 281));
        label = new QLabel(WaiterWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 100, 181, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label->setFont(font1);
        lineEdit = new QLineEdit(WaiterWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(180, 100, 181, 31));
        label_2 = new QLabel(WaiterWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 170, 111, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Black"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        WaiterTextField = new QPlainTextEdit(WaiterWindow);
        WaiterTextField->setObjectName(QString::fromUtf8("WaiterTextField"));
        WaiterTextField->setEnabled(false);
        WaiterTextField->setGeometry(QRect(30, 210, 311, 221));

        retranslateUi(WaiterWindow);

        QMetaObject::connectSlotsByName(WaiterWindow);
    } // setupUi

    void retranslateUi(QWidget *WaiterWindow)
    {
        WaiterWindow->setWindowTitle(QCoreApplication::translate("WaiterWindow", "Form", nullptr));
        waiterLabel->setText(QCoreApplication::translate("WaiterWindow", "Mesero", nullptr));
        waiterID->setText(QCoreApplication::translate("WaiterWindow", "0", nullptr));
        waiterImage->setText(QString());
        label->setText(QCoreApplication::translate("WaiterWindow", "Atendiendo Mesas: ", nullptr));
        label_2->setText(QCoreApplication::translate("WaiterWindow", "Bitacora:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaiterWindow: public Ui_WaiterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITERWINDOW_H
