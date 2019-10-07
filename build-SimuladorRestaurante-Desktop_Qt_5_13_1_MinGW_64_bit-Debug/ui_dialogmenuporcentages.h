/********************************************************************************
** Form generated from reading UI file 'dialogmenuporcentages.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMENUPORCENTAGES_H
#define UI_DIALOGMENUPORCENTAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogMenuPorcentages
{
public:
    QLabel *TitleLabel;
    QLabel *EntranceLabel;
    QLabel *MealLabel;
    QLabel *DessertLabel;
    QSpinBox *spinBoxEntrance;
    QSpinBox *spinBoxMeal;
    QSpinBox *spinBoxDessert;
    QPushButton *ConfigButton;

    void setupUi(QDialog *DialogMenuPorcentages)
    {
        if (DialogMenuPorcentages->objectName().isEmpty())
            DialogMenuPorcentages->setObjectName(QString::fromUtf8("DialogMenuPorcentages"));
        DialogMenuPorcentages->resize(400, 300);
        TitleLabel = new QLabel(DialogMenuPorcentages);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
        TitleLabel->setGeometry(QRect(50, 10, 381, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        TitleLabel->setFont(font);
        EntranceLabel = new QLabel(DialogMenuPorcentages);
        EntranceLabel->setObjectName(QString::fromUtf8("EntranceLabel"));
        EntranceLabel->setGeometry(QRect(20, 120, 81, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        EntranceLabel->setFont(font1);
        MealLabel = new QLabel(DialogMenuPorcentages);
        MealLabel->setObjectName(QString::fromUtf8("MealLabel"));
        MealLabel->setGeometry(QRect(10, 170, 121, 16));
        MealLabel->setFont(font1);
        DessertLabel = new QLabel(DialogMenuPorcentages);
        DessertLabel->setObjectName(QString::fromUtf8("DessertLabel"));
        DessertLabel->setGeometry(QRect(20, 230, 71, 16));
        DessertLabel->setFont(font1);
        spinBoxEntrance = new QSpinBox(DialogMenuPorcentages);
        spinBoxEntrance->setObjectName(QString::fromUtf8("spinBoxEntrance"));
        spinBoxEntrance->setGeometry(QRect(150, 110, 43, 25));
        spinBoxEntrance->setMaximum(100);
        spinBoxMeal = new QSpinBox(DialogMenuPorcentages);
        spinBoxMeal->setObjectName(QString::fromUtf8("spinBoxMeal"));
        spinBoxMeal->setGeometry(QRect(150, 170, 43, 25));
        spinBoxMeal->setMaximum(100);
        spinBoxDessert = new QSpinBox(DialogMenuPorcentages);
        spinBoxDessert->setObjectName(QString::fromUtf8("spinBoxDessert"));
        spinBoxDessert->setGeometry(QRect(150, 220, 43, 25));
        spinBoxDessert->setMaximum(100);
        ConfigButton = new QPushButton(DialogMenuPorcentages);
        ConfigButton->setObjectName(QString::fromUtf8("ConfigButton"));
        ConfigButton->setGeometry(QRect(229, 164, 121, 31));
        ConfigButton->setFont(font1);

        retranslateUi(DialogMenuPorcentages);

        QMetaObject::connectSlotsByName(DialogMenuPorcentages);
    } // setupUi

    void retranslateUi(QDialog *DialogMenuPorcentages)
    {
        DialogMenuPorcentages->setWindowTitle(QCoreApplication::translate("DialogMenuPorcentages", "Dialog", nullptr));
        TitleLabel->setText(QCoreApplication::translate("DialogMenuPorcentages", "Probabilidad de Platillos", nullptr));
        EntranceLabel->setText(QCoreApplication::translate("DialogMenuPorcentages", "Entrada:", nullptr));
        MealLabel->setText(QCoreApplication::translate("DialogMenuPorcentages", "Plato Fuerte:", nullptr));
        DessertLabel->setText(QCoreApplication::translate("DialogMenuPorcentages", "Postre:", nullptr));
        ConfigButton->setText(QCoreApplication::translate("DialogMenuPorcentages", "Configurar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogMenuPorcentages: public Ui_DialogMenuPorcentages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMENUPORCENTAGES_H
