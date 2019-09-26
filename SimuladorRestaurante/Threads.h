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
    ListaSimple<Order> *kitchenOrders;
    ListaSimple<Order>*kitchenReady;

    //Constructor
    ThreadWaiter(){}

    //Metodos
    void __init__(Waiter*waiter,ListaSimple<Order>*kitchenOrders,ListaSimple<Order>*kitchenReady){
        this->running = true;
        this->pause = false;
        this->waiter = waiter;
        this->kitchenOrders = kitchenOrders;
        this->kitchenReady = kitchenReady;

    }

    void run(){
        while(running){
            Node<Table>*table = waiter->tables->primerNodo;

            while(table != nullptr){

                if(table->data->state == available){
                    qDebug() << "Mesa vacia";
                    table = table->nxt;
                    sleep(3);
                    continue;
                }

                if(table->data->state == waitingWaiter){
                    qDebug() << "Atendiendo mesa #" << table->data->id;

                    Order* pedido =  new Order(table->data->id,entrance);
                    ListaSimple<Dish> *order = askEntrance(table);
                    pedido->setDish(order);
                    sleep(3);

                    qDebug() << "Orden tomada con exito";

                    if(order != nullptr){
                        qDebug() << "Entregando en cocina...";

                        qDebug() << order->size();
                        table->data->state=waitingEntrance;
                        deliverKitchen(pedido);
                        sleep(3);
                        order->primerNodo =  nullptr;

                        qDebug() << "Entrega exitosa";
                    }
                    else{
                        table->data->state=waitingMeal;
                        qDebug() << "No hay platos";
                    }
                    table = table->nxt;
                    //continue;
                }

                else if(table->data->state == waitingEntrance){
                    Node<Order> * temp = kitchenReady->primerNodo;
                    Order * order = nullptr;

                    while(temp != nullptr){
                        qDebug() << "Recogiendo pedido";
                        if (temp ->data->id == table->data->id){
                            order = kitchenReady->primerNodo->data;
                            break;
                        }
                        else
                            temp = temp->nxt;
                    }
                    sleep(3);

                    if(order != nullptr){
                        deliverClient(order,table->data);
                        order = nullptr;
                        qDebug()<<"Entregada con exito";
                    }

                    table= table->nxt;
                    continue;

                }

                sleep(3);

                while(pause)
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


    void deliverKitchen(Order * order){
        kitchenOrders->insertar(order);
    }

    void deliverClient(Order*order,Table*table){
        Node<Dish>*plate = order->dishes->primerNodo;

        while(plate != nullptr){
            table->addDish(plate->data);
            plate = plate->nxt;
        }
        return;
    }


    ListaSimple<Dish> * askEntrance(Node<Table>*table){
        int size = table->data->client->quant;
        int entrada = table->data->menu->Entrada;
        ListaSimple<Dish>* entradas = table->data->menu->getMenuEntrada();
        ListaSimple<Dish> * order = new ListaSimple<Dish>();


        while(size != 0){
            if (entrada == 0){
                return nullptr;
            }
            int prob = (randomInit(4122001)%entrada);
            if(prob <= entrada){
                order->insertar(entradas->search(randomInit(4122001)%entradas->size())->data);
                size--;
            }
            else
                size--;
        }
        return order;
    }

     ListaSimple<Dish> * askMeal(Node<Table>*table){
        int size = table->data->client->quant;
        int fuerte = table->data->menu->PlatoFuerte;
        ListaSimple<Dish>* fuertes = table->data->menu->getMenuPlatoFuerte();
        ListaSimple<Dish> * order = new ListaSimple<Dish>();


        while(size != 0){
            if (fuerte == 0){
                return nullptr;
            }
            int prob = (randomInit(4122001)%fuerte);
            if(prob <= fuerte){
                order->insertar(fuertes->search(randomInit(4122001)%fuertes->size())->data);
                size--;
            }
            else
                size--;
        }
        return order;
    }

     ListaSimple<Dish> * askDessert(Node<Table>*table){
        int size = table->data->client->quant;
        int postre = table->data->menu->Postre;
        ListaSimple<Dish>* postres = table->data->menu->getMenuPostre();
        ListaSimple<Dish> * order = new ListaSimple<Dish>();


        while(size != 0){
            if (postre == 0){
                return nullptr;
            }
            int prob = (randomInit(4122001)%postre);
            if(prob <= postre){
                order->insertar(postres->search(randomInit(4122001)%postres->size())->data);
                size--;
            }
            else
                size--;
        }
        return order;
    }

};


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
