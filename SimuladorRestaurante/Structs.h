#ifndef STRUCTS_H
#define STRUCTS_H
#include "Header.h"

template <typename T>
struct Node{
    // Campos
    Node<T> *nxt;
    T data;

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

    void queue(T data){
        if (this->isEmpty())
            this->last = this->first = new Node<T>(data);
        else{
            this->last->next = new Node<T>(data);
            this->last = this->last->next;
        }
    }

    T unqueue(){
        Node<T> * borrado = first;

        if(!isEmpty()){
            first = first->next;
            borrado->next = nullptr;
        }
        else
            return nullptr;
        return borrado->data;
    }
};

template<typename T>

struct ListaSimple{
    //Campos
    T* primerNodo;

    ListaSimple<T>(){
        this->primerNodo = nullptr;
    }

    void insertar(T*data){
        Node<T> temp = new Node<T>(data);
        if(primerNodo == nullptr)
            primerNodo = temp;
        else {
            temp.nxt = primerNodo;
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
    Dish* dishArray[18] = {};

    // Constructor

    Table(int id){
        client = nullptr;
        this->id = id;
    }

    // Metodos

    void setClient(Client*client){
        this->client = client;
}

    int lenght(){
        int cont = 0;
        while (dishArray[cont] != nullptr){
            cont++;
        }
        return cont;
    }

    void addDish(Dish*dish){
        int len = lenght();
        this->dishArray[len] = dish;
    }

// Falta el obtener factura!!!!!
};

struct Waiter{


}



#endif // STRUCTS_H
