#ifndef WAITERDIALOG_H
#define WAITERDIALOG_H

#include <QDialog>

namespace Ui {
class WaiterDialog;
}

class WaiterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WaiterDialog(QWidget *parent = nullptr,int id = 0,QString bitacora = "",QString tables = "");
    ~WaiterDialog();

    QPixmap WaiterLogo = QPixmap("C:/Users/nacho/Dropbox/TEC/Estructura de Datos/Imagenes/waiter.png");

private:
    Ui::WaiterDialog *ui;
};

#endif // WAITERDIALOG_H
