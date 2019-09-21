#include "Threads.h"


int main(int argc, char *argv[]){

    ClientQueue *cola = new ClientQueue();
    ThreadClientGenerator e;
    e.__init__(cola);
    e.setIntervalo(1,6);
    e.run();



    return 0;
}
