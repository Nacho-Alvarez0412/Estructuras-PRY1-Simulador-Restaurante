#ifndef FORMCONFIGURATION_H
#define FORMCONFIGURATION_H

#include <QWidget>
#include "Structs.h"

namespace Ui {
class FormConfiguration;
}

class FormConfiguration : public QWidget
{
    Q_OBJECT

public:
    explicit FormConfiguration(QWidget *parent = nullptr,Menu* = nullptr);
    ~FormConfiguration();

    QPixmap KFCLogo = QPixmap("C:/Users/nacho/Dropbox/TEC/Estructura de Datos/Imagenes/kfc.png");
    Menu*menu;
private slots:
    void on_pushButton_clicked();

private:
    Ui::FormConfiguration *ui;
};

#endif // FORMCONFIGURATION_H
