#include "refreshthread.h"

RefreshThread::RefreshThread()
{

}

void RefreshThread::__init__(QMainWindow*window){
    this->running = true;
    this->window = window;
}

void RefreshThread::run(){
    while(running){
        this->window->update();
        sleep(1);
    }
}
