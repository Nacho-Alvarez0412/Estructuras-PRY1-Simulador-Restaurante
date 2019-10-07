#include "clientassignergenerator.h"


ClientAssignerGenerator::ClientAssignerGenerator()
{

}

void ClientAssignerGenerator::__init__(QTextEdit*textField,Queue<Client>*clientQueue,ListaSimple<Table>*tables){
    this->running = true;
    this->pause =  true;
    this->tables = tables;
    this->clientQueue = clientQueue;
    this->textField = textField;
}

void ClientAssignerGenerator::run() {
    while(running){

        while(pause)
            sleep(1);

        if(clientQueue->first != nullptr){
            Client*client;
            if(existeReserva()){
                if(isReserve(clientQueue->last->data->id)){
                    client = clientQueue->unqueueLast()->data;
                    Table* table = firstReserve()->data;
                    table->setClient(client);
                    textField->append("Cliente# "+QString::number(client->id));
                    textField->append("Sentado con exito");
                    clearReserve(client->id);
                    continue;

                }
            }
            if(!isFull()){
                clientQueue->mutex.lock();
                client = clientQueue->unqueue()->data;
                clientQueue->mutex.unlock();
                Table* table = firstVacancy()->data;
                table->setClient(client);
                textField->append("Cliente# "+QString::number(client->id));
                textField->append("Sentado con exito");
            }
            else
                textField->append("Esta lleno.... esperando");
        }
        else
            textField->append("No hay nadie en cola");

        sleep(1);
    }
}

void ClientAssignerGenerator::Pause(){
    this->pause = true;
}

void ClientAssignerGenerator::Unpause(){
    this->pause = false;
}

Node<Table> * ClientAssignerGenerator::firstVacancy(){
    Node<Table> * temp = tables->search(random.bounded(tables->size()-1));
    while(temp->data->state != available){
        temp = tables->search(random.bounded(tables->size()-1));
    }
    return temp;
}

bool ClientAssignerGenerator::isReserve(int id){
    for(int i=0 ; i<20 ; i++ ){
        if(reserves[i] == id)
            return true;
    }
    return false;
}

bool ClientAssignerGenerator::existeReserva(){
    Node<Table>*temp = tables->primerNodo;

    while(temp!=nullptr){
        if(temp->data->state == reservada)
            return true;
        else
            temp = temp->nxt;
    }
    return false;
}

bool ClientAssignerGenerator::isFull(){
    Node<Table>* temp = tables->primerNodo;

    while(temp!=nullptr){
        if(temp->data->state == available)
            return false;
        temp = temp->nxt;
    }
    return true;
}

bool ClientAssignerGenerator::setReserve(int id){
    Node<Table> * temp = tables->primerNodo;

    for(int i = 0 ; i<20 ; i++){
        if(reserves[i] == 0){
            reserves[i] = id;
            break;
        }
    }

    while(temp != nullptr){
        if (temp->data->state == available){
            temp->data->state = reservada;
            return true;
        }
        else
            temp = temp->nxt;
    }
    return false;
}

Node<Table> * ClientAssignerGenerator::firstReserve(){
    Node<Table> * temp = tables->primerNodo;
    while(temp != nullptr){
        if (temp->data->state == reservada)
            return temp;
        else
            temp = temp->nxt;
    }
    return nullptr;
}

void ClientAssignerGenerator::clearReserve(int id){
    for(int i=0 ; i<20 ; i++ ){
        if(reserves[i] == id){
            reserves[i] = 0;
        }
    }
}



