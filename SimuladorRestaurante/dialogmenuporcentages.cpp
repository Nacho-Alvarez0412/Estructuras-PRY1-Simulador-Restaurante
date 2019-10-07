#include "dialogmenuporcentages.h"
#include "ui_dialogmenuporcentages.h"

DialogMenuPorcentages::DialogMenuPorcentages(QWidget *parent,Menu*menu) :
    QDialog(parent),
    ui(new Ui::DialogMenuPorcentages)
{
    this->menu = menu;
    this->setStyleSheet("background-color: rgb(213, 180, 143)");

    ui->setupUi(this);

}

DialogMenuPorcentages::~DialogMenuPorcentages()
{
    delete ui;
}

void DialogMenuPorcentages::on_ConfigButton_clicked()
{
    menu->Entrada = ui->spinBoxEntrance->text().toInt();
    menu->PlatoFuerte = ui->spinBoxMeal->text().toInt();
    menu->Postre = ui->spinBoxDessert->text().toInt();

    this->close();

}
