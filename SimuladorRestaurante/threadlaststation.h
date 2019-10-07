#ifndef THREADLASTSTATION_H
#define THREADLASTSTATION_H

#include "Structs.h"

class ThreadLastStation : public QThread{
public:
    //atributos
    bool running;
    bool pause;
    int cash;
    int washed;
    bool mode;
    QString writeCash;
    QTextEdit* cashierInfo;
    QTextEdit* dishwasherInfo;
    ListaSimple<Dish>* dishes;
    QLabel* dishesWashed;
    QLabel* totalEarnings;

    //constructor
    ThreadLastStation();

    //metodos
    void __init__(ListaSimple<Dish>* dishes, QTextEdit* cashierI, QTextEdit* dishwasherI,QLabel* dishesWashed,QLabel* totalEarnings);
    void run();
    void Pause();
    void Unpause();
    void addDish(Dish* dish);
    Node<Dish>* erase(Node<Dish>* deleted);
    Node<Dish>* peek();
    void queue();
    void stack();
};

#endif // THREADLASTSTATION_H
