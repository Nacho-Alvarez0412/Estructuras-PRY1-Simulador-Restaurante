#ifndef STRUCTS_H
#define STRUCTS_H
#include "Header.h"

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
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<typename T>

struct ListaSimple{
    //Campos
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

    Node<T>* searchByData(T* data){
        if (primerNodo == nullptr)
            return nullptr;
        else {
            Node<T>* ptr = primerNodo;
            while(ptr != nullptr){
                if (ptr->data == data)
                    break;
                ptr = ptr->nxt;
            }
            return ptr;
        }
    }

    Node<T>* searchAndDestroy(T* value){
        Node<T>* ptr = primerNodo;
        if (searchByData(value) != nullptr){
            if (ptr->data == value){
                primerNodo = ptr->nxt;
                ptr->nxt = nullptr;
            } else {
                while (ptr->nxt->data != value)
                    ptr = ptr->nxt;
                Node<T>* deleted = ptr->nxt;
                ptr->nxt = deleted->nxt;
                deleted->nxt = nullptr;
                ptr = deleted;
            }
            return ptr;
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

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>

struct Stack{
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



struct ClientNode{

    // Campos
    Client * data;
    ClientNode * nxt;

    // Constructor
    ClientNode(Client* value){
        this->data = value;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct ClientQueue{

    // Campos
    ClientNode* top;
    ClientNode* base;

    //Constructor
    ClientQueue(){
        top = base = nullptr;
    }

    void queued(Client*client){
        ClientNode* node = new ClientNode(client);
        if (top == base){
            if (top == nullptr){
                top = base = node;  // Lista vacia
            }
            top->nxt = base = node;  // Lista con 1 nodo
        } else {
            base->nxt = node;  // Lista con 2 o mas nodos
            base = node;
        }
    }

    ClientNode* prevBase(){
        ClientNode* ptr = top;
        if (top != nullptr)
            if (top != base){
                while(ptr->nxt != base){
                    ptr = ptr->nxt;
                }
                return ptr;
            }
        return nullptr;
    }

    ClientNode* unqueue(bool side){  //side=true saca ultimo; side=false saca primero
        ClientNode* deleted;
        if (side){
            deleted = base;
            base = prevBase();
            base->nxt = nullptr;
        } else {
            deleted = top;
            top = top->nxt;
            deleted->nxt = nullptr;
        }
        return deleted;
    }

    bool checkPriority(int id){
        return base->data->id == id;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct Table{
    // Campos

    Client * client;
    int id;
    DishType course;
    TableState state; // Convertir en enum == empty,waiting,waitingOrder,eating,reserved
    ListaSimple<Dish>* dishes;
    Menu* menu;

    // Constructor

    Table(int id,Menu*menu){
        this->menu = menu;
        this->state = available;
        this->course = entrance;
        this->client = nullptr;
        this->id = id;
        this->dishes = new ListaSimple<Dish>();
    }

    // Metodos

    void setClient(Client*client){
        this->state = waitingWaiter;
        this->client = client;
    }

    void setReserve(){
        this->state = reserved;
    }


    void addDish(Dish*dish){
        this->dishes->insertar(dish);
    }

    ListaSimple<Dish>* getDishes(){
        return dishes;
    }

    void setFree(){
        this->state = available;
        this->client = nullptr;
        this->dishes = nullptr; // Puede llenar la memoria de basura
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

    ListaSimple<Table>* tables;

    // Constructor
    Waiter(ListaSimple<Table>* tables){
        this->tables = tables;
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
    int type;   // 1 = ensaladas , 2 = plato fuerte, 3 = reposteria
    int price;

    // Constructor

    Dish(int cookTime,int eatTime,int washTime,int id,int type,int price,QString name, ListaSimpleIngredient*ingredients){
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

struct KitchenOrders{
    QMutex mutex;
    ListaSimple<Order>* list;

    KitchenOrders(){
        this->list = new ListaSimple<Order>;
    }

    void append(Order* order){
        list->insertar(order);
    }

    Order* errase(Order* order){
        return list->searchAndDestroy(order)->data;
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


#endif // STRUCTS_H
