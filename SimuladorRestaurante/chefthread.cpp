#include "chefthread.h"

ChefThread::ChefThread()
{

}

void ChefThread::__init__(Lock*lock,QTextEdit*textField,Chef* chef,  ListaSimple<Order>* orders,  ListaSimple<Order>* cooked){
    this->running = true;
    this->pause = true;
    this->chef = chef;
    this->orders = orders;
    this->cooked = cooked;
    this->chefTextField = textField;
    this->lock = lock;
}

void ChefThread::run(){
    while (running){
        orders->mutex.lock();
        Node<Order>* order = orders->primerNodo;
        while (order != nullptr){
            if(order->data->type == chef->type){
                orders->searchAndDestroy(order->data);
                Node<Dish>* dish = order->data->dishes->primerNodo;
                orders->mutex.unlock();
                while (dish != nullptr){
                    sleep(dish->data->cookTime);
                    lock->mutex.lock();
                    chefTextField->append("Plato cocinado de la mesa "+QString::number(order->data->id)+": " +dish->data->name);
                    sleep(2);
                    lock->mutex.unlock();
                    dish = dish->nxt;
                }
                cooked->mutex.lock();
                cooked->insertar(order->data);
                cooked->mutex.unlock();
            }
            else
                orders->mutex.unlock();
            orders->mutex.lock();
            order = order->nxt;
        }
        orders->mutex.unlock();
        while (pause)
            sleep(1);
    }
}
