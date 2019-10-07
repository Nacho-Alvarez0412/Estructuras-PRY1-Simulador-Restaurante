#include "formconfiguration.h"
#include "Structs.h"
#include "dialogreserves.h"


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

    Dish* d1 = new Dish(4,9,5,1,entrance,3500,"Guacamole",ingr);
    Dish* d2 = new Dish(7,10,4,4,meal,3000,"Lasana",ingr);
    Dish* d3 = new Dish(7,12,2,4,dessert,3000,"Faln de coco",ingr);

    Dish* d4 = new Dish(4,5,6,1,entrance,300,"Cheese poppers",ingr);
    Dish* d5 = new Dish(7,7,11,4,meal,3000,"Fish and chips",ingr);
    Dish* d6 = new Dish(7,9,8,4,dessert,3000,"Pastel de zanahoria",ingr);

    Dish* d7 = new Dish(4,5,2,1,entrance,300,"Fondue",ingr);
    Dish* d8 = new Dish(7,5,4,4,meal,3000,"Pez frito",ingr);
    Dish* d9 = new Dish(7,13,3,4,dessert,3000,"Crema catalana",ingr);


    Dish*d10 = new Dish(5,8,10,25,entrance,4000,"Potato Skins",ingr);
    Dish*d11 = new Dish(10,15,10,24,meal,6000,"Pasta en Salsa Blanca",ingr);
    Dish*d12 = new Dish(7,6,4,22,dessert,3000,"Pie de Limon",ingr);

    entradas->insertar(d1);
    fuerte->insertar(d2);
    postre->insertar(d3);
    entradas->insertar(d4);
    fuerte->insertar(d5);
    postre->insertar(d6);
    entradas->insertar(d7);
    fuerte->insertar(d8);
    postre->insertar(d9);
    entradas->insertar(d10);
    fuerte->insertar(d11);
    postre->insertar(d12);



    Menu* menu = new Menu(40,80,20,entradas,fuerte,postre);


    QApplication a(argc, argv);
    FormConfiguration* w1 = new FormConfiguration(nullptr,menu);
    w1->show();

    return a.exec();
}
