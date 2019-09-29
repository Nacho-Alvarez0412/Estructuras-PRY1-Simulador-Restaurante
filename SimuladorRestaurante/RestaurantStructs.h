#ifndef RESTAURANTSTRUCT_H
#define RESTAURANTSTRUCT_H

#include "Threads.h"

// -----------------------------------------------   STRUCTS DE LAS PARTES DEL RESTAURANTE   ----------------------------------------------------------

struct Entrance{
    ListaSimple<Table>*tables;
    Queue<Client>*clientQueue;

    //Constructor
    Entrance(int cantMesas,Menu*menu){
        this->clientQueue = new Queue<Client>();
        this->tables = new ListaSimple<Table>();

        int cont = 1;

        while(cont <= cantMesas){
            Table*t = new Table(cont,menu);
            tables->insertar(t);
            cont++;
        }
    }
};

struct DinningRoom{
    ListaSimple<Table>*tables;
    ListaSimple<Waiter>*meseros;

    //Constructor
    DinningRoom(ListaSimple<Table>*tables,int cantMesas){

    }



};
// Structs del restaurante



#endif // RESTAURANTSTRUCT_H
