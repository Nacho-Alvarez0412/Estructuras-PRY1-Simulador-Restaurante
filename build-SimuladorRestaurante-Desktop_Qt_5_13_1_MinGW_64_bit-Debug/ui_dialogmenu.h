/********************************************************************************
** Form generated from reading UI file 'dialogmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMENU_H
#define UI_DIALOGMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogMenu
{
public:
    QLabel *label;
    QTextEdit *textEditEntrance;
    QTextEdit *textEditDessert;
    QTextEdit *textEditMeal;

    void setupUi(QDialog *DialogMenu)
    {
        if (DialogMenu->objectName().isEmpty())
            DialogMenu->setObjectName(QString::fromUtf8("DialogMenu"));
        DialogMenu->resize(727, 1071);
        label = new QLabel(DialogMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 971, 1021));
        textEditEntrance = new QTextEdit(DialogMenu);
        textEditEntrance->setObjectName(QString::fromUtf8("textEditEntrance"));
        textEditEntrance->setGeometry(QRect(50, 390, 291, 241));
        QFont font;
        font.setFamily(QString::fromUtf8("Californian FB"));
        font.setPointSize(14);
        font.setItalic(true);
        textEditEntrance->setFont(font);
        textEditEntrance->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 180, 143);"));
        textEditEntrance->setFrameShape(QFrame::Panel);
        textEditEntrance->setLineWidth(2);
        textEditEntrance->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditEntrance->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEditEntrance->setReadOnly(true);
        textEditDessert = new QTextEdit(DialogMenu);
        textEditDessert->setObjectName(QString::fromUtf8("textEditDessert"));
        textEditDessert->setGeometry(QRect(50, 710, 291, 271));
        textEditDessert->setFont(font);
        textEditDessert->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 180, 143);"));
        textEditDessert->setFrameShape(QFrame::Panel);
        textEditDessert->setLineWidth(2);
        textEditDessert->setReadOnly(true);
        textEditMeal = new QTextEdit(DialogMenu);
        textEditMeal->setObjectName(QString::fromUtf8("textEditMeal"));
        textEditMeal->setGeometry(QRect(380, 390, 301, 591));
        textEditMeal->setFont(font);
        textEditMeal->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 180, 143);"));
        textEditMeal->setFrameShape(QFrame::Panel);
        textEditMeal->setLineWidth(2);
        textEditMeal->setReadOnly(true);

        retranslateUi(DialogMenu);

        QMetaObject::connectSlotsByName(DialogMenu);
    } // setupUi

    void retranslateUi(QDialog *DialogMenu)
    {
        DialogMenu->setWindowTitle(QCoreApplication::translate("DialogMenu", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogMenu: public Ui_DialogMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMENU_H
