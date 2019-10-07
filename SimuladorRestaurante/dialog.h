#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "clientgeneratorthread.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    int max;
    int min;
    ClientGeneratorThread* clientThread;

    explicit Dialog(QWidget *parent = nullptr,ClientGeneratorThread* clienThread = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
