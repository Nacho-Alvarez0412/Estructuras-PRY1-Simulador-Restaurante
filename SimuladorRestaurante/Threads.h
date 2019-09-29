#ifndef THREADS_H
#define THREADS_H

#include "Structs.h"

class ThreadClientGenerator : public QThread{
   //Atributos
public:
   Queue<Client>* clientQueue;
   bool running;
   bool pause;
   int  firstInterval;
   int  lastInterval;


   ThreadClientGenerator(){}

   void setIntervalo(int low, int high){
       this->firstInterval = low;
       this->lastInterval = high;
   }


    void __init__(Queue<Client>* clientQueue){
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
           clientQueue->mutex.lock();
           clientQueue->queue(client);
           clientQueue->mutex.unlock();
           qDebug() << "Cliente creado con exito!"<<cont<<" "<<size;
           qDebug() << "Tamano de la cola: "<< clientQueue->size();

           cont++;

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
   Queue<Client>* clientQueue;
    ListaSimple<Table>* tables;


    ThreadClientAssigner(){}

    void __init__(Queue<Client>*clientQueue,ListaSimple<Table>*tables){
        this->running = true;
        this->pause =  false;
        this->tables = tables;
        this->clientQueue = clientQueue;
    }

    void run() {
        while(running){

            if(clientQueue->first != nullptr){
                Client*client;
                if(firstVacancy() != nullptr){
                    clientQueue->mutex.lock();
                    client = clientQueue->unqueue()->data;
                    clientQueue->mutex.unlock();
                    Table* table = firstVacancy()->data;
                    table->setClient(client);
                    qDebug() <<"Cliente# " <<client->id;
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
            }

        }
    }

    void Pause(){
        this->pause = true;
    }

    void Unpause(){
        this->pause = false;
    }

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
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class ThreadWaiter : public QThread{
    //Atributos
public:
    bool running;
    bool pause;
    Waiter*waiter;
     ListaSimple<Order> *kitchenOrders;
     ListaSimple<Order> *kitchenReady;

    //Constructor
    ThreadWaiter(){}

    //Metodos
    void __init__(Waiter*waiter, ListaSimple<Order> *kitchenOrders, ListaSimple<Order> * kitchenReady){
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

                if(table->data->state == done){
                    qDebug() << "La mesa # "<< table->data->id<<" Terminaron de comer";
                    table->data->setFree();
                }

                if(table->data->state == available || table->data->state == eating || table->data->state == reserved){
                    qDebug() << "La mesa # "<< table->data->id<< " no necesita atencion";
                    table = table->nxt;
                    sleep(3);
                    continue;
                }

                if(table->data->state == waitingWaiter){
                    qDebug() << "Atendiendo mesa #" << table->data->id;
                    Order* pedido = nullptr;
                    ListaSimple<Dish> *order;

                    if(table->data->course == entrance){
                        pedido =  new Order(table->data->id,entrance);
                        order = askEntrance(table);
                        pedido->setDish(order);
                        table->data->state=waitingEntrance;

                         qDebug() << "Pidio entrada";
                        sleep(3);
                    }
                    else if(table->data->course == meal){
                        pedido =  new Order(table->data->id,meal);
                        order = askMeal(table);
                        pedido->setDish(order);
                        table->data->state=waitingMeal;

                        qDebug() << "Pidio plato fuerte";
                        sleep(3);
                    }
                    else if(table->data->course == dessert){
                        pedido =  new Order(table->data->id,dessert);
                        order = askDessert(table);
                        pedido->setDish(order);
                        table->data->state=waitingDessert;

                         qDebug() << "Pidio postre";
                        sleep(3);
                    }
                    qDebug() << "Orden tomada con exito";
                    qDebug() << "Tamano de la orden: "<<order->size();

                    if(order->size() == 0){
                        qDebug() << "No hay platos";

                        table->data->mutex.lock();

                        if(table->data->state==waitingEntrance){
                            table->data->state = waitingWaiter;
                            table->data->course = meal;
                            table->data->mutex.unlock();
                            table= table->nxt;
                            continue;
                        }

                        else if(table->data->state==waitingMeal){
                            table->data->state = waitingWaiter;
                            table->data->course = dessert;
                            table->data->mutex.unlock();
                            table= table->nxt;
                            continue;
                        }

                        else if(table->data->state==waitingDessert){
                            table->data->state = done;                            
                            table->data->setFree();
                            table->data->mutex.unlock();
                            table = table->nxt;
                            continue;
                        }

                    }
                    else{
                        qDebug() << "Entregando en cocina...";

                        kitchenOrders->mutex.lock();
                        deliverKitchen(pedido);
                        kitchenOrders->mutex.unlock();
                        sleep(3);

                        qDebug() << "Entrega exitosa";
                    }

                    table = table->nxt;
                    continue;
                }

                else if(table->data->state == waitingEntrance){
                    Order * order = nullptr;

                    qDebug() << "Verificando pedido de mesa " << table->data->id;

                    kitchenReady->mutex.lock();
                    order = retrieveOrder(kitchenReady,table->data);
                    kitchenReady->mutex.unlock();
                    sleep(3);


                    if(order != nullptr){
                        qDebug() << "Orden lista!";
                        table->data->mutex.lock();
                        deliverClient(order,table->data);
                        table->data->state = eating;
                        table->data->mutex.unlock();
                        qDebug()<<"Entregada con exito";
                    }
                    else
                        qDebug() <<"No esta listo aun";

                    table= table->nxt;
                    continue;

                }

              else if(table->data->state == waitingMeal){
                    Order * order = nullptr;

                    qDebug() << "Verificando pedido de mesa " << table->data->id;

                    kitchenReady->mutex.lock();
                    order = retrieveOrder(kitchenReady,table->data);
                    kitchenReady->mutex.unlock();
                    sleep(3);



                    if(order != nullptr){
                        qDebug() << "Orden lista!";
                        table->data->mutex.lock();
                        deliverClient(order,table->data);
                        table->data->state = eating;
                        table->data->mutex.unlock();

                        qDebug()<<"Entregada con exito";
                    }
                    else
                        qDebug() <<"No esta listo aun";

                    table= table->nxt;
                    continue;
                }

                else if(table->data->state == waitingDessert){
                    Order * order = nullptr;

                    qDebug() << "Verificando pedido de mesa " << table->data->id;

                    kitchenReady->mutex.lock();
                    order = retrieveOrder(kitchenReady,table->data);
                    kitchenReady->mutex.unlock();
                    sleep(3);


                    if(order != nullptr){
                        qDebug() << "Orden lista!";
                        table->data->mutex.lock();
                        deliverClient(order,table->data);
                        table->data->state = eating;
                        table->data->mutex.unlock();

                    }
                    else
                        qDebug() <<"No esta listo aun";

                    table= table->nxt;
                    continue;
                }

                sleep(3);

                while(pause)
                    sleep(1);
            }
        }
    }

    Order* retrieveOrder(ListaSimple<Order>*ready,Table* table){
        Node<Order>*temp = ready->primerNodo;

        while(temp != nullptr){
            if (temp->data->id == table->id)
                return (ready->searchAndDestroy(temp->data))->data;
            else
                temp = temp->nxt;
        }
        return nullptr;
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
            int prob = (randomInit(4122001)%100);
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
            int prob = (randomInit(4122001)%100);
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
            int prob = (randomInit(4122001)%100);
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class ThreadChef : public QThread{
public:
    Chef* chef;
    bool running;
    bool pause;
    ListaSimple<Order>* orders;
    ListaSimple<Order>* cooked;

    ThreadChef(){}

    void __init__(Chef* chef,  ListaSimple<Order>* orders,  ListaSimple<Order>* cooked){
        this->running = true;
        this->pause = false;
        this->chef = chef;
        this->orders = orders;
        this->cooked = cooked;
    }

    void run(){
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
                        qDebug() << "Plato cocinado: " + dish->data->name;
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
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ThreadLastStation : public QThread{
    //Atributos
public:
    bool running;
    bool pause;
    double cash;
    int washed;
    bool mode;
    ListaSimple<Dish>* dishes;

    //Constructor
    ThreadLastStation(){}

    //Metodos
    void __init__(ListaSimple<Dish>* dishes){
        this->running = true;
        this->pause = false;
        this->cash = 0;
        this->washed = 0;
        this->dishes = dishes;
    }

    void run(){
        while (running){
            dishes->mutex.lock();
            Node<Dish>* dish = peek();
            dishes->mutex.unlock();
            if (dish != nullptr){
                sleep(dish->data->washTime);
                washed++;
                cash += dish->data->price;
                dishes->mutex.lock();
                errase();
                dishes->mutex.unlock();
            }
            while (pause)
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
        dishes->insertar(dish);
    }

    Node<Dish>* errase(){
        bool mode = this->mode;
        Node<Dish>* dish;
        if (mode)
            dish = dishes->erraseFirst();
        else
            dish = dishes->erraseLast();
        return dish;
    }

    Node<Dish>* peek(){
        bool mode = this->mode;
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

    void append(Node<Order>* order){
        if (order != nullptr){
            Node<Dish>* dish = order->data->dishes->primerNodo;
            while (dish != nullptr){
                this->dishes->insertar(dish->data);
                dish = dish->nxt;
            }
        }
    }



};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ThreadRestaurant : public QThread{
public:
    //Campos

    //Constructor
    ThreadRestaurant(){}

    void __init__(){}

    void run(){
        while(true){sleep(1);}
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ThreadClient : public QThread{
public:
    //Campos
    Table* table;
    bool running,pause;


    //Constructor
    ThreadClient(){}

    void __init__(Table* table){
        this->table = table;
    }

    void run(){
        while(running){
            if(table->state == eating){
                int eatingTime;
                if(table->course == entrance){
                     eatingTime = obtainTime(entrance);
                     qDebug() <<table->id;
                     qDebug() <<"Tardare "<< eatingTime<<" segundos";
                     qDebug() << "comiendo...";
                     sleep(eatingTime);
                     qDebug() << "terminamos de comer...";

                     table->mutex.lock();
                     table->course = meal;
                     table->state = waitingWaiter;
                     table->mutex.unlock();
                }
                else if(table->course == meal){
                    eatingTime = obtainTime(meal);
                    qDebug() <<table->id;
                    qDebug() <<"Tardare "<< eatingTime<<" segundos";
                    qDebug() << "comiendo...";
                    sleep(eatingTime);
                    qDebug() << "terminamos de comer...";

                    table->mutex.lock();
                    table->course = dessert;
                    table->state = waitingWaiter;
                    table->mutex.unlock();
                    qDebug() << table->state;
                }
                else{
                    eatingTime = obtainTime(dessert);
                    qDebug() <<table->id;
                    qDebug() <<"Tardare "<< eatingTime<<" segundos";
                    qDebug() << "comiendo...";
                    sleep(eatingTime);
                    qDebug() << "terminamos de comer...";

                    table->mutex.lock();
                    table->course = entrance;
                    table->state = done;
                    table->mutex.unlock();
                }
            }
            while(table->state != eating)
                sleep(1);
        }
    }

    void Pause(){
        this->pause = true;
    }

    void Unpause(){
        this->pause = false;
    }

    int obtainTime(DishType type){
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



};


#endif // THREADS_H
