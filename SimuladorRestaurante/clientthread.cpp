#include "clientthread.h"

ClientThread::ClientThread()
{

}

void ClientThread::__init__(Table* table){
    this->table = table;
    this->running = true;
}

void ClientThread::run(){
    while(running){
        if(table->state == eating){
            int eatingTime;
            if(table->course == entrance){
                 eatingTime = obtainTime(entrance);

                 table->mutex.lock();
                 eat(eatingTime);
                 table->mutex.unlock();

                 table->mutex.lock();
                 table->course = meal;
                 table->state = waitingWaiter;
                 table->mutex.unlock();
            }
            else if(table->course == meal){
                eatingTime = obtainTime(meal);

                table->mutex.lock();
                eat(eatingTime);
                table->mutex.unlock();

                table->mutex.lock();
                table->course = dessert;
                table->state = waitingWaiter;
                table->mutex.unlock();
            }
            else{
                eatingTime = obtainTime(dessert);

                table->mutex.lock();
                eat(eatingTime);
                table->mutex.unlock();

                table->mutex.lock();
                table->course = entrance;
                table->state = done;
                table->mutex.unlock();
                painter.fillRect(this->table->rectangle, QBrush(Qt::green, Qt::SolidPattern));
            }
        }
        while(table->state != eating)
            sleep(1);
    }
}


void ClientThread::Pause(){
    this->pause = true;
}

void ClientThread::Unpause(){
    this->pause = false;
}

int ClientThread::obtainTime(DishType type){
    ListaSimple<Dish>* dishes = table->getDishes();
    Node<Dish>* temp = dishes->primerNodo;


    while(temp != nullptr){
        if(temp->data->type == type)
            return temp->data->eatTime;
        else
            temp = temp->nxt;
    }
    return 1; // Nunca recibe este return
}

void ClientThread::eat(int time){
    while (time!=0) {
        table->label->setNum(time);
        time--;
        sleep(1);
    }
    table->label->setNum(0);
}
