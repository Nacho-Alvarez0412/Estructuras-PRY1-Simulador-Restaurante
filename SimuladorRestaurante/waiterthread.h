#ifndef WAITERTHREAD_H
#define WAITERTHREAD_H

#include "Structs.h"
#include "QtCore"

class WaiterThread : public QThread
{
public:
    //Campos
    bool running;
    bool pause;
    Waiter*waiter;
    ListaSimple<Order> *kitchenOrders;
    ListaSimple<Order> *kitchenReady;
    ListaSimple<Dish> *dirtyDishes;
    QString bitacora;
    QTextEdit* cashierTextField;
    Lock* lock;
    int orderTime;

    WaiterThread();
    void __init__(Lock*lock,Waiter*waiter, ListaSimple<Order> *kitchenOrders, ListaSimple<Order> * kitchenReady,ListaSimple<Dish>*dirtyDish,int,QTextEdit*);
    void run();
    Order* retrieveOrder(ListaSimple<Order>*ready,Table* table);
    void Pause();
    void Unpause();
    void deliverKitchen(Order * order);
    void deliverClient(Order*order,Table*table);
    ListaSimple<Dish> * askEntrance(Node<Table>*table);
    ListaSimple<Dish> * askMeal(Node<Table>*table);
    ListaSimple<Dish> * askDessert(Node<Table>*table);
};

#endif // WAITERTHREAD_H
