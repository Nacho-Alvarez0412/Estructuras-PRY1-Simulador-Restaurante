#ifndef THREADS_H
#define THREADS_H

#include "Structs.h"

class ThreadClientGenerator : public QThread{
   //Atributos
public:
   ClientQueue* clientQueue;
   bool running;
   bool pause;
   int  firstInterval;
   int  lastInterval;


   ThreadClientGenerator(){}

   void setIntervalo(int low, int high){
       this->firstInterval = low;
       this->lastInterval = high;
   }


    void __init__(ClientQueue* clientQueue){
       running = true;
       this->clientQueue = clientQueue;
       pause = false;
   }

   void run(){
       int size;
       int sleepTime;
       int cont = 0;
       while (running){
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

class ThreadChef : QThread{
    //Atributos
public:
    bool start;
    bool free; //pause
    int type;
    Dish* dish;

    //Constructor
    ThreadChef(){}

    //Metodos
    void __init__(int type){
        this->start = true;
        this->free = true;
        this->dish = nullptr;
        this->type = type;
    }

    void run(){
        while (start){
            while (free)
                sleep(1);
            sleep(dish->cookTime);
            dish->id++;
            free = true;
        }
    }

    void Pause(){
        this->free = true;
    }

    void Unpause(){
        this->free = false;
    }

};

class ThreadKitchen : QThread{
    //Atributos
public:
    Queue<Dish>* order;
    Queue<Dish>* cooked;
    bool start;
    bool pause;
    ListaSimple<ThreadChef>* chefs;

    //Constructor
    ThreadKitchen(){}

    //Metodos
    /*void __init__(){
        // Initialize data
        this->order = new Queue<Dish>();
        this->cooked = new Queue<Dish>();
        this->start = true;
        this->pause = false;

        // Initialize Threads
        this->chefs->insertar(new ThreadChef(1));
        this->chefs->insertar(new ThreadChef(2));
        this->chefs->insertar(new ThreadChef(2));
        this->chefs->insertar(new ThreadChef(2));
        this->chefs->insertar(new ThreadChef(3));

        // Start Threads
        this->chefs->primerNodo->data->run();
        this->chefs->primerNodo->nxt->data->run();
        this->chefs->primerNodo->nxt->nxt->data->run();
        this->chefs->primerNodo->nxt->nxt->nxt->data->run();
        this->chefs->primerNodo->nxt->nxt->nxt->nxt->data->run();
    }*/

    void run(){
        while (start){
            Node<Dish>* dish = order->first;
            while (dish != nullptr){
                Node<ThreadChef>* chef = chefs->primerNodo;
                int type = dish->data->id;
                while(chef != nullptr){
                    if (chef->data->free && chef->data->type == type){
                        chef->data->dish = dish->data;
                        chef->data->Unpause();
                        break;
                    }
                    chef = chef->nxt;
                }
                dish = dish->nxt;
            }
            while (pause)
                sleep(1);
        }
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
