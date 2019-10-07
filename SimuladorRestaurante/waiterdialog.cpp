#include "waiterdialog.h"
#include "ui_waiterdialog.h"

WaiterDialog::WaiterDialog(QWidget *parent,int id,WaiterThread*waiter) :
    QDialog(parent),
    ui(new Ui::WaiterDialog)
{
    ui->setupUi(this);

    int x = ui->waiterImage->width();
    int y = ui->waiterImage->height();
    ui->waiterImage->setPixmap(WaiterLogo.scaled(x,y,Qt::KeepAspectRatio));
    this->setStyleSheet("background-color: rgb(213, 180, 143)");

    this->waiter = waiter;

    if(waiter->pause){
        ui->pushButton->setText("Atender");
    }
    else{
        ui->pushButton->setText("Pausar");
    }

    ui->waiterID->setNum(id);
}

WaiterDialog::~WaiterDialog()
{
    delete ui;
}

void WaiterDialog::on_pushButton_clicked()
{
    ui->WaiterTextField->setText(waiter->bitacora);
    if(waiter->pause){
        waiter->Unpause();
        ui->pushButton->setText("Pausar");
    }
    else{
        waiter->Pause();
        ui->pushButton->setText("Atender");
    }
}

void WaiterDialog::on_UpdateBitacora_clicked()
{
    ui->WaiterTextField->setText(waiter->bitacora);
}

void WaiterDialog::on_pushButton_2_clicked()
{
    waiter->orderTime = ui->spinBox->text().toInt();
}
