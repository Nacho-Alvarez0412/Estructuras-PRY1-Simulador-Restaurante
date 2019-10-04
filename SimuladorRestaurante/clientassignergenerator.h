#ifndef CLIENTASSIGNERGENERATOR_H
#define CLIENTASSIGNERGENERATOR_H

#include "Structs.h"

class ClientAssignerGenerator : public QThread
{
public:
    //Campos
    bool running;
    bool pause;
    Queue<Client>* clientQueue;
    ListaSimple<Table>* tables;
    QTextEdit * textField;

    //Constructor
    ClientAssignerGenerator();
    void __init__(QTextEdit*,Queue<Client>*,ListaSimple<Table>*);

    //Metodos
    void run();
    void Pause();
    void Unpause();
    Node<Table> * firstVacancy();
};

#endif // CLIENTASSIGNERGENERATOR_H
