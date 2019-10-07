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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_WaiterDialog
{
public:
    QLabel *waiterID;
    QLabel *waiterImage;
    QLabel *waiterLabel;
    QLabel *label_2;
    QTextEdit *WaiterTextField;
    QPushButton *pushButton;
    QPushButton *UpdateBitacora;
    QLabel *label_3;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;

    void setupUi(QDialog *WaiterDialog)
    {
        if (WaiterDialog->objectName().isEmpty())
            WaiterDialog->setObjectName(QString::fromUtf8("WaiterDialog"));
        WaiterDialog->resize(692, 486);
        waiterID = new QLabel(WaiterDialog);
        waiterID->setObjectName(QString::fromUtf8("waiterID"));
        waiterID->setGeometry(QRect(150, 10, 51, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        waiterID->setFont(font);
        waiterImage = new QLabel(WaiterDialog);
        waiterImage->setObjectName(QString::fromUtf8("waiterImage"));
        waiterImage->setGeometry(QRect(400, 130, 251, 281));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        waiterImage->setFont(font1);
        waiterLabel = new QLabel(WaiterDialog);
        waiterLabel->setObjectName(QString::fromUtf8("waiterLabel"));
        waiterLabel->setGeometry(QRect(10, 10, 131, 81));
        waiterLabel->setFont(font);
        label_2 = new QLabel(WaiterDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 180, 111, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        label_2->setFont(font2);
        WaiterTextField = new QTextEdit(WaiterDialog);
        WaiterTextField->setObjectName(QString::fromUtf8("WaiterTextField"));
        WaiterTextField->setEnabled(true);
        WaiterTextField->setGeometry(QRect(30, 220, 341, 231));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(true);
        font3.setWeight(50);
        WaiterTextField->setFont(font3);
        WaiterTextField->setReadOnly(true);
        pushButton = new QPushButton(WaiterDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 380, 111, 41));
        pushButton->setFont(font1);
        UpdateBitacora = new QPushButton(WaiterDialog);
        UpdateBitacora->setObjectName(QString::fromUtf8("UpdateBitacora"));
        UpdateBitacora->setGeometry(QRect(470, 430, 111, 41));
        UpdateBitacora->setFont(font1);
        label_3 = new QLabel(WaiterDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 121, 171, 31));
        label_3->setFont(font1);
        spinBox = new QSpinBox(WaiterDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(210, 126, 43, 25));
        spinBox->setMinimum(1);
        pushButton_2 = new QPushButton(WaiterDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 120, 151, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font4.setPointSize(16);
        font4.setBold(false);
        font4.setItalic(true);
        font4.setWeight(50);
        pushButton_2->setFont(font4);

        retranslateUi(WaiterDialog);

        QMetaObject::connectSlotsByName(WaiterDialog);
    } // setupUi

    void retranslateUi(QDialog *WaiterDialog)
    {
        WaiterDialog->setWindowTitle(QCoreApplication::translate("WaiterDialog", "Dialog", nullptr));
        waiterID->setText(QCoreApplication::translate("WaiterDialog", "0", nullptr));
        waiterImage->setText(QString());
        waiterLabel->setText(QCoreApplication::translate("WaiterDialog", "Mesero", nullptr));
        label_2->setText(QCoreApplication::translate("WaiterDialog", "Bitacora:", nullptr));
        pushButton->setText(QCoreApplication::translate("WaiterDialog", "Pausar", nullptr));
        UpdateBitacora->setText(QCoreApplication::translate("WaiterDialog", "Update", nullptr));
        label_3->setText(QCoreApplication::translate("WaiterDialog", "Tiempo de atencion: ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("WaiterDialog", "Ajustar Tiempo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaiterDialog: public Ui_WaiterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITERDIALOG_H
