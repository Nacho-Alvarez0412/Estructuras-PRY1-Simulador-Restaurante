#ifndef DIALOGMENUPORCENTAGES_H
#define DIALOGMENUPORCENTAGES_H

#include <QDialog>
#include "Structs.h"

namespace Ui {
class DialogMenuPorcentages;
}

class DialogMenuPorcentages : public QDialog
{
    Q_OBJECT

public:
    int entrance;
    int meal;
    int dessert;
    Menu* menu;
    explicit DialogMenuPorcentages(QWidget *parent = nullptr,Menu* menu = nullptr);
    ~DialogMenuPorcentages();

private slots:
    void on_ConfigButton_clicked();

private:
    Ui::DialogMenuPorcentages *ui;
};

#endif // DIALOGMENUPORCENTAGES_H
