#include "RestaurantStructs.h"


int main(int argc, char *argv[]){
   ListaSimple<Table>* tables = new ListaSimple<Table>();
   ListaSimpleIngredient* ingr = new ListaSimpleIngredient();
   ClientQueue *cola = new ClientQueue();
   Waiter * w1 = new Waiter(tables);

   ListaSimple<Dish>* entradas = new ListaSimple<Dish>();
   ListaSimple<Dish>* fuerte = new ListaSimple<Dish>();
   ListaSimple<Dish>* postre = new ListaSimple<Dish>();

   ingr->insertar("Pollo");
   ingr->insertar("Salsa");
   ingr->insertar("Cebolla");

   Dish* d1 = new Dish(4,5,6,1,entrance,300,"Pollo a la Lena",ingr);
   Dish* d2 = new Dish(7,1,24,4,meal,3000,"Lasana",ingr);
   Dish* d3 = new Dish(7,1,24,4,dessert,3000,"Sopa de mondongo",ingr);

   Dish* d4 = new Dish(4,5,6,1,entrance,300,"Pollo a la Lena",ingr);
   Dish* d5 = new Dish(7,1,24,4,meal,3000,"Lasana",ingr);
   Dish* d6 = new Dish(7,1,24,4,dessert,3000,"Sopa de mondongo",ingr);

   entradas->insertar(d1);
   fuerte->insertar(d2);
   postre->insertar(d3);
   entradas->insertar(d4);
   fuerte->insertar(d5);
   postre->insertar(d6);


   Menu* menu = new Menu(100,57,10,entradas,fuerte,postre);






   Table* t1 = new Table(1,menu);
   Table* t2 = new Table(2,menu);
   Table* t3 = new Table(3,menu);
   Table* t4 = new Table(4,menu);


   tables->insertar(t1);
   tables->insertar(t2);
   tables->insertar(t3);
   tables->insertar(t4);

    ListaSimple<Order>* ordersQueue = new ListaSimple<Order>();
    ListaSimple<Order>* readysQueue = new ListaSimple<Order>();

    Order*o1 = new Order(1,entrance);
    Order*o2 = new Order(1,meal);
    Order*o3 = new Order(1,dessert);

    readysQueue->insertar(o1);
    readysQueue->insertar(o2);
    readysQueue->insertar(o3);


   ThreadWaiter w;
   w.__init__(w1,ordersQueue,readysQueue);
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
