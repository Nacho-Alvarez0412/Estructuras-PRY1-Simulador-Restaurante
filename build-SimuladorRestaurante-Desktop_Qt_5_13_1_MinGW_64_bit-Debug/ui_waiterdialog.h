/********************************************************************************
** Form generated from reading UI file 'waiterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITERDIALOG_H
#define UI_WAITERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_WaiterDialog
{
public:
    QLabel *waiterID;
    QLabel *label;
    QLineEdit *WaiterTables;
    QLabel *waiterImage;
    QLabel *waiterLabel;
    QLabel *label_2;
    QTextEdit *WaiterTextField;

    void setupUi(QDialog *WaiterDialog)
    {
        if (WaiterDialog->objectName().isEmpty())
            WaiterDialog->setObjectName(QString::fromUtf8("WaiterDialog"));
        WaiterDialog->resize(692, 486);
        waiterID = new QLabel(WaiterDialog);
        waiterID->setObjectName(QString::fromUtf8("waiterID"));
        waiterID->setGeometry(QRect(150, 10, 51, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        waiterID->setFont(font);
        label = new QLabel(WaiterDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 110, 181, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label->setFont(font1);
        WaiterTables = new QLineEdit(WaiterDialog);
        WaiterTables->setObjectName(QString::fromUtf8("WaiterTables"));
        WaiterTables->setEnabled(true);
        WaiterTables->setGeometry(QRect(180, 110, 181, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Black"));
        font2.setBold(true);
        font2.setWeight(75);
        WaiterTables->setFont(font2);
        WaiterTables->setReadOnly(true);
        waiterImage = new QLabel(WaiterDialog);
        waiterImage->setObjectName(QString::fromUtf8("waiterImage"));
        waiterImage->setGeometry(QRect(400, 130, 251, 281));
        waiterLabel = new QLabel(WaiterDialog);
        waiterLabel->setObjectName(QString::fromUtf8("waiterLabel"));
        waiterLabel->setGeometry(QRect(10, 10, 131, 81));
        waiterLabel->setFont(font);
        label_2 = new QLabel(WaiterDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 180, 111, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial Black"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        WaiterTextField = new QTextEdit(WaiterDialog);
        WaiterTextField->setObjectName(QString::fromUtf8("WaiterTextField"));
        WaiterTextField->setEnabled(true);
        WaiterTextField->setGeometry(QRect(30, 220, 341, 231));
        WaiterTextField->setFont(font3);
        WaiterTextField->setReadOnly(true);

        retranslateUi(WaiterDialog);

        QMetaObject::connectSlotsByName(WaiterDialog);
    } // setupUi

    void retranslateUi(QDialog *WaiterDialog)
    {
        WaiterDialog->setWindowTitle(QCoreApplication::translate("WaiterDialog", "Dialog", nullptr));
        waiterID->setText(QCoreApplication::translate("WaiterDialog", "0", nullptr));
        label->setText(QCoreApplication::translate("WaiterDialog", "Atendiendo Mesas: ", nullptr));
        waiterImage->setText(QString());
        waiterLabel->setText(QCoreApplication::translate("WaiterDialog", "Mesero", nullptr));
        label_2->setText(QCoreApplication::translate("WaiterDialog", "Bitacora:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaiterDialog: public Ui_WaiterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITERDIALOG_H
