#ifndef STRUCTS_H
#define STRUCTS_H
#include "Header.h"

struct Client{
    int id;
    int quant;

    Client(int id){
        this->id = id;
        this->quant = qrand() % 7;  // random between 1-6
    }
};


struct ClientNode{

    // Campos
    Client * data;
    ClientNode * nxt;

    // Constructor
    ClientNode(Client* value){
        this->data = value;
    }
};

struct ClientQueue{

    // Campos
    ClientNode* top;
    ClientNode* base;

    //Constructor
    ClientQueue(){
        top = base = nullptr;
    }

    void queued(ClientNode*node){
        if (top == base){
            if (top == nullptr){
                top = base = node;  // Lista vacia
            }
            top->nxt = base = node;  // Lista con 1 nodo
        } else {
            base->nxt = node;  // Lista con 2 o mas nodos
            base = node;
        }
    }

    ClientNode* prevBase(){
        ClientNode* ptr = top;
        if (top != nullptr)
            if (top != base){
                while(ptr->nxt != base){
                    ptr = ptr->nxt;
                }
                return ptr;
            }
        return nullptr;
    }

    ClientNode* unqueue(bool side){  //side=true saca ultimo; side=false saca primero
        ClientNode* deleted;
        if (side){
            deleted = base;
            base = prevBase();
            base->nxt = nullptr;
        } else {
            deleted = top;
            top->nxt = top;
            deleted->nxt = nullptr;
        }
        return deleted;
    }

    bool checkPriority(int id){
        return base->data->id == id;
    }
};

class ClientGenerator : QThread{
    //Atributos
    ClientQueue* clientQueue;
    bool start;
    bool pause;

    //Constructor

    ClientGenerator();

    void __init__(ClientQueue* clientQueue){
        start = true;
        this->clientQueue = clientQueue;
        pause = true;
    }

    void run(){
        int size;
        QRandomGenerator* randInt = new QRandomGenerator();
        while (start){
            size = randInt->bounded(1,6);

            sleep(1); // Debe ser seteado por el usuario!!!
            while (pause)
                sleep(1);
        }
    }

    void StartPause(){
        this->pause = true;
    }

    void StopPause(){
        this->pause = false;
    }




};

#endif // STRUCTS_H
