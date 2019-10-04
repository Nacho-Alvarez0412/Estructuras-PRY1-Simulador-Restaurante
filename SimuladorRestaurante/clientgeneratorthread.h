#ifndef CLIENTGENERATORTHREAD_H
#define CLIENTGENERATORTHREAD_H

#include "Structs.h"

class ClientGeneratorThread : public QThread
{
public:
    //Campos
    Queue<Client>* clientQueue;
    QLabel * label;
    QTextEdit * textField;
    bool running;
    bool pause;
    int  firstInterval;
    int  lastInterval;

    //Metodos
    ClientGeneratorThread();
    void __init__(QTextEdit*,QLabel*,Queue<Client>*,int,int);
    void setIntervalo(int,int);
    void run();
    void Pause();
    void Unpause();
};

#endif // CLIENTGENERATORTHREAD_H
