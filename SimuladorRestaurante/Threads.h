#ifndef THREADS_H
#define THREADS_H

#include "Structs.h"

class ThreadClientGenerator : QThread{
   //Atributos
public:
   ClientQueue* clientQueue;
   bool start;
   bool pause;
   int  firstInterval;
   int  lastInterval;


   ThreadClientGenerator(){}

   void setIntervalo(int low, int high){
       this->firstInterval = low;
       this->lastInterval = high;
   }


    void __init__(ClientQueue* clientQueue){
       start = true;
       this->clientQueue = clientQueue;
       pause = false;
   }

   void run(){
       int size;
       int sleepTime;
       int cont = 0;
       while (start){
           size = (randomInit(4122001)%6 +1);
           sleepTime = ((randomInit(4122001)%lastInterval) + firstInterval);
           Client * client = new Client(cont,size);
           clientQueue->queued(client);
           qDebug() << "Cliente creado con exito!"<<cont<<" "<<size;
           cont++;
           sleep(sleepTime);
           while (pause)
               sleep(1);
       }
   }

   void  Pause(){
       this->pause = true;
   }

   void  Unpause(){
       this->pause = false;
   }

};


class ThreadClientAssigner : QThread{
    //Atributos
public:
    bool start;
    bool pause;
    ClientQueue* clientQueue;
    ListaSimple<Table>* tables;


    ThreadClientAssigner(){}


    Node<Table> * firstVacancy(){
        Node<Table> * temp = tables->primerNodo;
        while(temp != nullptr){
            if (temp->data->state == 0)
                return temp;
            else
                temp = temp->nxt;
        }
        return nullptr;
    }

    void __init__(ClientQueue*clientQueue,ListaSimple<Table>*tables){
        this->start = true;
        this->pause =  false;
        this->tables = tables;
        this->clientQueue = clientQueue;
    }

    void run() {
        while(start){

            if(clientQueue->top != nullptr){
                Client*client;
                if(firstVacancy() != nullptr){
                    client = clientQueue->unqueue(false)->data;
                    Table* table = firstVacancy()->data;
                    table->setClient(client);
                    qDebug() << "Sentado con exito";
                }
                else
                    qDebug() << "Esta lleno.... esperando";
            }
            else
                qDebug() << "No hay nadie en cola";

            sleep(5);
            while(pause){
                sleep(1);
                qDebug() << "Restaurante cerrado, nadie entra";
            }

        }
    }

    void Pause(){
        this->pause = true;
    }

    void Unpause(){
        this->pause = false;
    }
};



class ThreadKitchen : QThread{
    //Atributos
public:
    bool start;
    bool pause;
    Chef* chefs[3] = {new Chef(false), new Chef(false), new Chef(false)};

    //Constructor
    ThreadKitchen(){}

    //Metodos
    void __init__(int cant){
        this->start = true;
        this->pause = false;
        switch(cant){
        case 1:
            this->chefs[0]->activate = true;
            this->chefs[1]->activate = this->chefs[2]->activate = false;
            break;
        case 3:
            this->chefs[0]->activate = this->chefs[1]->activate = this->chefs[2]->activate = true;
            break;
        default:
            this->chefs[0]->activate = this->chefs[1]->activate = this->chefs[2]->activate = false;
            break;
        }
    }

    void run() {
        //Working on it
    }

    void Pause(){
        this->pause = true;
    }

    void Unpause(){
        this->pause = false;
    }

    void switchChef(int id){
        if (0 < id && id < 4)
            this->chefs[id]->activate = !this->chefs[id]->activate;
    }
};


class ThreadDishWasher : QThread{
    //Atributos
public:
    bool start;
    bool pause;
    Stack<Dish>* dishes;
    int total;

    //Constructor
    ThreadDishWasher(){}

    //Metodos
    void __init__(Stack<Dish>* dishes){
        this->start = true;
        this->pause = false;
        this->dishes = dishes;
        this->total = 0;
    }

    void run() {
        while(start){
            Node<Dish>* ptr = this->dishes->peek();
            if (ptr != nullptr){
                sleep(ptr->data->washTime);
                this->total++;
                dishes->pop();
            }
            while(pause)
                sleep(1);
        }
    }

    void Pause(){
        this->pause = true;
    }

    void Unpause(){
        this->pause = false;
    }

    void addDish(Dish* dish){
        dishes->push(dish);
    }

};


#endif // THREADS_H
