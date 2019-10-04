#ifndef STRUCTS_H
#define STRUCTS_H

#include "StructHeaders.h"

template <typename T>
struct Node{
    // Campos
    Node<T> *nxt;
    T* data;

    //Constructor
    Node<T>(T* data){
        this->nxt= nullptr;
        this->data = data;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>

struct Queue{
    //Campos
    QMutex mutex;
    Node<T> *first, *last;

    Queue<T>(){
        this->first = this->last = nullptr;
    }

    bool isEmpty() {
        return this->first == nullptr; }

    void queue(T* data){
        if (this->isEmpty())
            this->last = this->first = new Node<T>(data);
        else{
            last->nxt = new Node<T>(data);
            last = last->nxt;
        }
    }

    Node<T>* unqueue(){
        Node<T> * borrado = first;

        if(!isEmpty()){
            first = first->nxt;
            borrado->nxt = nullptr;
        }
        else
            return nullptr;
        return borrado;
    }

    int size(){
        Node<T>* temp = first;
        int cont = 0;
        while(temp != nullptr){
            cont++;
            temp = temp->nxt;
        }
        return cont;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<typename T>

struct ListaSimple{
    //Campos
    QMutex mutex;
    Node<T>* primerNodo;

    ListaSimple<T>(){
        this->primerNodo = nullptr;
    }

    void insertar(T*data){
        Node<T>* temp = primerNodo;
         if (temp == nullptr){
             primerNodo = new Node<T>(data);
             return;
         }
         while(temp->nxt != nullptr)
             temp = temp->nxt;
         temp->nxt = new Node<T>(data);
    }

    Node<T>* searchAndDestroy(T* value){
        Node<T>* ptr = primerNodo;
        Node<T>  *deleted;
        if (ptr != nullptr){
            if (ptr->data == value){
                deleted = ptr;
                primerNodo = deleted->nxt;
                deleted->nxt = nullptr;
                return deleted;
            }
            else {
                while (ptr != nullptr){
                    if (ptr->nxt->data == value) {
                        deleted = ptr->nxt;
                        ptr->nxt = deleted->nxt;
                        deleted->nxt = nullptr;
                        break;
                    } else
                        ptr = ptr->nxt;
                }
                return deleted;
            }
        }
        return nullptr;
    }



    Node<T> * search(int index){
        Node<T>* ptr = primerNodo;
        int cont = 0;
        while (cont != index && ptr != nullptr){
            cont++;
            ptr = ptr->nxt;
        }
        return ptr;
    }

    int size(){
        Node<T>* temp = primerNodo;
        int cont=0;
        while(temp != nullptr){
            cont++;
            temp = temp->nxt;
        }
        return cont;
    }

    Node<T>* erraseFirst(){
        Node<T>* ptr = primerNodo;
        if (ptr != nullptr){
            primerNodo = ptr->nxt;
            ptr->nxt = nullptr;
        }
        return ptr;
    }

    Node<T>* erraseLast(){
        Node<T>* ptr = primerNodo;
        if (ptr != nullptr){
            if (ptr->nxt == nullptr)
                primerNodo = nullptr;
            else {
                Node<T>* deleted;
                while (ptr->nxt->nxt != nullptr)
                    ptr = ptr->nxt;
                deleted = ptr->nxt;
                ptr->nxt = nullptr;
                ptr = deleted;
                //delete deleted;
            }
        }
        return ptr;
    }

    void append(ListaSimple<Dish>* listO,ListaSimple<Dish>*nueva){
        if (nueva != nullptr){
            Node<Dish>* dish = nueva->primerNodo;
            while (dish != nullptr){
                listO->insertar(dish->data);
                dish = dish->nxt;
            }
        }
    }

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>

struct Stack{
    QMutex mutex;
    Node<T> * top;

    Stack<T>()= default;

    void push(T*data){
        Node<T>* ptr = new Node<T>(data);
        ptr->nxt = top;
        top = ptr;
    }

    Node<T>* pop(){
        Node<T>* deleted = top;
        top = deleted->nxt;
        deleted->nxt = nullptr;
    }

    Node<T>* peek(){
        return top;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct NodeIngredient{
    //Campos
    QString data;
    NodeIngredient* nxt;

    //Constructor
    NodeIngredient(QString name){
        this->data = name;
        this->nxt = nullptr;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct ListaSimpleIngredient{
    //Campos
    NodeIngredient * primerNodo;

    //Constructor
    ListaSimpleIngredient(){
        primerNodo = nullptr;
    }

    //Metodos

    void insertar(QString data){
        NodeIngredient* temp = primerNodo;
         if (temp == nullptr){
             primerNodo = new NodeIngredient(data);
             return;
         }
         while(temp->nxt != nullptr)
             temp = temp->nxt;
         temp->nxt = new NodeIngredient(data);
    }


    NodeIngredient* borrar(QString value){
        if (primerNodo == nullptr)
            return nullptr;
        else{
            NodeIngredient* temp = primerNodo;
            while(temp->nxt != nullptr){
                if (temp->nxt->data == value){
                    NodeIngredient * borrado = temp->nxt;
                    temp->nxt = borrado->nxt;
                    borrado->nxt = nullptr;
                    return borrado;
                }
                else
                    temp = temp->nxt;

            }
            return nullptr;
        }
    }

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct Client{
    int id;
    int quant;

    // Constructor

    Client(int id, int quant){
        this->id = id;
        this->quant = quant;  // random between 1-6
    }

    QString toString(){
        QString info = "";
        info +="Cliente# "+QString::number(this->id)+"\n";
        info +="Tamaño del cliente: "+QString::number(this->quant)+"\n";
        return info;
    }
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Menu{
    //Campos
    int Entrada;
    int PlatoFuerte;
    int Postre;
    ListaSimple<Dish>* MenuEntrada;
    ListaSimple<Dish>* MenuPlatoFuerte;
    ListaSimple<Dish>* MenuPostre;

    Menu(int entrada,int platoFuerte,int Postre,ListaSimple<Dish>*menue,ListaSimple<Dish>*menufuerte,ListaSimple<Dish>*menupostre){
        this->Entrada = entrada;
        this->PlatoFuerte = platoFuerte;
        this->Postre = Postre;
        this->MenuEntrada = menue;
        this->MenuPlatoFuerte = menufuerte;
        this->MenuPostre = menupostre;
    }

    ListaSimple<Dish>* getMenuEntrada(){
        return MenuEntrada;
    }

    ListaSimple<Dish>* getMenuPlatoFuerte(){
        return MenuPlatoFuerte;
    }

    ListaSimple<Dish>* getMenuPostre(){
        return MenuPostre;
    }

    void setProbEntrada(int value){
        this->Entrada = value;
    }

    void setProbPlatoFuerte(int value){
        this->PlatoFuerte = value;
    }

    void setProbPostre(int value){
        this->Postre = value;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Dish{
    // Campos
    QString name;
    ListaSimpleIngredient* ingredients;
    int cookTime;
    int eatTime;
    int washTime;
    int id;
    DishType type;
    int price;

    // Constructor

    Dish(int cookTime,int eatTime,int washTime,int id,DishType type,int price,QString name, ListaSimpleIngredient*ingredients){
        this->id = id;
        this->name =name;
        this->type = type;
        this->price=price;
        this->eatTime = eatTime;
        this->cookTime = cookTime;
        this->washTime = washTime;
        this->ingredients = ingredients;
    }

};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct Table{
    // Campos
    QMutex mutex;
    Client * client;
    int id;
    DishType course;
    TableState state; // Convertir en enum == empty,waiting,waitingOrder,eating,reserved
    ListaSimple<Dish>* dishes;
    Menu* menu;
    ListaSimple<Bill>*bills;
    QRect  rectangle;

    // Constructor

    Table(int id,Menu*menu){
        this->menu = menu;
        this->state = inactive;
        this->course = entrance;
        this->client = nullptr;
        this->id = id;
        this->dishes = new ListaSimple<Dish>();
        this->bills = new ListaSimple<Bill>();
    }

    // Metodos

    void setClient(Client*client){
        this->state = waitingWaiter;
        this->client = client;
    }

    void setReserve(){
        this->state = reservada;
    }


    void addDish(Dish*dish){
        this->dishes->insertar(dish);
    }

    ListaSimple<Dish>* getDishes(){
        return dishes;
    }

    void setFree(){
        this->state = available;
        this->course = entrance;
        this->client = nullptr;
        this->dishes = new ListaSimple<Dish>(); // Puede llenar la memoria de basura
    }

    QString printDishCourse(DishType type){
        Node<Dish> * temp = dishes->primerNodo;
        QString info = "";
        while(temp!=nullptr){
            if (temp->data->type == type){
                info += temp->data->name+"\n";
                temp = temp->nxt;
            }
            else
                temp = temp->nxt;
        }
        return info;
    }

    QString toString(){
        QString info = "";
        QString estado;
        QString platillo;

        switch(state){
        case available:
             estado = "disponible";
             break;
        case reservada:
              estado = "reservada";
              break;
        case eating:
             estado = "comiendo";
             break;
        case waitingWaiter:
             estado = "esperando al mesero";
             break;
        case waitingEntrance:
             estado = "esperando entrada";
             break;
        case waitingMeal:
             estado = "esperando plato fuerte";
             break;
        case waitingDessert:
             estado = "esperando postre";
             break;
        default:
             estado = "pagando";
        }

        switch (course) {
        case entrance:
             platillo = "Entrada";
             break;
        case meal:
             platillo = "Plato Fuerte";
             break;
        default:
             platillo = "Postre";
        }

        if(state == inactive)
            return "La mesa no se encuentra activa";
        else if(client!=nullptr){
            info += "Status: "+estado+"\n";
            info +="Tipo de platillo actual: "+platillo+"\n";
            info +="Cliente:\n";
            info +=client->toString();
            info +="Platillos:\n";
            info +="Entradas:\n";
            info +=printDishCourse(entrance)+"\n";
            info +="Platos Fuerte:\n";
            info +=printDishCourse(meal)+"\n";
            info +="Postres:\n";
            info +=printDishCourse(dessert)+"\n";
            return info;
        }
        else
            info += "Status: "+estado+"\n";
            info +="Cliente: no hay clientes sentados";
            return info;

    }

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Order{

    //Campos
    int id;
    DishType type;
    ListaSimple<Dish>* dishes;

    // Constructor
    Order(int id,DishType type){
        this->id = id;
        this->type = type;
        this->dishes = new ListaSimple<Dish>;
    }

    void setDish(ListaSimple<Dish>*dishes){
        this->dishes = dishes;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct Waiter{
    // Campos
    int id;
    ListaSimple<Table>* tables;

    // Constructor
    Waiter(int id,ListaSimple<Table>* tables){
        this->id = id;
        this->tables = tables;
    }

    QString toStringTables(){
        QString mesas = "";
        Node<Table>* temp = tables->primerNodo;

        while(temp != nullptr){
            mesas += QString::number(temp->data->id)+" ";
        }
        return mesas;
    }

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct NodeChashier{
    //Campos
    int data;
    NodeChashier* nxt;

    //Constructor
    NodeChashier(int data){
        this->data = data;
        this->nxt = nullptr;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct Cashier{
    //Campos
    bool state; // true = queue; false = stack
    int earnings;
    NodeChashier* first;
    NodeChashier* last;

    //Constructor
    Cashier(){
        this->state = true;
        this->earnings = 0;
        this->first = this->last = nullptr;
    }

    //Metodos
    void add(int data){
        NodeChashier* add = new NodeChashier(data);
        if (first == nullptr)
            first = last = add;
        else {
            last->nxt = add;
            last = add;
        }
    }

    NodeChashier* prevLast(){
        NodeChashier* ptr = first;
        if (first == nullptr || first == last)
            return nullptr;
        while (ptr->nxt != last){
            ptr = ptr->nxt;
        }
        return ptr;
    }

    int remove(){
        NodeChashier* deleted;
        if (this->state){
            deleted = first;
            first = first->nxt;
            deleted->nxt = nullptr;
        } else {
            if (last != nullptr){
                deleted = last;
                if (first != last)
                    prevLast()->nxt = nullptr;
                else
                    first = last = nullptr;
            } else
                return 0;
        }
        this->earnings += deleted->data;
        return deleted->data;
    }

    void changeState(){
        this->state = !this->state;
    }

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Chef{
    //Campos
    Dish* dish;
    DishType type;

    //Constructor
    Chef(DishType type){
        this->dish = nullptr;
        this->type = type;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Bill{
    //Campos
    int total;
    int table;
    int client;
    ListaSimple<Dish>* dishes;

    //Constructor
    Bill(int table,int client,ListaSimple<Dish>*dishes){
        this->total = 0;
        this->table = table;
        this->client = client;
        this->dishes = dishes;
    }

    void checkout(){
        Node<Dish>* temp = dishes->primerNodo;
        while(temp!=nullptr){
            this->total += temp->data->price;
            temp = temp->nxt;
        }
        return;
    }

    void printDishes(){
        Node<Dish>* temp = dishes->primerNodo;

        while(temp != nullptr){
            qDebug()<<temp->data->id<<" "<<temp->data->name<<" "<<temp->data->price;
            qDebug()<<" ";
            temp = temp->nxt;
        }
        return;
    }

    void checkoutPrint(){
        qDebug() << "La mesa #"<<table;
        qDebug() << " ";
        qDebug() << "Cliente #"<<client;
        qDebug() << " ";
        qDebug() << "Total a pagar: "<<total;
        qDebug() <<" ";
        printDishes();
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Lock{
    //Campos
    QMutex mutex;

    //Constructor
    Lock(){}
};

#endif // STRUCTS_H
