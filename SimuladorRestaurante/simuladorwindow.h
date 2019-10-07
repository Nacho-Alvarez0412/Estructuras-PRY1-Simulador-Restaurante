#ifndef SIMULADORWINDOW_H
#define SIMULADORWINDOW_H

#include <QMainWindow>
#include "clientgeneratorthread.h"
#include "clientassignergenerator.h"
#include "clientthread.h"
#include "refreshthread.h"
#include "waiterthread.h"
#include "waiterdialog.h"
#include "chefthread.h"
#include "dialog.h"
#include "dialogmenuporcentages.h"
#include "formconfiguration.h"
#include "dialogmenu.h"
#include "threadlaststation.h"
#include "dialogreserves.h"
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class SimuladorWindow; }
QT_END_NAMESPACE

class SimuladorWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClientGeneratorThread clientGenerator;
    ClientAssignerGenerator clientAssigner;
    RefreshThread refresher;
    ClientThread clients[20];
    WaiterThread waiters[20];
    ChefThread ChefEntrance;
    ChefThread ChefMeal1;
    ChefThread ChefMeal2;
    ChefThread ChefMeal3;
    ChefThread ChefDessert;
    ThreadLastStation lastStation;

    Queue<Client>* entranceQueue = new Queue<Client>();
    ListaSimple<Table>* tables = new ListaSimple<Table>();
    ListaSimple<Order>* kitchenOrders = new ListaSimple<Order>();
    ListaSimple<Order>* kitchenReady = new ListaSimple<Order>();
    ListaSimple<Dish>* dirtyDishes = new ListaSimple<Dish>();
    Menu* menu;
    Chef* chefEntrance = new Chef(entrance);
    Chef* chefMeal1 = new Chef(meal);
    Chef* chefMeal2 = new Chef(meal);
    Chef* chefMeal3 = new Chef(meal);
    Chef* chefDessert = new Chef(dessert);


    QPixmap ChefLogo = QPixmap("C:/Users/nacho/Dropbox/TEC/Estructura de Datos/Imagenes/remychefcito.jpg");


    virtual void paintEvent(QPaintEvent*event);

    SimuladorWindow(QWidget *parent = nullptr,int = 0,int = 0,Menu* = nullptr);
    ~SimuladorWindow();

private slots:
    void on_ButtonClientGenerator_clicked();

    void on_AssignTablesButton_clicked();

    void on_Table6Button_clicked();

    void on_Table1Button_clicked();

    void on_Table2Button_clicked();

    void on_Table3Button_clicked();

    void on_Table4Button_clicked();

    void on_Table5Button_clicked();

    void on_Table7Button_clicked();

    void on_Table8Button_clicked();

    void on_Table9Button_clicked();

    void on_Table10Button_clicked();

    void on_Table11Button_clicked();

    void on_Table12Button_clicked();

    void on_Table13Button_clicked();

    void on_Table14Button_clicked();

    void on_Table15Button_clicked();

    void on_Table16Button_clicked();

    void on_Table17Button_clicked();

    void on_Table18Button_clicked();

    void on_Table19Button_clicked();

    void on_Table20Button_clicked();

    void on_actionMesero_1_triggered();

    void on_actionMesero_2_triggered();

    void on_actionMesero_3_triggered();

    void on_actionMesero_4_triggered();

    void on_actionMesero_5_triggered();

    void on_actionMesero_6_triggered();

    void on_actionMesero_7_triggered();

    void on_actionMesero_8_triggered();

    void on_actionMesero_9_triggered();

    void on_actionMesero_10_triggered();

    void on_actionMesero_11_triggered();

    void on_actionMesero_12_triggered();

    void on_actionMesero_13_triggered();

    void on_actionMesero_14_triggered();

    void on_actionMesero_15_triggered();

    void on_actionMesero_16_triggered();

    void on_actionMesero_17_triggered();

    void on_actionMesero_18_triggered();

    void on_actionMesero_19_triggered();

    void on_actionMesero_20_triggered();

    void on_CookEntranceButton_clicked();

    void on_CookMealButton3_clicked();

    void on_CookMealButton2_clicked();

    void on_CookMealButton1_clicked();

    void on_CookDessertButton_clicked();

    void on_actionIntervalo_de_llegada_triggered();

    void on_actionProbabilidad_de_plato_fuerte_triggered();

    void on_actionRestart_Simulation_triggered();

    void on_actionVer_Menu_triggered();

    void on_CashPauseButton_clicked();

    void on_TypeCashButton_clicked();

    void on_actionSolicitar_Reserva_triggered();

    void on_actionStart_triggered();

    void on_actionDetener_triggered();

private:
    Ui::SimuladorWindow *ui;
    WaiterDialog * waiterDialog1;
    WaiterDialog * waiterDialog2;
    WaiterDialog * waiterDialog3;
    WaiterDialog * waiterDialog4;
    WaiterDialog * waiterDialog5;
    WaiterDialog * waiterDialog6;
    WaiterDialog * waiterDialog7;
    WaiterDialog * waiterDialog8;
    WaiterDialog * waiterDialog9;
    WaiterDialog * waiterDialog10;
    WaiterDialog * waiterDialog11;
    WaiterDialog * waiterDialog12;
    WaiterDialog * waiterDialog13;
    WaiterDialog * waiterDialog14;
    WaiterDialog * waiterDialog15;
    WaiterDialog * waiterDialog16;
    WaiterDialog * waiterDialog17;
    WaiterDialog * waiterDialog18;
    WaiterDialog * waiterDialog19;
    WaiterDialog * waiterDialog20;
    Dialog * setIntervalDialog;
    DialogMenuPorcentages * setPorcentages;

};
#endif // SIMULADORWINDOW_H
