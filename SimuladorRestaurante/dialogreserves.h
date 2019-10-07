#ifndef DIALOGRESERVES_H
#define DIALOGRESERVES_H

#include <QDialog>
#include "clientassignergenerator.h"

namespace Ui {
class DialogReserves;
}

class DialogReserves : public QDialog
{
    Q_OBJECT

public:
    ClientAssignerGenerator* clientAssigner;
    ClientQueue* clientQueue;
    explicit DialogReserves(QWidget *parent = nullptr,ClientAssignerGenerator* clientAssigner = nullptr);
    ~DialogReserves();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogReserves *ui;
};

#endif // DIALOGRESERVES_H
