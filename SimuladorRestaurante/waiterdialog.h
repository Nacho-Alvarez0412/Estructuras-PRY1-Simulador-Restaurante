#ifndef WAITERDIALOG_H
#define WAITERDIALOG_H

#include <QDialog>
#include "Structs.h"
#include "waiterthread.h"



namespace Ui {
class WaiterDialog;
}

class WaiterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WaiterDialog(QWidget *parent = nullptr,int id = 0,WaiterThread* waiter = nullptr);
    ~WaiterDialog();

    WaiterThread* waiter;

    QPixmap WaiterLogo = QPixmap("C:/Users/nacho/Dropbox/TEC/Estructura de Datos/Imagenes/waiter.png");

private slots:
    void on_pushButton_clicked();

    void on_UpdateBitacora_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::WaiterDialog *ui;
};

#endif // WAITERDIALOG_H
