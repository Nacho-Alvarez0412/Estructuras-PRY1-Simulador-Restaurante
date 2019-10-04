#ifndef CHEFTHREAD_H
#define CHEFTHREAD_H

#include "Structs.h"
#include "QtCore"

class ChefThread : public QThread
{
public:
    //Campos
    Chef* chef;
    bool running;
    bool pause;
    ListaSimple<Order>* orders;
    ListaSimple<Order>* cooked;
    QTextEdit* chefTextField;
    Lock* lock;


    //Constructor
    ChefThread();
    void __init__(Lock*,QTextEdit*,Chef* chef,  ListaSimple<Order>* orders,  ListaSimple<Order>* cooked);

    void run();
};

#endif // CHEFTHREAD_H
