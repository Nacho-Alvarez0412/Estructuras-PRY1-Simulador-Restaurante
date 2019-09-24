#include "RestaurantStructs.h"


int main(int argc, char *argv[]){
    ListaSimple<Table>* tables = nullptr;
 /*   tables->insertar(new Table(1));
    tables->insertar(new Table(2));
    tables->insertar(new Table(3));
    tables->insertar(new Table(4));
    tables->insertar(new Table(5));
*/

   ClientQueue *cola = new ClientQueue();


   ThreadClientGenerator e;
   e.__init__(cola);
   e.setIntervalo(1, 6);
   e.start();

   ThreadClientGenerator e2;
   e2.__init__(cola);
   e2.setIntervalo(1, 6);
   e2.run();

   qDebug() << "Hola";

 /*  ThreadClientAssigner k;
   k.__init__(cola, tables);
   k.run();

   qDebug() << "Hola 2";*/
   return 0;
}
