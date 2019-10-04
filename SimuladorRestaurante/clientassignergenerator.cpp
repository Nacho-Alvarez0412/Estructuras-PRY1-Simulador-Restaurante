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
            if(firstVacancy() != nullptr){
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

        sleep(5);
    }
}

void ClientAssignerGenerator::Pause(){
    this->pause = true;
}

void ClientAssignerGenerator::Unpause(){
    this->pause = false;
}

Node<Table> * ClientAssignerGenerator::firstVacancy(){
    Node<Table> * temp = tables->primerNodo;
    while(temp != nullptr){
        if (temp->data->state == 0)
            return temp;
        else
            temp = temp->nxt;
    }
    return nullptr;
}
