#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <QMainWindow>
#include <QString>
#include <QThread>
#include <QRandomGenerator>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Simulador; }
QT_END_NAMESPACE

class Simulador : public QMainWindow
{
    Q_OBJECT

public:
    Simulador(QWidget *parent = nullptr);
    ~Simulador();

private:
    Ui::Simulador *ui;
};

// Prototipos de Estructuras

struct Restaurant;

/// Uses:

struct Entrance;

// Uses:
struct Client;
struct Node;
struct ClientQueue;
class ClientAssigner; // Thread
class ClientGenerator; // Tread
// End Entrance






/// End Restaurant

#endif // SIMULADOR_H
