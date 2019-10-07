#ifndef DIALOGMENU_H
#define DIALOGMENU_H

#include <QDialog>
#include "Structs.h"

namespace Ui {
class DialogMenu;
}

class DialogMenu : public QDialog
{
    Q_OBJECT

public:
    QPixmap MenuTemplate = QPixmap("C:/Users/nacho/Dropbox/TEC/Estructura de Datos/Imagenes/RusticMenu.jpg");
    explicit DialogMenu(QWidget *parent = nullptr,Menu* menu = nullptr);
    ~DialogMenu();

private:
    Ui::DialogMenu *ui;
};

#endif // DIALOGMENU_H
