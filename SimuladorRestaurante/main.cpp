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

   qDebug() << "Hola";

   ThreadClientGenerator k;
   k.__init__(cola);
   k.setIntervalo(1,5);
   k.start();

   ThreadClientAssigner k1;
   k1.__init__(cola,tables);
   k1.start();


   ThreadRestaurant r;
   r.__init__();
   r.run();

   return 0;
}
