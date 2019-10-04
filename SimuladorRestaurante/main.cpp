#include "simuladorwindow.h"
#include "formconfiguration.h"
#include "Structs.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    ListaSimpleIngredient* ingr = new ListaSimpleIngredient();


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


    QApplication a(argc, argv);
    FormConfiguration* w1 = new FormConfiguration(nullptr,menu);
    w1->show();


    return a.exec();
}
