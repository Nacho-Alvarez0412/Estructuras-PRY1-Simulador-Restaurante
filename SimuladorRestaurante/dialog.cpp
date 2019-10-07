#include "dialog.h"
#include "ui_dialog.h"
#include "Structs.h"

Dialog::Dialog(QWidget *parent,ClientGeneratorThread*clientGenerator) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    this->clientThread = clientGenerator;
    this->setStyleSheet("background-color: rgb(213, 180, 143)");

    ui->setupUi(this);
    ui->label_4->setVisible(false);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    max = ui->spinBoxMax->text().toInt();
    min = ui->spinBoxMin->text().toInt();
    if(max>min){
        clientThread->setIntervalo(min,max);
        this->close();
    }
    else
        ui->label_4->setVisible(true);
}
