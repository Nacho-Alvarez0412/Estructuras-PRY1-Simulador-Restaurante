#include "dialogreserves.h"
#include "ui_dialogreserves.h"

DialogReserves::DialogReserves(QWidget *parent,ClientAssignerGenerator* clientAssigner) :
    QDialog(parent),
    ui(new Ui::DialogReserves)
{
    this->setStyleSheet("background-color: rgb(213, 180, 143)");
    this->clientAssigner = clientAssigner;
    ui->setupUi(this);
    ui->label_3->setVisible(false);
}

DialogReserves::~DialogReserves()
{
    delete ui;
}

void DialogReserves::on_pushButton_clicked()
{
    int id = ui->spinBox->text().toInt();

    if(clientAssigner->setReserve(id))
        this->close();
    else
        ui->label_3->setVisible(true);
}
