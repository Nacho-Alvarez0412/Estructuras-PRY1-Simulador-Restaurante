#include "simuladorwindow.h"
#include "ui_simuladorwindow.h"

SimuladorWindow::SimuladorWindow(QWidget *parent,int cantMesas,int cantMeseros,Menu*menu)
    : QMainWindow(parent)
    , ui(new Ui::SimuladorWindow)
{
    ui->setupUi(this);
    this->menu = menu;
    this->setWindowState(Qt::WindowMaximized);

    Lock * waiterCahsierLock = new Lock();

    int x = ui->chefLabel1->width();
    int y = ui->chefLabel1->height();
    ui->chefLabel1->setPixmap(ChefLogo.scaled(x,y,Qt::KeepAspectRatio));
    ui->chefLabel1_2->setPixmap(ChefLogo.scaled(x,y,Qt::KeepAspectRatio));
    ui->chefLabel1_3->setPixmap(ChefLogo.scaled(x,y,Qt::KeepAspectRatio));

    //Thread Refresh
    refresher.__init__(this);
    refresher.start();

    //Inicia Thread Generado de clientes
    clientGenerator.__init__(ui->QueueTextField,ui->QueueSizeLabel,entranceQueue,1,5);
    clientGenerator.start();

    //Inicia Thread Recepcionista
    clientAssigner.__init__(ui->ClientAssignerTextFiel,entranceQueue,tables);
    clientAssigner.start();


    //Inicia Thread de Chfes
    Lock* lock = new Lock();
    ChefEntrance.__init__(lock,ui->ChefTextField,chefEntrance,kitchenOrders,kitchenReady);
    ChefMeal1.__init__(lock,ui->ChefTextField,chefMeal1,kitchenOrders,kitchenReady);
    ChefMeal2.__init__(lock,ui->ChefTextField,chefMeal2,kitchenOrders,kitchenReady);
    ChefMeal3.__init__(lock,ui->ChefTextField,chefMeal3,kitchenOrders,kitchenReady);
    ChefDessert.__init__(lock,ui->ChefTextField,chefDessert,kitchenOrders,kitchenReady);

    ChefEntrance.start();
    ChefMeal1.start();
    ChefMeal2.start();
    ChefMeal3.start();
    ChefDessert.start();

    //Inicia Thread de Cashier y Dishwasher
    lastStation.__init__(dirtyDishes, ui->CashTextField, ui->WashTextField,ui->cantDePlatos,ui->label);
    lastStation.start();

    if(cantMeseros > cantMesas)
        cantMeseros = cantMesas;

    int meserosBackup = cantMeseros;

    if(cantMeseros>0){
        ui->actionMesero_1->setVisible(true);
        ui->actionMesero_1->setEnabled(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_2->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_3->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_4->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_5->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_6->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_7->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_8->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_9->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_10->setVisible(true);
    }

    if(cantMeseros>0){
        ui->actionMesero_11->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_12->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_13->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_14->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_15->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_16->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_17->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_18->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_19->setVisible(true);
        cantMeseros--;
    }

    if(cantMeseros>0){
        ui->actionMesero_20->setVisible(true);
        cantMeseros--;
    }


    //Crea las 20 mesas
    int cont = 1;
    int clientIndex = 0;

    while(cont <= 20){
        Table* t = new Table(cont,menu);
        tables->insertar(t);
        clients[clientIndex].__init__(t);
        clients[clientIndex].start();
        clientIndex++;
        cont++;
    }

    //Crea n meseros
    int cantMesasXMesero = cantMesas/meserosBackup;
    int meseroIndex = 0;
    int tableIndex = 0;
    int tableSize = cantMesas;
    bool isOne = meserosBackup == 1;
    int id = 1;

    while(meserosBackup != 0){
        int i = cantMesasXMesero;
        ListaSimple<Table>*wt = new ListaSimple<Table>;

        while(i != 0){
            wt->insertar(tables->search(tableIndex)->data);
            i--;
            tableIndex++;
            tableSize--;
        }
        if(meserosBackup == 1 && !isOne){
            while(tableSize!=0){
                wt->insertar(tables->search(tableIndex)->data);
                tableIndex++;
                tableSize--;
            }
        }
        Waiter* w = new Waiter(id,wt);
        id++;
        waiters[meseroIndex].__init__(waiterCahsierLock,w,kitchenOrders,kitchenReady,dirtyDishes,5,ui->CashTextField);
        waiters[meseroIndex].start();
        meseroIndex++;
        meserosBackup--;
    }


    //Activa las mesas indicadas

    Node<Table> * temp = tables->primerNodo;

    while(cantMesas!=0){
        temp->data->state = available;
        temp = temp->nxt;
        cantMesas--;
    }
}

SimuladorWindow::~SimuladorWindow()
{
    delete ui;
}

void SimuladorWindow::paintEvent(QPaintEvent*event){
    QPainter painter(this);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(4);

    painter.setPen(pen);


    //Linea de mesas 1

    if(tables->search(15)->data->state != inactive){
        tables->search(15)->data->label = ui->TableTime16;
        tables->search(15)->data->rectangle = QRect(140,850,100,100);
        painter.drawRect(tables->search(15)->data->rectangle);

        if(tables->search(15)->data->state == available)
            painter.fillRect(tables->search(15)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(15)->data->state != reservada)
            painter.fillRect(tables->search(15)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(15)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime16->setVisible(false);
        ui->Table16Button->setVisible(false);
    }

    if(tables->search(16)->data->state != inactive){
        tables->search(16)->data->label = ui->TableTime17;
        tables->search(16)->data->rectangle = QRect(340,850,100,100);
        painter.drawRect(tables->search(16)->data->rectangle);

        if(tables->search(16)->data->state == available)
            painter.fillRect(tables->search(16)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(16)->data->state != reservada)
            painter.fillRect(tables->search(16)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(16)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime17->setVisible(false);
        ui->Table17Button->setVisible(false);
    }


    if(tables->search(17)->data->state != inactive){
        tables->search(17)->data->label = ui->TableTime18;
        tables->search(17)->data->rectangle = QRect(540,850,100,100);
        painter.drawRect(tables->search(17)->data->rectangle);

        if(tables->search(17)->data->state == available)
            painter.fillRect(tables->search(17)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(17)->data->state != reservada)
            painter.fillRect(tables->search(17)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(17)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime18->setVisible(false);
        ui->Table18Button->setVisible(false);
    }

    if(tables->search(18)->data->state != inactive){
        tables->search(18)->data->label = ui->TableTime19;
        tables->search(18)->data->rectangle = QRect(740,850,100,100);
        painter.drawRect(tables->search(18)->data->rectangle);

        if(tables->search(18)->data->state == available)
            painter.fillRect(tables->search(18)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(18)->data->state != reservada)
            painter.fillRect(tables->search(18)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(18)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime19->setVisible(false);
        ui->Table19Button->setVisible(false);
    }

    if(tables->search(19)->data->state != inactive){
        tables->search(19)->data->label = ui->TableTime20;
        tables->search(19)->data->rectangle = QRect(940,850,100,100);
        painter.drawRect(tables->search(19)->data->rectangle);

        if(tables->search(19)->data->state == available)
            painter.fillRect(tables->search(19)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(19)->data->state != reservada)
            painter.fillRect(tables->search(19)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(19)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime20->setVisible(false);
        ui->Table20Button->setVisible(false);
    }

    // Linea de mesas 2

    if(tables->search(10)->data->state != inactive){
        tables->search(10)->data->label = ui->TableTime11;
        tables->search(10)->data->rectangle = QRect(140,650,100,100);
        painter.drawRect(tables->search(10)->data->rectangle);

        if(tables->search(10)->data->state == available)
            painter.fillRect(tables->search(10)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(10)->data->state != reservada)
            painter.fillRect(tables->search(10)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(10)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime11->setVisible(false);
        ui->Table11Button->setVisible(false);
    }

    if(tables->search(11)->data->state != inactive){
        tables->search(11)->data->label = ui->TableTime12;
        tables->search(11)->data->rectangle = QRect(340,650,100,100);
        painter.drawRect(tables->search(11)->data->rectangle);

        if(tables->search(11)->data->state == available)
            painter.fillRect(tables->search(11)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(11)->data->state != reservada)
            painter.fillRect(tables->search(11)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(11)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime12->setVisible(false);
        ui->Table12Button->setVisible(false);
    }

    if(tables->search(12)->data->state != inactive){
        tables->search(12)->data->label = ui->TableTime13;
        tables->search(12)->data->rectangle = QRect(540,650,100,100);
        painter.drawRect(tables->search(12)->data->rectangle);

        if(tables->search(12)->data->state == available)
            painter.fillRect(tables->search(12)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(12)->data->state != reservada)
            painter.fillRect(tables->search(12)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(12)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime13->setVisible(false);
        ui->Table13Button->setVisible(false);
    }

    if(tables->search(13)->data->state != inactive){
        tables->search(13)->data->label = ui->TableTime14;
        tables->search(13)->data->rectangle = QRect(740,650,100,100);
        painter.drawRect(tables->search(13)->data->rectangle);

        if(tables->search(13)->data->state == available)
            painter.fillRect(tables->search(13)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(13)->data->state != reservada)
            painter.fillRect(tables->search(13)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(13)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime14->setVisible(false);
        ui->Table14Button->setVisible(false);
    }

    if(tables->search(14)->data->state != inactive){
        tables->search(14)->data->label = ui->TableTime15;
        tables->search(14)->data->rectangle = QRect(940,650,100,100);
        painter.drawRect(tables->search(14)->data->rectangle);

        if(tables->search(14)->data->state == available)
            painter.fillRect(tables->search(14)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(14)->data->state != reservada)
            painter.fillRect(tables->search(14)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(14)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime15->setVisible(false);
        ui->Table15Button->setVisible(false);
    }

    // Linea de mesas 3

    if(tables->search(5)->data->state != inactive){
        tables->search(5)->data->label = ui->TableTime6;
        tables->search(5)->data->rectangle = QRect(140,450,100,100);
        painter.drawRect(tables->search(5)->data->rectangle);

        if(tables->search(5)->data->state == available)
            painter.fillRect(tables->search(5)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(5)->data->state != reservada)
            painter.fillRect(tables->search(5)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(5)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime6->setVisible(false);
        ui->Table6Button->setVisible(false);
    }

    if(tables->search(6)->data->state != inactive){
        tables->search(6)->data->label = ui->TableTime7;
        tables->search(6)->data->rectangle = QRect(340,450,100,100);
        painter.drawRect(tables->search(6)->data->rectangle);

        if(tables->search(6)->data->state == available)
            painter.fillRect(tables->search(6)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(6)->data->state != reservada)
            painter.fillRect(tables->search(6)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(6)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime7->setVisible(false);
        ui->Table7Button->setVisible(false);
    }

    if(tables->search(7)->data->state != inactive){
        tables->search(7)->data->label = ui->TableTime8;
        tables->search(7)->data->rectangle = QRect(540,450,100,100);
        painter.drawRect(tables->search(7)->data->rectangle);

        if(tables->search(7)->data->state == available)
            painter.fillRect(tables->search(7)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(7)->data->state != reservada)
            painter.fillRect(tables->search(7)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(7)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime8->setVisible(false);
        ui->Table8Button->setVisible(false);
    }

    if(tables->search(8)->data->state != inactive){
        tables->search(8)->data->label = ui->TableTime9;
        tables->search(8)->data->rectangle = QRect(740,450,100,100);
        painter.drawRect(tables->search(8)->data->rectangle);

        if(tables->search(8)->data->state == available)
            painter.fillRect(tables->search(8)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(8)->data->state != reservada)
            painter.fillRect(tables->search(8)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(8)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime9->setVisible(false);
        ui->Table9Button->setVisible(false);
    }

    if(tables->search(9)->data->state != inactive){
        tables->search(9)->data->label = ui->TableTime10;
        tables->search(9)->data->rectangle = QRect(940,450,100,100);
        painter.drawRect(tables->search(9)->data->rectangle);

        if(tables->search(9)->data->state == available)
            painter.fillRect(tables->search(9)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(9)->data->state != reservada)
            painter.fillRect(tables->search(9)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(9)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime10->setVisible(false);
        ui->Table10Button->setVisible(false);
    }

    // Linea de mesas 4

    if(tables->search(0)->data->state != inactive){
        tables->search(0)->data->label = ui->TableTime1;
        tables->search(0)->data->rectangle = QRect(140,250,100,100);
        painter.drawRect(tables->search(0)->data->rectangle);

        if(tables->search(0)->data->state == available)
            painter.fillRect(tables->search(0)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(0)->data->state != reservada)
            painter.fillRect(tables->search(0)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(0)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime1->setVisible(false);
        ui->Table1Button->setVisible(false);
    }

    if(tables->search(1)->data->state != inactive){
        tables->search(1)->data->label = ui->TableTime2;
        tables->search(1)->data->rectangle = QRect(340,250,100,100);
        painter.drawRect(tables->search(1)->data->rectangle);

        if(tables->search(1)->data->state == available)
            painter.fillRect(tables->search(1)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(1)->data->state != reservada)
            painter.fillRect(tables->search(1)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(1)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime2->setVisible(false);
        ui->Table2Button->setVisible(false);
    }

    if(tables->search(2)->data->state != inactive){
        tables->search(2)->data->label = ui->TableTime3;
        tables->search(2)->data->rectangle = QRect(540,250,100,100);
        painter.drawRect(tables->search(2)->data->rectangle);

        if(tables->search(2)->data->state == available)
            painter.fillRect(tables->search(2)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(2)->data->state != reservada)
            painter.fillRect(tables->search(2)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(2)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime3->setVisible(false);
        ui->Table3Button->setVisible(false);
    }

    if(tables->search(3)->data->state != inactive){
        tables->search(3)->data->label = ui->TableTime4;
        tables->search(3)->data->rectangle = QRect(740,250,100,100);
        painter.drawRect(tables->search(3)->data->rectangle);

        if(tables->search(3)->data->state == available)
            painter.fillRect(tables->search(3)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(3)->data->state != reservada)
            painter.fillRect(tables->search(3)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(3)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime4->setVisible(false);
        ui->Table4Button->setVisible(false);
    }

    if(tables->search(4)->data->state != inactive){
        tables->search(4)->data->label = ui->TableTime5;
        tables->search(4)->data->rectangle = QRect(940,250,100,100);
        painter.drawRect(tables->search(4)->data->rectangle);

        if(tables->search(4)->data->state == available)
            painter.fillRect(tables->search(4)->data->rectangle, QBrush(QColor(0,255,127), Qt::SolidPattern));
        else if(tables->search(4)->data->state != reservada)
            painter.fillRect(tables->search(4)->data->rectangle, QBrush(QColor( 255, 87, 51 ), Qt::SolidPattern));
        else
            painter.fillRect(tables->search(4)->data->rectangle, QBrush(Qt::yellow, Qt::SolidPattern));
    }
    else{
        ui->TableTime5->setVisible(false);
        ui->Table5Button->setVisible(false);
    }


}


void SimuladorWindow::on_ButtonClientGenerator_clicked()
{
    if(clientGenerator.pause == false){
        clientGenerator.Pause();
        ui->ButtonClientGenerator->setText("Generar Clientes");
    }
    else{
        clientGenerator.Unpause();
        ui->ButtonClientGenerator->setText("Pausar");
    }
}

void SimuladorWindow::on_AssignTablesButton_clicked()
{
    if(clientAssigner.pause == false){
        clientAssigner.Pause();
        ui->AssignTablesButton->setText("Asignar Clientes");
    }
    else{
        clientAssigner.Unpause();
        ui->AssignTablesButton->setText("Pausar");
    }

}

void SimuladorWindow::on_Table6Button_clicked()
{
    ui->TableIDLabel->setNum(6);
    ui->TableInfoTextFiedl->setText(tables->search(5)->data->toString());
}

void SimuladorWindow::on_Table1Button_clicked()
{
    ui->TableIDLabel->setNum(1);
    ui->TableInfoTextFiedl->setText(tables->search(0)->data->toString());
}

void SimuladorWindow::on_Table2Button_clicked()
{
    ui->TableIDLabel->setNum(2);
    ui->TableInfoTextFiedl->setText(tables->search(1)->data->toString());
}

void SimuladorWindow::on_Table3Button_clicked()
{
    ui->TableIDLabel->setNum(3);
    ui->TableInfoTextFiedl->setText(tables->search(2)->data->toString());
}

void SimuladorWindow::on_Table4Button_clicked()
{
    ui->TableIDLabel->setNum(4);
    ui->TableInfoTextFiedl->setText(tables->search(3)->data->toString());
}

void SimuladorWindow::on_Table5Button_clicked()
{
    ui->TableIDLabel->setNum(5);
    ui->TableInfoTextFiedl->setText(tables->search(4)->data->toString());
}

void SimuladorWindow::on_Table7Button_clicked()
{
    ui->TableIDLabel->setNum(7);
    ui->TableInfoTextFiedl->setText(tables->search(6)->data->toString());
}

void SimuladorWindow::on_Table8Button_clicked()
{
    ui->TableIDLabel->setNum(8);
    ui->TableInfoTextFiedl->setText(tables->search(7)->data->toString());
}

void SimuladorWindow::on_Table9Button_clicked()
{
    ui->TableIDLabel->setNum(9);
    ui->TableInfoTextFiedl->setText(tables->search(8)->data->toString());
}

void SimuladorWindow::on_Table10Button_clicked()
{
    ui->TableIDLabel->setNum(10);
    ui->TableInfoTextFiedl->setText(tables->search(9)->data->toString());
}

void SimuladorWindow::on_Table11Button_clicked()
{
    ui->TableIDLabel->setNum(11);
    ui->TableInfoTextFiedl->setText(tables->search(10)->data->toString());
}

void SimuladorWindow::on_Table12Button_clicked()
{
    ui->TableIDLabel->setNum(12);
    ui->TableInfoTextFiedl->setText(tables->search(11)->data->toString());
}

void SimuladorWindow::on_Table13Button_clicked()
{
    ui->TableIDLabel->setNum(13);
    ui->TableInfoTextFiedl->setText(tables->search(12)->data->toString());
}

void SimuladorWindow::on_Table14Button_clicked()
{
    ui->TableIDLabel->setNum(14);
    ui->TableInfoTextFiedl->setText(tables->search(13)->data->toString());
}

void SimuladorWindow::on_Table15Button_clicked()
{
    ui->TableIDLabel->setNum(15);
    ui->TableInfoTextFiedl->setText(tables->search(14)->data->toString());
}

void SimuladorWindow::on_Table16Button_clicked()
{
    ui->TableIDLabel->setNum(16);
    ui->TableInfoTextFiedl->setText(tables->search(15)->data->toString());
}

void SimuladorWindow::on_Table17Button_clicked()
{
    ui->TableIDLabel->setNum(17);
    ui->TableInfoTextFiedl->setText(tables->search(16)->data->toString());
}

void SimuladorWindow::on_Table18Button_clicked()
{
    ui->TableIDLabel->setNum(18);
    ui->TableInfoTextFiedl->setText(tables->search(17)->data->toString());
}

void SimuladorWindow::on_Table19Button_clicked()
{
    ui->TableIDLabel->setNum(19);
    ui->TableInfoTextFiedl->setText(tables->search(18)->data->toString());
}

void SimuladorWindow::on_Table20Button_clicked()
{
    ui->TableIDLabel->setNum(20);
    ui->TableInfoTextFiedl->setText(tables->search(19)->data->toString());
}

void SimuladorWindow::on_actionMesero_1_triggered()
{

    waiterDialog1 = new WaiterDialog(this,1,&waiters[0]);
    waiterDialog1->show();
}

void SimuladorWindow::on_actionMesero_2_triggered()
{
    waiterDialog2 = new WaiterDialog(this,2,&waiters[1]);
    waiterDialog2->show();
}

void SimuladorWindow::on_actionMesero_3_triggered()
{
    waiterDialog3 = new WaiterDialog(this,3,&waiters[2]);
    waiterDialog3->show();
}

void SimuladorWindow::on_actionMesero_4_triggered()
{
    waiterDialog4 = new WaiterDialog(this,4,&waiters[3]);
    waiterDialog4->show();

}

void SimuladorWindow::on_actionMesero_5_triggered()
{
    waiterDialog5 = new WaiterDialog(this,5,&waiters[4]);
    waiterDialog5->show();
}

void SimuladorWindow::on_actionMesero_6_triggered()
{
    waiterDialog6 = new WaiterDialog(this,6,&waiters[5]);
    waiterDialog6->show();
}

void SimuladorWindow::on_actionMesero_7_triggered()
{
    waiterDialog7 = new WaiterDialog(this,7,&waiters[6]);
    waiterDialog7->show();
}

void SimuladorWindow::on_actionMesero_8_triggered()
{
    waiterDialog8 = new WaiterDialog(this,8,&waiters[7]);
    waiterDialog8->show();
}

void SimuladorWindow::on_actionMesero_9_triggered()
{
    waiterDialog9 = new WaiterDialog(this,9,&waiters[8]);
    waiterDialog9->show();
}

void SimuladorWindow::on_actionMesero_10_triggered()
{
    waiterDialog10 = new WaiterDialog(this,10,&waiters[9]);
    waiterDialog10->show();
}

void SimuladorWindow::on_actionMesero_11_triggered()
{
    waiterDialog11 = new WaiterDialog(this,11,&waiters[10]);
    waiterDialog11->show();
}

void SimuladorWindow::on_actionMesero_12_triggered()
{
    waiterDialog12 = new WaiterDialog(this,12,&waiters[11]);
    waiterDialog12->show();
}

void SimuladorWindow::on_actionMesero_13_triggered()
{
    waiterDialog13 = new WaiterDialog(this,13,&waiters[12]);
    waiterDialog13->show();
}

void SimuladorWindow::on_actionMesero_14_triggered()
{
    waiterDialog14 = new WaiterDialog(this,14,&waiters[13]);
    waiterDialog14->show();
}

void SimuladorWindow::on_actionMesero_15_triggered()
{
    waiterDialog15 = new WaiterDialog(this,15,&waiters[14]);
    waiterDialog15->show();
}

void SimuladorWindow::on_actionMesero_16_triggered()
{
    waiterDialog16 = new WaiterDialog(this,16,&waiters[15]);
    waiterDialog16->show();
}

void SimuladorWindow::on_actionMesero_17_triggered()
{
    waiterDialog17 = new WaiterDialog(this,17,&waiters[16]);
    waiterDialog17->show();
}

void SimuladorWindow::on_actionMesero_18_triggered()
{
    waiterDialog18 = new WaiterDialog(this,18,&waiters[17]);
    waiterDialog18->show();
}

void SimuladorWindow::on_actionMesero_19_triggered()
{
    waiterDialog19 = new WaiterDialog(this,19,&waiters[18]);
    waiterDialog19->show();
}

void SimuladorWindow::on_actionMesero_20_triggered()
{
    waiterDialog20 = new WaiterDialog(this,20,&waiters[19]);
    waiterDialog20->show();
}

void SimuladorWindow::on_CookEntranceButton_clicked()
{
    if(ChefEntrance.pause){
        ChefEntrance.pause = false;
        ui->CookEntranceButton->setText("Pausar");
    }
    else{
        ChefEntrance.pause = true;
        ui->CookEntranceButton->setText("Cocinar");
    }
}

void SimuladorWindow::on_CookMealButton3_clicked()
{
    if(ChefMeal3.pause){
        ChefMeal3.pause = false;
        ui->CookMealButton3->setText("Pausar");
    }
    else{
        ChefMeal3.pause = true;
        ui->CookMealButton3->setText("Cocinar");
    }
}

void SimuladorWindow::on_CookMealButton2_clicked()
{
    if(ChefMeal2.pause){
        ChefMeal2.pause = false;
        ui->CookMealButton2->setText("Pausar");
    }
    else{
        ChefMeal2.pause = true;
        ui->CookMealButton2->setText("Cocinar");
    }
}

void SimuladorWindow::on_CookMealButton1_clicked()
{
    if(ChefMeal1.pause){
        ChefMeal1.pause = false;
        ui->CookMealButton1->setText("Pausar");
    }
    else{
        ChefMeal1.pause = true;
        ui->CookMealButton1->setText("Cocinar");
    }
}

void SimuladorWindow::on_CookDessertButton_clicked()
{
    if(ChefDessert.pause){
        ChefDessert.pause = false;
        ui->CookDessertButton->setText("Pausar");
    }
    else{
        ChefDessert.pause = true;
        ui->CookDessertButton->setText("Cocinar");
    }
}

void SimuladorWindow::on_actionIntervalo_de_llegada_triggered()
{
    setIntervalDialog = new Dialog(this,&clientGenerator);
    setIntervalDialog->show();
}

void SimuladorWindow::on_actionProbabilidad_de_plato_fuerte_triggered()
{

    qDebug()<< menu;
    setPorcentages = new DialogMenuPorcentages(this,menu);
    setPorcentages->show();

}

void SimuladorWindow::on_actionRestart_Simulation_triggered()
{
    FormConfiguration* w1 = new FormConfiguration(nullptr,menu);
    w1->show();
    this->close();

}

void SimuladorWindow::on_actionVer_Menu_triggered()
{
    DialogMenu * w = new DialogMenu(nullptr,menu);
    w->show();
}



void SimuladorWindow::on_CashPauseButton_clicked()
{
    if (lastStation.pause == true){
        lastStation.Unpause();
        ui->CashPauseButton->setText("Pausar");
    } else {
        lastStation.Pause();
        ui->CashPauseButton->setText("Lavar");
    }
}



void SimuladorWindow::on_TypeCashButton_clicked()
{
    if (lastStation.mode == true){
        lastStation.stack();
        ui->TypeCashButton->setText("Pila");
    } else {
        lastStation.queue();
        ui->TypeCashButton->setText("Cola");
    }
}

void SimuladorWindow::on_actionSolicitar_Reserva_triggered()
{
    DialogReserves * w = new DialogReserves(this,&clientAssigner);
    w->show();
}

void SimuladorWindow::on_actionStart_triggered()
{
    clientGenerator.Unpause();
    ui->ButtonClientGenerator->setText("Pausar");
    clientAssigner.Unpause();
    ui->AssignTablesButton->setText("Pausar");
    ChefMeal1.pause = false;
    ui->CookMealButton1->setText("Pausar");
    ChefMeal2.pause = false;
    ui->CookMealButton2->setText("Pausar");
    ChefMeal3.pause = false;
    ui->CookMealButton3->setText("Pausar");
    ChefDessert.pause = false;
    ui->CookDessertButton->setText("Pausar");
    ChefEntrance.pause = false;
    ui->CookEntranceButton->setText("Pausar");
    lastStation.Unpause();
    ui->CashPauseButton->setText("Pausar");

    for(int i=0 ; i<20 ; i++)
        clients[i].Unpause();

}

void SimuladorWindow::on_actionDetener_triggered()
{
    clientGenerator.Pause();
    ui->ButtonClientGenerator->setText("Generar Clientes");
    clientAssigner.Pause();
    ui->AssignTablesButton->setText("Asignar Clientes");
    ChefMeal1.pause = true;
    ui->CookMealButton1->setText("Cocinar");
    ChefMeal2.pause = true;
    ui->CookMealButton2->setText("Cocinar");
    ChefMeal3.pause = true;
    ui->CookMealButton3->setText("Cocinar");
    ChefDessert.pause = true;
    ui->CookDessertButton->setText("Cocinar");
    ChefEntrance.pause = true;
    ui->CookEntranceButton->setText("Cocinar");
    lastStation.Pause();
    ui->CashPauseButton->setText("Lavar");

    for(int i=0 ; i<20 ; i++)
        clients[i].Unpause();
}
