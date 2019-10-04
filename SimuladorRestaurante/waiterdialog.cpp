#include "waiterdialog.h"
#include "ui_waiterdialog.h"

WaiterDialog::WaiterDialog(QWidget *parent,int id,QString bitacora,QString tables) :
    QDialog(parent),
    ui(new Ui::WaiterDialog)
{
    ui->setupUi(this);

    int x = ui->waiterImage->width();
    int y = ui->waiterImage->height();
    ui->waiterImage->setPixmap(WaiterLogo.scaled(x,y,Qt::KeepAspectRatio));

    ui->waiterID->setNum(id);
    ui->WaiterTextField->setText(bitacora);
}

WaiterDialog::~WaiterDialog()
{
    delete ui;
}
