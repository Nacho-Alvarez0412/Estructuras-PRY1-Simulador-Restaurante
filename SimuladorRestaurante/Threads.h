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


   void setIntervalo(int low, int high){
       this->firstInterval = low;
       this->lastInterval = high;
   }


   //Constructor

   ThreadClientGenerator(){}

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
           cont++;
           qDebug() << client->id;
           qDebug() << client->quant;
           sleep(sleepTime);
           while (pause)
               sleep(1);
       }
   }

   void StartPause(){
       this->pause = true;
   }

   void StopPause(){
       this->pause = false;
   }



};

#endif // THREADS_H
