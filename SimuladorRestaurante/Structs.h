#ifndef STRUCTS_H
#define STRUCTS_H
#include "Header.h"

struct Client{
    int size;
    int id;

    Client(int id){
        this->size = 0; //random 1-7
        this->id = id; //id = prev id ++;
    }


};

struct NodoClient{
    Client* data;
    Client* nxt;

    //NodoClient()= default;

};

struct Entrance{
    NodoClient* first;
    NodoClient* last;

    //Entrance()= default;

    void queue(NodoClient*);
    NodoClient* unQueue(bool);
    bool checkPriority();

};

struct Ingredient{
    QString name;
    Ingredient* nxt;

    Ingredient(QString name){
        this->name = name;
        this->nxt = nullptr;
    }

};

struct Recipe{
    Ingredient* first;

    //Recipe()= default;

    void insert(Ingredient*);
};

struct Dish{
    int id;
    QString name;
    int type;
    int time;
    int wTime;
    Recipe * recipe;
    int price;
    int state;

   Dish(int id, QString name, int type, int time, int wTime, Recipe* recipe, int price, int state){
       this->id = id;
       this->name = name;
       this->type = type;
       this->time = time;
       this->wTime = wTime;
       this->recipe = recipe;
       this->price = price;
       this->state = state;
    }

   QString toString();

};

struct Dishes{
    Dish* data;
    Dish* nxt;

    //Dishes()= default;
};

struct Receipt{
    Dish* dishes[18]={};
    int total;
    int table;

    //Receipt()= default;

    int totalDue();
};

struct NodoReceipt{
    Receipt* data;
    Receipt* nxt;

    //NodoReceipt()= default;

};

struct Receipts{
    NodoReceipt*first;

    //Receipts()= default;
};

struct Table{
    bool vancancy;
    Client* client;
    Dish* dishes[18]={};
    Receipts* receipts;

    //Table()= default;

};

struct Order{
    Dishes* dishes;
    int table;
    short satate;

    //Order()= default;
};

struct NodoOrder{
    Order* data;
    Order* nxt;

    //NodoOrder()= default;
};

struct Waiter{
    Table* tables[20]={};
    Order* order;

    //Waiter()= default;
};

struct Kitchen{
    NodoOrder* first;

    //Kitchen()= default;
};

struct Dishwasher{
    NodoOrder* first;
    int cont;

    //Dishwasher()= default;
};

struct Checkout{
    NodoOrder* first;
    NodoOrder* last;

    //Checkout()= default;
};

#endif // STRUCTS_H
