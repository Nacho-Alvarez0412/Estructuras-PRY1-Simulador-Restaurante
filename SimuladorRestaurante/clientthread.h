#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include "Structs.h"
#include <QPainter>

class ClientThread : public QThread
{
public:
    //Campos
    Table* table;
    bool running,pause;
    QPainter painter;

    ClientThread();
    void __init__(Table*);
    void run();
    void Pause();
    void Unpause();
    int obtainTime(DishType);
    void eat(int);
};

#endif // CLIENTTHREAD_H
