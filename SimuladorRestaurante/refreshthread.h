#ifndef REFRESHTHREAD_H
#define REFRESHTHREAD_H

#include <QMainWindow>
#include "Structs.h"

class RefreshThread : public QThread
{
public:
    //Campos
    bool running;
    QMainWindow*window;

    //Constructor
    RefreshThread();
    void __init__(QMainWindow*);
    void run();
};

#endif // REFRESHTHREAD_H
