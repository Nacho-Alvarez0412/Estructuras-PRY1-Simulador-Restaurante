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
       int cont = 1;
       while (running){
           size = (randomInit(4122001)%6 +1);
           sleepTime = ((randomInit(4122001)%lastInterval) + firstInterval);
           Client * client = new Client(cont,size);
           clientQueue->queued(client);
           qDebug() << "Cliente creado con exito!"<<cont<<" "<<size;
           cont++;
           pause = true;
           sleep(sleepTime+3);
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


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class ThreadClientAssigner : public QThread{
    //Atributos
public:
    bool running;
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
        this->running = true;
        this->pause =  false;
        this->tables = tables;
        this->clientQueue = clientQueue;
    }

    void run() {
        while(running){

            if(clientQueue->top != nullptr){
                Client*client;
                if(firstVacancy() != nullptr){
                    client = clientQueue->unqueue(false)->data;
                    Table* table = firstVacancy()->data;
                    table->setClient(client);
                    qDebug() << client->id;
                    qDebug() << "Sentado con exito";
                    pause = true;
                }
                else
                    qDebug() << "Esta lleno.... esperando";
            }
            else
                qDebug() << "No hay nadie en cola";

            sleep(5);
            while(pause){
                sleep(1);
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class ThreadWaiter : public QThread{
    //Atributos
public:
    bool running;
    bool pause;
    Waiter*waiter;

    //Constructor
    ThreadWaiter(){}

    //Metodos
    void __init__(Waiter*waiter){
        this->running = true;
        this->pause = false;
        this->waiter = waiter;

    }

    void run(){
        while(running){
            Node<Table>*table = waiter->tables->primerNodo;

            if(table->data->state == 1){
                qDebug() << "Atendiendo mesa #" << table->data->id;
            }
            else
                qDebug() << "Mesa vacia";
            table = table->nxt;
            sleep(3);

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

    ListaSimple<Dish>* askOrder(){

    }

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class ThreadChef : public QThread{
    //Atributos
public:
    bool running;
    bool free; //pause
    int type;
    Dish* dish;

    //Constructor
    ThreadChef(){}

    //Metodos
    void __init__(int type){
        this->running = true;
        this->free = true;
        this->dish = nullptr;
        this->type = type;
    }

    void run(){
        while (running){
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class ThreadKitchen : public QThread{
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
    void __init__(){
        // Initialize data
        this->order = new Queue<Dish>();
        this->cooked = new Queue<Dish>();
        this->start = true;
        this->pause = false;

        // Initialize Threads
        this->chefs->insertar(new ThreadChef());
        this->chefs->insertar(new ThreadChef());
        this->chefs->insertar(new ThreadChef());
        this->chefs->insertar(new ThreadChef());
        this->chefs->insertar(new ThreadChef());

        // Asign type Chef
        this->chefs->primerNodo->data->__init__(1);
        this->chefs->primerNodo->nxt->data->__init__(2);
        this->chefs->primerNodo->nxt->nxt->data->__init__(2);
        this->chefs->primerNodo->nxt->nxt->nxt->data->__init__(2);
        this->chefs->primerNodo->nxt->nxt->nxt->nxt->data->__init__(3);

        // Start Threads
        this->chefs->primerNodo->data->start();
        this->chefs->primerNodo->nxt->data->start();
        this->chefs->primerNodo->nxt->nxt->data->start();
        this->chefs->primerNodo->nxt->nxt->nxt->data->start();
        this->chefs->primerNodo->nxt->nxt->nxt->nxt->data->start();
    }

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
                        cooked->queue(dish->data);
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class ThreadDishWasher : public QThread{
    //Atributos
public:
    bool running;
    bool pause;
    Stack<Dish>* dishes;
    int total;

    //Constructor
    ThreadDishWasher(){}

    //Metodos
    void __init__(Stack<Dish>* dishes){
        this->running = true;
        this->pause = false;
        this->dishes = dishes;
        this->total = 0;
    }

    void run() {
        while(running){
            Node<Dish>* ptr = this->dishes->peek();
            sleep(2);
            if (ptr != nullptr){
                sleep(ptr->data->washTime);
                this->total++;
                dishes->pop();
            }
            else
                qDebug() << "No hay platos";
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class ThreadRestaurant : QThread{
public:
    //Campos

    //Constructor
    ThreadRestaurant(){}

    void __init__(){}

    void run(){
        while(true){sleep(1);}
    }
};


#endif // THREADS_H
