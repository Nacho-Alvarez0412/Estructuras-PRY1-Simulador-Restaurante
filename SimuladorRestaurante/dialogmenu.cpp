#include "dialogmenu.h"
#include "ui_dialogmenu.h"

DialogMenu::DialogMenu(QWidget *parent,Menu*menu) :
    QDialog(parent),
    ui(new Ui::DialogMenu)
{
    ui->setupUi(this);

    int x = ui->label->width();
    int y = ui->label->height();
    ui->label->setPixmap(MenuTemplate.scaled(x,y,Qt::KeepAspectRatio));

    ui->textEditEntrance->setText(menu->printEntrance());
    ui->textEditMeal->setText(menu->printMeal());
    ui->textEditDessert->setText(menu->printDessert());


}

DialogMenu::~DialogMenu()
{
    delete ui;
}
