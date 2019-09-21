#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <QMainWindow>
#include <QString>
#include <QThread>
#include <QRandomGenerator>
#include <QDebug>

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

// Prototipos de Estructuras

struct Restaurant;

/// Uses:

struct Entrance;

// Uses:
struct Client;
struct ClientNode;
struct ClientQueue;
class ClientAssigner; // Thread
class ClientGenerator; // Tread
// End Entrance


struct DinningRoom;

//Uses:
struct Table;
struct Waiter;
struct Cashier;
struct Dish;
struct Order;
struct OrderNode;
struct OrderQueue;
// End DinningRoom




/// End Restaurant


/// Funciones globales


static int randomInit(int seed)
{
    std::uniform_int_distribution<int> dist(1, seed);

    return dist(*QRandomGenerator::global());
}

#endif // SIMULADOR_H
