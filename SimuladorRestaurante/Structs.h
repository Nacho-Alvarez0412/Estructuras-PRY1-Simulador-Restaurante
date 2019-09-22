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

template<typename T>

struct ListaSimple{
    //Campos
    Node<T>* primerNodo;

    ListaSimple<T>(){
        this->primerNodo = nullptr;
    }

    void insertar(T*data){
        Node<T>* temp = new Node<T>(data);
        if(primerNodo == nullptr)
            primerNodo = temp;
        else {
            temp->nxt = primerNodo;
            primerNodo = temp;
        }
    }

    Node<T> borrar(T value){
        if (primerNodo == nullptr)
            return nullptr;
        else{
            Node<T>* temp = primerNodo;
            while(temp->nxt != nullptr){
                if (temp->nxt->data == value){
                    Node<T> * borrado = temp->nxt;
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


struct Client{
    int id;
    int quant;

    // Constructor

    Client(int id, int quant){
        this->id = id;
        this->quant = quant;  // random between 1-6
    }
};


struct ClientNode{

    // Campos
    Client * data;
    ClientNode * nxt;

    // Constructor
    ClientNode(Client* value){
        this->data = value;
    }
};

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
            top->nxt = top;
            deleted->nxt = nullptr;
        }
        return deleted;
    }

    bool checkPriority(int id){
        return base->data->id == id;
    }
};

struct Table{
    // Campos

    Client * client;
    int id;
    ListaSimple<Dish>* dishes;

    // Constructor

    Table(int id){
        client = nullptr;
        this->id = id;
    }

    // Metodos

    void setClient(Client*client){
        this->client = client;
    }


    void addDish(Dish*dish){
        this->dishes->insertar(dish);
    }

    ListaSimple<Dish>* getDishes(){
        return dishes;
    }

};

struct Order{

    //Campos
    int task; // 1 = Pedir orden, 2 = Dejar orden en la cocina, 3 = Recoger orden, 4 = Entregar orden, 5 = facturar orden
    ListaSimple<Dish>* dishes;

    // Constructor
    Order(){
        this->task = 1;
        this->dishes->primerNodo = nullptr;
    }

    void changeOrderState(int state){
        this->task = state;
    }

    void setDish(ListaSimple<Dish>*dishes){
        this->dishes = dishes;
    }
};


struct Waiter{
    // Campos

    ListaSimple<Table>* tables;
    Queue<Order>* ordersQueue;

    // Constructor
    Waiter(ListaSimple<Table>* tables){
        this->tables = tables;
        ordersQueue->last=ordersQueue->last = nullptr;
    }

    void addOrder(Order*order){
        ordersQueue->queue(order);
    }

    Order* delieverOrder(){
        return ordersQueue->unqueue()->data;
    }

};

struct Dish{
    // Campos
    QString name;
    ListaSimple<QString>* ingredients;
    int cookTime;
    int eatTime;
    int washTime;
    int id;
    int type;   // 1 = ensaladas , 2 = plato fuerte, 3 = reposteria
    int price;

    // Constructor

    Dish(int cookTime,int eatTime,int washTime,int id,int type,int price,QString name, ListaSimple<QString>*ingredients){
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



#endif // STRUCTS_H
