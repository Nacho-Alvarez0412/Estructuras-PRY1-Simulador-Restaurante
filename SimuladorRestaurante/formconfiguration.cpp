#include "formconfiguration.h"
#include "ui_formconfiguration.h"
#include "QtCore"
#include "simuladorwindow.h"

FormConfiguration::FormConfiguration(QWidget *parent,Menu*menu) :
    QWidget(parent),
    ui(new Ui::FormConfiguration)
{
    ui->setupUi(this);
    this->menu = menu;
    this->setStyleSheet("background-color: black;");
    int x = ui->label_4->width();
    int y = ui->label_4->height();
    ui->label_4->setPixmap(KFCLogo.scaled(x,y,Qt::KeepAspectRatio));
}

FormConfiguration::~FormConfiguration()
{
    delete ui;
}

void FormConfiguration::on_pushButton_clicked()
{
    int cantMesas = ui->SpinBoxCantMesas->text().toInt();
    int cantMeseros = ui->SpinBoxCantMeseros->text().toInt();

    SimuladorWindow *w = new SimuladorWindow(nullptr,cantMesas,cantMeseros,menu);
    w->show();
    this->close();
}
