#include "clientgeneratorthread.h"

ClientGeneratorThread::ClientGeneratorThread()
{

}

   void ClientGeneratorThread:: setIntervalo(int low, int high){
       this->firstInterval = low;
       this->lastInterval = high;
   }


    void ClientGeneratorThread::__init__(QTextEdit*textField, QLabel*label,Queue<Client>* clientQueue,int first,int last){
       this->textField = textField;
       this->label = label;
       running = true;
       pause = true;
       this->firstInterval = first;
       this->lastInterval = last;
       this->clientQueue = clientQueue;

   }

   void ClientGeneratorThread::run(){
       int size;
       int sleepTime;
       int cont = 1;
       while (running){

           while (pause)
               sleep(1);

           size = (randomInit(4122001)%6 +1);
           sleepTime = ((randomInit(4122001)%lastInterval) + firstInterval);
           Client * client = new Client(cont,size);
           clientQueue->mutex.lock();
           clientQueue->queue(client);
           clientQueue->mutex.unlock();
           textField->append("Cliente creado con exito! ID: "+QString::number(cont)+" cantidad: "+QString::number(size));
           label->setText(QString::number(clientQueue->size()));

           cont++;

           sleep(sleepTime);
       }
   }

   void  ClientGeneratorThread::Pause(){
       this->pause = true;
   }

   void  ClientGeneratorThread::Unpause(){
       this->pause = false;
   }

