#include "Structs.h"
#include "ui_GUI.h"

Simulador::Simulador(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Simulador)
{
    ui->setupUi(this);
}

Simulador::~Simulador()
{
    delete ui;
}

