#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <QMainWindow>
#include <QString>

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

struct Client;
struct NodoClient;
struct Entrance;
struct Ingredient;
struct Recipe;
struct Dish;
struct Dishes;
struct Receipt;
struct NodoReceipt;
struct Receipts;
struct Table;
struct Order;
struct NodoOrder;
struct Waiter;
struct Kitchen;
struct Dishwasher;
struct Checkout;

#endif // SIMULADOR_H
