#ifndef RESTAURANTSTRUCT_H
#define RESTAURANTSTRUCT_H

#include "Threads.h"

// -----------------------------------------------   STRUCTS DE LAS PARTES DEL RESTAURANTE   ----------------------------------------------------------

// Structs del restaurante

struct Entrance{
    // Campos
    ClientQueue * clientQueue;
    ListaSimple<Table> * tables;

    Entrance(ClientQueue*clientQueue,ListaSimple<Table>*tables){
        this->clientQueue = clientQueue;
        this->tables = tables;
    }

    void EntranceStart(){
        ThreadClientGenerator clientGenerator;
        ThreadClientAssigner clientAssigner;
        clientGenerator.setIntervalo(1,6);
        clientGenerator.__init__(clientQueue);
        clientAssigner.__init__(clientQueue,tables);
        clientGenerator.start();
        clientAssigner.start();
    }


};


#endif // RESTAURANTSTRUCT_H
