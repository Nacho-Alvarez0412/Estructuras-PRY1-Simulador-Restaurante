#include "RestaurantStructs.h"


int main(int argc, char *argv[]){
   ListaSimple<Table>* tables = new ListaSimple<Table>();
   ListaSimple<Dish>* platillos = new ListaSimple<Dish>();
   ListaSimpleIngredient* ingr = new ListaSimpleIngredient();
   ClientQueue *cola = new ClientQueue();
   Waiter * w1 = new Waiter(tables);

   ingr->insertar("Pollo");
   ingr->insertar("Salsa");
   ingr->insertar("Cebolla");

   Menu* menu = new Menu(4,8,2,platillos);
   Table* t1 = new Table(1,menu);
   Table* t2 = new Table(2,menu);
   Table* t3 = new Table(3,menu);
   Table* t4 = new Table(4,menu);


   Dish* d1 = new Dish(4,5,6,1,1,300,"Pollo a la Lena",ingr);

   tables->insertar(t1);
   tables->insertar(t2);
   tables->insertar(t3);
   tables->insertar(t4);



   ThreadWaiter w;
   w.__init__(w1);
   w.start();

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
