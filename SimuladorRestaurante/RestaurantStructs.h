//hi
#ifndef RESTAURANTSTRUCT_H
#define RESTAURANTSTRUCT_H

#include "Threads.h"

// -----------------------------------------------   STRUCTS DE LAS PARTES DEL RESTAURANTE   ----------------------------------------------------------

// Structs del restaurante

struct Entrance{
    ClientQueue * clientQueue;
    ThreadClientGenerator clientGenerator;
    ThreadClientAssigner clientAssigner;
    ListaSimple<Table>* tables;

    // Constructor
    Entrance(){
        this->clientQueue = new ClientQueue();
        clientGenerator.__init__(clientQueue);
        clientGenerator.setIntervalo(1,10); // Deben ser preguntados en una interfaz grafica
        clientAssigner.__init__(clientQueue,tables);

    }

    void EntranceStart(){
        clientAssigner.run();
        clientGenerator.run();


    }
};



#endif // RESTAURANTSTRUCT_H
