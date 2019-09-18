#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Simulador; }
QT_END_NAMESPACE

class Simulador : public QMainWindow
{
    Q_OBJECT

public:
    Simulador(QWidget *parent = nullptr);
    ~Simulador();

private:
    Ui::Simulador *ui;
};
#endif // SIMULADOR_H
