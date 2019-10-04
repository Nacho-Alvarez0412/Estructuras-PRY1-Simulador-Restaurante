#include "waiterthread.h"

WaiterThread::WaiterThread()
{

}

void WaiterThread::__init__(Waiter*waiter, ListaSimple<Order> *kitchenOrders, ListaSimple<Order> * kitchenReady,ListaSimple<Dish>*dirtyDish){
    this->running = true;
    this->pause = false;
    this->waiter = waiter;
    this->kitchenOrders = kitchenOrders;
    this->kitchenReady = kitchenReady;
    this->dirtyDishes = dirtyDish;
    this->bitacora = "";

}

void WaiterThread::run(){
    while(running){
        Node<Table>*table = waiter->tables->primerNodo;

        while(table != nullptr){

            if(table->data->state == done){
                bitacora += "La mesa # "+QString::number( table->data->id)+" Terminaron de comer\n";
                Bill* bill = new Bill(table->data->id,table->data->client->id,table->data->getDishes());
                bill->checkout();
                table->data->bills->insertar(bill);
                bill->checkoutPrint();
                ListaSimple<Dish>* platillos = table->data->dishes;
                dirtyDishes->mutex.lock();
                dirtyDishes->append(dirtyDishes,platillos);
                dirtyDishes->mutex.unlock();
                table->data->setFree();
            }

            if(table->data->state == available || table->data->state == eating || table->data->state == reservada){
                bitacora += "La mesa # "+ QString::number( table->data->id)+ " no necesita atencion\n";
                table = table->nxt;
                sleep(3);
                continue;
            }

            if(table->data->state == waitingWaiter){
                bitacora += "Atendiendo mesa #" +QString::number(table->data->id)+"\n";
                Order* pedido = nullptr;
                ListaSimple<Dish> *order;

                if(table->data->course == entrance){
                    pedido =  new Order(table->data->id,entrance);
                    order = askEntrance(table);
                    pedido->setDish(order);
                    table->data->state=waitingEntrance;

                     bitacora += "Pidio entrada\n";
                    sleep(3);
                }
                else if(table->data->course == meal){
                    pedido =  new Order(table->data->id,meal);
                    order = askMeal(table);
                    pedido->setDish(order);
                    table->data->state=waitingMeal;

                    bitacora += "Pidio plato fuerte\n";
                    sleep(3);
                }
                else if(table->data->course == dessert){
                    pedido =  new Order(table->data->id,dessert);
                    order = askDessert(table);
                    pedido->setDish(order);
                    table->data->state=waitingDessert;

                     bitacora += "Pidio postre\n";
                    sleep(3);
                }
                bitacora += "Orden tomada con exito\n";
                bitacora += "Tamano de la orden: "+QString::number(order->size())+"\n";

                if(order->size() == 0){
                    bitacora += "No hay platos\n";

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

                    else{
                        table->data->state = done;
                        table->data->mutex.unlock();
                        table = table->nxt;
                        continue;
                    }

                }
                else{
                    bitacora += "Entregando en cocina...\n";

                    kitchenOrders->mutex.lock();
                    deliverKitchen(pedido);
                    kitchenOrders->mutex.unlock();
                    sleep(3);

                    bitacora += "Entrega exitosa\n";
                }

                table = table->nxt;
                continue;
            }

            else if(table->data->state == waitingEntrance){
                Order * order = nullptr;

                bitacora += "Verificando pedido de mesa " +QString::number(table->data->id)+"\n";

                kitchenReady->mutex.lock();
                order = retrieveOrder(kitchenReady,table->data);
                kitchenReady->mutex.unlock();
                sleep(3);


                if(order != nullptr){
                    bitacora += "Orden lista!\n";
                    table->data->mutex.lock();
                    deliverClient(order,table->data);
                    table->data->state = eating;
                    table->data->mutex.unlock();
                    bitacora += "Entregada con exito\n";
                }
                else
                    bitacora += "No esta listo aun\n";

                table= table->nxt;
                continue;

            }

          else if(table->data->state == waitingMeal){
                Order * order = nullptr;

                bitacora += "Verificando pedido de mesa " +QString::number(table->data->id)+"\n";

                kitchenReady->mutex.lock();
                order = retrieveOrder(kitchenReady,table->data);
                kitchenReady->mutex.unlock();
                sleep(3);



                if(order != nullptr){
                    bitacora += "Orden lista!\n";
                    table->data->mutex.lock();
                    deliverClient(order,table->data);
                    table->data->state = eating;
                    table->data->mutex.unlock();

                    bitacora += "Entregada con exito\n";
                }
                else
                    bitacora += "No esta listo aun\n";

                table= table->nxt;
                continue;
            }

            else if(table->data->state == waitingDessert){
                Order * order = nullptr;

                bitacora += "Verificando pedido de mesa " +QString::number(table->data->id)+"\n";

                kitchenReady->mutex.lock();
                order = retrieveOrder(kitchenReady,table->data);
                kitchenReady->mutex.unlock();
                sleep(3);


                if(order != nullptr){
                    bitacora += "Orden lista!\n";
                    table->data->mutex.lock();
                    deliverClient(order,table->data);
                    table->data->state = eating;
                    table->data->mutex.unlock();

                }
                else
                    bitacora += "No esta listo aun\n";

                table= table->nxt;
                continue;
            }

            sleep(3);

            while(pause)
                sleep(1);
        }
    }
}

Order* WaiterThread::retrieveOrder(ListaSimple<Order>*ready,Table* table){
    Node<Order>*temp = ready->primerNodo;

    while(temp != nullptr){
        if (temp->data->id == table->id)
            return (ready->searchAndDestroy(temp->data))->data;
        else
            temp = temp->nxt;
    }
    return nullptr;
}

void WaiterThread::Pause(){
    this->pause = true;
}


void WaiterThread::Unpause(){
    this->pause = false;
}


void WaiterThread::deliverKitchen(Order * order){
    kitchenOrders->insertar(order);
}

void WaiterThread::deliverClient(Order*order,Table*table){
    Node<Dish>*plate = order->dishes->primerNodo;

    while(plate != nullptr){
        table->addDish(plate->data);
        plate = plate->nxt;
    }
    return;
}


ListaSimple<Dish> * WaiterThread::askEntrance(Node<Table>*table){
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

 ListaSimple<Dish> * WaiterThread::askMeal(Node<Table>*table){
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

 ListaSimple<Dish> * WaiterThread::askDessert(Node<Table>*table){
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

