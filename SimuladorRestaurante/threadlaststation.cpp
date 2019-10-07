#include "threadlaststation.h"

ThreadLastStation::ThreadLastStation(){}

void ThreadLastStation::__init__(ListaSimple<Dish>* dishes, QTextEdit* cashierI, QTextEdit* dishwasherI,QLabel* dishesWashed,QLabel* totalEarnings){
    this->running = true;
    this->pause = true;
    this->cash = 0;
    this->washed = 0;
    this->mode = true;
    this->writeCash = "";
    this->dishes = dishes;
    this->cashierInfo = cashierI;
    this->dishwasherInfo = dishwasherI;
    this->dishesWashed = dishesWashed;
    this->totalEarnings = totalEarnings;
}

void ThreadLastStation::run(){
    while (running){
        while (pause)
            sleep(1);
        dishes->mutex.lock();
        Node<Dish>* dish = peek();
        dishes->mutex.unlock();
        if (dish != nullptr){
            dishwasherInfo->append("Lavando el plato: " + dish->data->name);
            sleep(dish->data->washTime);
            dishwasherInfo->append("Terminado de lavar");
            dishesWashed->setNum(++washed);
            cash += dish->data->price;
            totalEarnings->setNum(cash);
            dishes->mutex.lock();
            erase(dish);
            dishes->mutex.unlock();
        }
    }
}

void ThreadLastStation::Pause(){
    this->pause = true;
}

void ThreadLastStation::Unpause(){
    this->pause = false;
}

void ThreadLastStation::addDish(Dish *dish){
    dishes->insertar(dish);
}

Node<Dish>* ThreadLastStation::erase(Node<Dish>* deleted){
    return this->dishes->searchAndDestroy(deleted->data);
}

Node<Dish>* ThreadLastStation::peek(){
    Node<Dish>* dish = dishes->primerNodo;
    if (mode)
        return dish;
    else {
        if (dish != nullptr){
            while (dish->nxt != nullptr)
                dish = dish->nxt;
        }
        return dish;
    }
}

void ThreadLastStation::queue(){
    this->mode = true;
}

void ThreadLastStation::stack(){
    this->mode = false;
}







