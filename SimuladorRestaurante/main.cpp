#include "Header.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Simulador w;
    w.show();
    return a.exec();
}
