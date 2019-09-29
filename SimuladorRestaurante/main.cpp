#include "RestaurantStructs.h"


int main(int argc, char *argv[]){

   ListaSimple<Table>* tables = new ListaSimple<Table>();
   ListaSimpleIngredient* ingr = new ListaSimpleIngredient();
   Queue<Client>* cola = new Queue<Client>();
   Waiter * w1 = new Waiter(tables);

   ListaSimple<Dish>* platosSucios = new ListaSimple<Dish>();

   ListaSimple<Dish>* entradas = new ListaSimple<Dish>();
   ListaSimple<Dish>* fuerte = new ListaSimple<Dish>();
   ListaSimple<Dish>* postre = new ListaSimple<Dish>();

   ingr->insertar("Pollo");
   ingr->insertar("Salsa");
   ingr->insertar("Cebolla");

   Dish* d1 = new Dish(4,5,6,1,entrance,300,"Guacamole",ingr);
   Dish* d2 = new Dish(7,5,24,4,meal,3000,"Lasana",ingr);
   Dish* d3 = new Dish(7,1,24,4,dessert,3000,"Faln de coco",ingr);

   Dish* d4 = new Dish(4,5,6,1,entrance,300,"Cheese poppers",ingr);
   Dish* d5 = new Dish(7,5,24,4,meal,3000,"Fish and chips",ingr);
   Dish* d6 = new Dish(7,1,24,4,dessert,3000,"Pastel de zanahoria",ingr);

   Dish* d7 = new Dish(4,5,6,1,entrance,300,"Fondue",ingr);
   Dish* d8 = new Dish(7,5,24,4,meal,3000,"Pez frito",ingr);
   Dish* d9 = new Dish(7,1,24,4,dessert,3000,"Crema catalana",ingr);

   entradas->insertar(d1);
   fuerte->insertar(d2);
   postre->insertar(d3);
   entradas->insertar(d4);
   fuerte->insertar(d5);
   postre->insertar(d6);
   entradas->insertar(d7);
   fuerte->insertar(d8);
   postre->insertar(d9);



   Menu* menu = new Menu(40,80,20,entradas,fuerte,postre);


   Table* t1 = new Table(1,menu);
   Table* t2 = new Table(2,menu);
   Table* t3 = new Table(3,menu);
   Table* t4 = new Table(4,menu);


   tables->insertar(t1);
   tables->insertar(t2);
   tables->insertar(t3);
   tables->insertar(t4);


    ThreadChef t, m,p,a,b;
    ListaSimple<Order>* cooked = new  ListaSimple<Order>();
     ListaSimple<Order>* orders = new  ListaSimple<Order>();


   ThreadWaiter w;
   w.__init__(w1,orders,cooked,platosSucios);
   w.start();


   ThreadClientGenerator k;
   k.__init__(cola);
   k.setIntervalo(1,5);
   k.start();

   t.__init__(new Chef(entrance), orders, cooked);
   t.start();

   m.__init__(new Chef(meal), orders, cooked);
   m.start();

   p.__init__(new Chef(dessert), orders, cooked);
   p.start();

   a.__init__(new Chef(meal), orders, cooked);
   a.start();

   b.__init__(new Chef(meal), orders, cooked);
   b.start();


   ThreadClientAssigner k1;
   k1.__init__(cola,tables);
   k1.start();

   ThreadClient c1;
   c1.__init__(t1);
   c1.start();

   ThreadClient c21;
   c21.__init__(t2);
   c21.start();

   ThreadClient c2;
   c2.__init__(t2);
   c2.start();

   ThreadClient c3;
   c3.__init__(t3);
   c3.start();

   ThreadClient c4;
   c4.__init__(t4);
   c4.start();

   ThreadLastStation l4;
   l4.__init__(platosSucios);
   l4.run();


   ThreadRestaurant r;
   r.__init__();
   r.run();

   return 0;
}
