#ifndef STRUCTHEADERS_H
#define STRUCTHEADERS_H

#include <QMainWindow>
#include <QtCore>
#include <QString>
#include <QRandomGenerator>
#include <QDebug>
#include <QMutex>
#include <QLabel>
#include <QTextEdit>

// Prototipos de Estructuras

struct Restaurant;

/// Uses:

struct Entrance;

// Uses:
struct Client;
struct ClientNode;
struct ClientQueue;
class ThreadClientAssigner; // Thread
class ThreadClientGenerator; // Tread
// End Entrance


struct DinningRoom;

//Uses:
struct Table;
//Uses:
struct Bill;
struct Waiter;
struct Cashier;
struct Dish;
struct Order;

// End DinningRoom




/// End Restaurant


/// Funciones globales


static int randomInit(int seed)
{
    std::uniform_int_distribution<int> dist(1, seed);

    return dist(*QRandomGenerator::global());
}

enum TableState{
    available,reservada,eating,waitingWaiter,waitingEntrance,waitingMeal,waitingDessert,done,inactive
};

enum DishType{
    entrance,meal,dessert
};

#endif // STRUCTHEADERS_H
