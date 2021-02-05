#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene= new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1491,-881);
    delt_t=1;
    t=0;
    t_limit=-1;
    punto=0;
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this, SLOT(advance_funtion()));
    timer->start(1000/60);


}

void MainWindow::delete_all()
{
    while(Cd.size() != 0)
    {
        while(Cd.at(0)->balasA.size() != 0)
        {
            scene->removeItem(Cd.at(0)->balasA.at(0));
            Cd.at(0)->balasA.removeAt(0);
        }
        while(Cd.at(0)->balasD.size() != 0)
        {
            scene->removeItem(Cd.at(0)->balasD.at(0));
            Cd.at(0)->balasD.removeAt(0);
        }
        while(Cd.at(0)->balasDD.size() != 0)
        {
            scene->removeItem(Cd.at(0)->balasDD.at(0));
            Cd.at(0)->balasDD.removeAt(0);
        }
        scene->removeItem(Cd.at(0));
        Cd.removeAt(0);
    }
    while(Co.size() != 0)
    {
        while(Co.at(0)->balasA.size() != 0)
        {
            scene->removeItem(Co.at(0)->balasA.at(0));
            Co.at(0)->balasA.removeAt(0);
        }
        while(Co.at(0)->balasD.size() != 0)
        {
            scene->removeItem(Co.at(0)->balasD.at(0));
            Co.at(0)->balasD.removeAt(0);
        }
        while(Co.at(0)->balasDD.size() != 0)
        {
            scene->removeItem(Co.at(0)->balasDD.at(0));
            Co.at(0)->balasDD.removeAt(0);
        }
        scene->removeItem(Co.at(0));
        Co.removeAt(0);
    }
    while(T1.size() != 0)
    {
        scene->removeItem(T1.at(0));
        T1.removeAt(0);
    }
    while(T3.size() != 0)
    {
        scene->removeItem(T3.at(0));
        T3.removeAt(0);
    }
    while(T2.size() != 0)
    {
        scene->removeItem(T2.at(0));
        T2.removeAt(0);
    }
}

void MainWindow::advance_funtion()
{
    if(t<t_limit+1)
    {
        if(punto==1 || punto==2)
        {
            t+=delt_t;
            if(Cd.size()!=0)
            {
                if(Cd.at(0)->balasA.size()!=0)
                {
                    Cd.at(0)->balasA.at(0)->bala_at(t);
                }
                if(Cd.at(0)->balasD.size()!=0)
                {
                    Cd.at(0)->balasD.at(0)->bala_at(t);
                }
                if(Cd.at(0)->balasDD.size()!=0)
                {
                    Cd.at(0)->balasDD.at(0)->bala_at(t);
                }
            }
            if(Co.size()!=0)
            {
                if(Co.at(0)->balasA.size()!=0)
                {
                    Co.at(0)->balasA.at(0)->bala_at(t);
                }
                if(Co.at(0)->balasD.size()!=0)
                {
                    Co.at(0)->balasD.at(0)->bala_at(t);
                }
                if(Co.at(0)->balasDD.size()!=0)
                {
                    Co.at(0)->balasDD.at(0)->bala_at(t);
                }
            }
        }



        if(punto==3)
        {
            t+=delt_t;
            if(Cd.size()!=0 && t>OtoD)
            {
                if(Cd.at(0)->balasA.size()!=0)
                {
                    Cd.at(0)->balasA.at(0)->bala_at(t);
                }
                if(Cd.at(0)->balasD.size()!=0)
                {
                    Cd.at(0)->balasD.at(0)->bala_at(t-OtoD);
                }
                if(Cd.at(0)->balasDD.size()!=0)
                {
                    Cd.at(0)->balasDD.at(0)->bala_at(t);
                }
            }
            if(Co.size()!=0)
            {
                if(Co.at(0)->balasA.size()!=0)
                {
                    Co.at(0)->balasA.at(0)->bala_at(t);
                }
                if(Co.at(0)->balasD.size()!=0)
                {
                    Co.at(0)->balasD.at(0)->bala_at(t);
                }
                if(Co.at(0)->balasDD.size()!=0)
                {
                    Co.at(0)->balasDD.at(0)->bala_at(t);
                }
            }
        }
        if(punto==5)
        {
            t+=delt_t;
            if(Cd.size()!=0 && t>OtoD)
            {
                if(Cd.at(0)->balasA.size()!=0)
                {
                    Cd.at(0)->balasA.at(0)->bala_at(t);
                }
                if(Cd.at(0)->balasD.size()!=0)
                {
                    Cd.at(0)->balasD.at(0)->bala_at(t-OtoD);
                }
                if(Cd.at(0)->balasDD.size()!=0)
                {
                    Cd.at(0)->balasDD.at(0)->bala_at(t);
                }
            }
            if(Co.size()!=0)
            {
                if(Co.at(0)->balasA.size()!=0)
                {
                    Co.at(0)->balasA.at(0)->bala_at(t);
                }
                if(Co.at(0)->balasD.size()!=0)
                {
                    Co.at(0)->balasD.at(0)->bala_at(t);
                }
                if(Co.at(0)->balasDD.size()!=0 && t>OtoD+DtoO)
                {
                    Co.at(0)->balasDD.at(0)->bala_at(t-(OtoD+DtoO));
                }
            }
        }

        if(punto==4)
        {
            t+=delt_t;
            if(Cd.size()!=0)
            {
                if(Cd.at(0)->balasA.size()!=0)
                {
                    Cd.at(0)->balasA.at(0)->bala_at(t);
                }
                if(Cd.at(0)->balasD.size()!=0)
                {
                    Cd.at(0)->balasD.at(0)->bala_at(t);
                }
                if(Cd.at(0)->balasDD.size()!=0)
                {
                    Cd.at(0)->balasDD.at(0)->bala_at(t);
                }
            }
            if(Co.size()!=0 && t>DtoO)
            {
                if(Co.at(0)->balasA.size()!=0)
                {
                    Co.at(0)->balasA.at(0)->bala_at(t);
                }
                if(Co.at(0)->balasD.size()!=0)
                {
                    Co.at(0)->balasD.at(0)->bala_at(t-DtoO);
                }
                if(Co.at(0)->balasDD.size()!=0)
                {
                    Co.at(0)->balasDD.at(0)->bala_at(t);
                }
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_6_clicked()
{
    delete_all();
    float hd=ui->Hd->text().toFloat();
    float ho=ui->Ho->text().toFloat();
    float d=ui->dist->text().toFloat();
    Co. push_back(new canhon({0,ho},'O',d));
    Cd.push_back(new canhon({d,hd},'D',d));
    scene->addItem(Co.at(0));
    scene->addItem(Cd.at(0));
}





void MainWindow::primero()
{
     Co.at(0)->balasA.push_back(new balas(Co.at(0)->get_pos(),Cd.at(0)->get_pos(),'O',Co.at(0)->RB1));
     t_limit=Co.at(0)->balasA.at(0)->get_colitio_moment();
}

void MainWindow::segundo()
{
    Cd.at(0)->balasA.push_back(new balas(Cd.at(0)->get_pos(),Co.at(0)->get_pos(),'D',Cd.at(0)->RB1));
    t_limit=Cd.at(0)->balasA.at(0)->get_colitio_moment();
}

void MainWindow::tercero()
{
    do
    {
    primero();
    }
    while(t_limit+0.8<OtoD);
    Cd.at(0)->balasD.push_back( new balas(Cd.at(0)->get_pos(),Co.at(0)->balasA.at(0)->get_pos_at(OtoD),Co.at(0)->balasA.at(0)->get_vel_at(OtoD),
                                          'D',Cd.at(0)->RB1,Co.at(0)->balasA.at(0)->get_colitio_moment()));

}

void MainWindow::cuarto()
{
    do
    {
    segundo();
    }
    while(t_limit+0.8<DtoO);
    Co.at(0)->balasD.push_back( new balas(Co.at(0)->get_pos(),Cd.at(0)->balasA.at(0)->get_pos_at(DtoO),Cd.at(0)->balasA.at(0)->get_vel_at(DtoO),
                                          'O',Co.at(0)->RB1,Cd.at(0)->balasA.at(0)->get_colitio_moment()));
}

void MainWindow::quinto()
{
    do
    {
    primero();
    }
    while(t_limit+1.4<OtoD+DtoO);
    do
    {
    Cd.at(0)->balasD.push_back( new balas(Cd.at(0)->get_pos(),Co.at(0)->balasA.at(0)->get_pos_at(OtoD),Co.at(0)->balasA.at(0)->get_vel_at(OtoD),
                                          'D',Cd.at(0)->RB1,Co.at(0)->balasA.at(0)->get_colitio_moment()));
    }
    while(Cd.at(0)->balasD.at(0)->get_colitio_moment()+0.7<DtoO);
    Co.at(0)->balasDD.push_back( new balas(Co.at(0)->get_pos(), Cd.at(0)->balasD.at(0)->get_pos_at(DtoO),Cd.at(0)->balasD.at(0)->get_vel_at(DtoO),
                                          'O',Co.at(0)->RB2,Cd.at(0)->balasD.at(0)->get_colitio_moment()));
}

void MainWindow::on_pushButton_clicked()
{
    on_pushButton_6_clicked();
    punto=1;
    primero();
    scene->addItem( Co.at(0)->balasA.at(0));
    t=0;

}

void MainWindow::on_pushButton_2_clicked()
{
    on_pushButton_6_clicked();
    punto=2;
    segundo();
    scene->addItem( Cd.at(0)->balasA.at(0));
    t=0;
}

void MainWindow::on_pushButton_3_clicked()
{
    on_pushButton_6_clicked();
    punto=3;
    tercero();
    scene->addItem( Cd.at(0)->balasD.at(0));
    scene->addItem( Co.at(0)->balasA.at(0));
    t=0;
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    delt_t= float(value)/300 +0.001;
    ui->lcdNumber->display(delt_t*60);
}

void MainWindow::on_pushButton_4_clicked()
{
    on_pushButton_6_clicked();
    punto=4;
    cuarto();
    scene->addItem( Cd.at(0)->balasA.at(0));
    scene->addItem( Co.at(0)->balasD.at(0));
    t=0;
}

void MainWindow::on_pushButton_5_clicked()
{
    on_pushButton_6_clicked();
    punto=5;
    quinto();
    scene->addItem( Cd.at(0)->balasD.at(0));
    scene->addItem( Co.at(0)->balasA.at(0));
    scene->addItem( Co.at(0)->balasDD.at(0));
    t=0;
}
