#include "RestaurantStructs.h"


int main(int argc, char *argv[]){
   ListaSimple<Table>* tables = new ListaSimple<Table>();
   Table* t1 = new Table(1);
   Table* t2 = new Table(2);
   Table* t3 = new Table(3);
   Table* t4 = new Table(4);

   tables->insertar(t1);
   tables->insertar(t2);
   tables->insertar(t3);
   tables->insertar(t4);

   ClientQueue *cola = new ClientQueue();

/*
   ThreadClientGenerator e;
   e.__init__(cola);
   e.setIntervalo(1, 6);
   e.start();*/


   qDebug() << "Hola";

   ThreadClientAssigner k;
   k.__init__(cola, tables);
   k.run();

   return 0;
}
