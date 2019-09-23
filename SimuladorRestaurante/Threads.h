//hi
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



/*class ThreadCocina : QThread{
    //Atributos
public:
    bool start;
    bool pause;


};*/

#endif // THREADS_H
