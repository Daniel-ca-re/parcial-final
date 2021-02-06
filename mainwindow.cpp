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
    delt_t=1/60;
    t=0;
    t_limit=-1;
    punto=0;
    radO1= new radio_d_explocion();
    radD1= new radio_d_explocion();
    radO2= new radio_d_explocion();
    scene->addItem(radD1);
    scene->addItem(radO1);
    scene->addItem(radO2);


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
        scene->removeItem(Cd.at(0)->platform);
        scene->removeItem(Cd.at(0)->rad);
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
        scene->removeItem(Co.at(0)->platform);
        scene->removeItem(Co.at(0)->rad);
        scene->removeItem(Co.at(0));
        Co.removeAt(0);



    }
    while(T1.size() != 0)
    {
        scene->removeItem(T1.at(0));
        T1.removeAt(0);
    }
    Co_state=0;
    radD1->set_ini();
    radO1->set_ini();
    radO2->set_ini();
    scene->removeItem(radD1);
    scene->removeItem(radO1);
    scene->removeItem(radO2);

}

void MainWindow::make_trayectory()
{
    if(t>trayectory_moment && se_puede_avanzar)
    {
    if(punto==1 )
    {

        if(Co.size()!=0)
        {
            if(Co.at(0)->balasA.size()!=0)
            {
                T1.push_back(new puntos_de_trayectoria(Co.at(0)->balasA.at(0)->get_pos_at(trayectory_moment)));
                scene->addItem(T1.back());
            }
        }
    }
        if(punto==2)
        {
            if(Cd.size()!=0)
            {
                if(Cd.at(0)->balasA.size()!=0)
                {
                    T1.push_back(new puntos_de_trayectoria(Cd.at(0)->balasA.at(0)->get_pos_at(trayectory_moment)));
                    scene->addItem(T1.back());
                }
            }
        }



        if(punto==3)
        {
            if(Cd.size()!=0 && t>OtoD)
            {
                if(Cd.at(0)->balasD.size()!=0)
                {
                    T1.push_back(new puntos_de_trayectoria(Cd.at(0)->balasD.at(0)->get_pos_at(trayectory_moment-OtoD)));
                    scene->addItem(T1.back());
                }

            }
            if(Co.size()!=0)
            {
                if(Co.at(0)->balasA.size()!=0)
                {
                    T1.push_back(new puntos_de_trayectoria(Co.at(0)->balasA.at(0)->get_pos_at(trayectory_moment)));
                    scene->addItem(T1.back());
                }
            }
        }
        if(punto==4)
        {
            if(Cd.size()!=0)
            {
                if(Cd.at(0)->balasA.size()!=0)
                {
                    T1.push_back(new puntos_de_trayectoria(Cd.at(0)->balasA.at(0)->get_pos_at(trayectory_moment)));
                    scene->addItem(T1.back());
                }

            }
            if(Co.size()!=0 && t>DtoO)
            {

                if(Co.at(0)->balasD.size()!=0)
                {
                    T1.push_back(new puntos_de_trayectoria(Co.at(0)->balasD.at(0)->get_pos_at(trayectory_moment-DtoO)));
                    scene->addItem(T1.back());
                }

            }
        }
        if(punto==5)
        {
            if(Cd.size()!=0 && t>OtoD)
            {
                if(Cd.at(0)->balasD.size()!=0)
                {
                    T1.push_back(new puntos_de_trayectoria(Cd.at(0)->balasD.at(0)->get_pos_at(trayectory_moment-OtoD)));
                    scene->addItem(T1.back());
                }

            }
            if(Co.size()!=0)
            {
                if(Co.at(0)->balasA.size()!=0)
                {
                    T1.push_back(new puntos_de_trayectoria(Co.at(0)->balasA.at(0)->get_pos_at(trayectory_moment)));
                    scene->addItem(T1.back());
                }
                if(Co.at(0)->balasDD.size()!=0 && t>OtoD+DtoO)
                {
                    T1.push_back(new puntos_de_trayectoria(Co.at(0)->balasDD.at(0)->get_pos_at(trayectory_moment-OtoD-DtoO)));
                    scene->addItem(T1.back());
                }
            }
        }


        trayectory_moment+=t_limit/80;
    }
}

void MainWindow::make_collitions()
{
    if(punto==3)
    {
        if(radD1->collidesWithItem(Co.at(0)->balasA.at(0) ))
        {
            scene->removeItem(Co.at(0)->balasA.at(0));
            scene->removeItem(Cd.at(0)->balasD.at(0));
            Co.at(0)->balasA.clear();
            Cd.at(0)->balasD.clear();
            radD1->set_ini();
            radO1->set_ini();
            punto=0;
        }
    }
    if(punto==4)
    {
        if(radO1->collidesWithItem(Cd.at(0)->balasA.at(0) ))
        {

            scene->removeItem(Cd.at(0)->balasA.at(0));
            scene->removeItem(Co.at(0)->balasD.at(0));
            Cd.at(0)->balasA.clear();
            Co.at(0)->balasD.clear();
            radD1->set_ini();
            radO1->set_ini();
            punto=0;
        }
    }
    if(punto==5)
    {
        if(radO2->collidesWithItem(Cd.at(0)->balasD.at(0) ))
        {

            scene->removeItem(Cd.at(0)->balasD.at(0));
            scene->removeItem(Co.at(0)->balasDD.at(0));
            Cd.at(0)->balasD.clear();
            Co.at(0)->balasDD.clear();
            radD1->set_ini();
            radO2->set_ini();
            punto=1;
        }
    }
}

void MainWindow::advance_funtion()
{
    if(t<t_limit)
    {
        if(punto==1 || punto==2)
        {
            t+=delt_t;
            if(Cd.size()!=0)
            {
                if(Cd.at(0)->balasA.size()!=0)
                {
                    Cd.at(0)->balasA.at(0)->bala_at(t);

                    radD1->set_pos(Cd.at(0)->balasA.at(0)->get_pos_at(t));
                    rotateCd(180-Cd.at(0)->balasA.at(0)->angle);

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
                    radO1->set_pos(Co.at(0)->balasA.at(0)->get_pos_at(t));
                    rotateCo(180-Co.at(0)->balasA.at(0)->angle,1);
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
                    radD1->set_pos(Cd.at(0)->balasD.at(0)->get_pos_at(t-OtoD));
                    rotateCd(180-Cd.at(0)->balasD.at(0)->angle);

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
                    radO1->set_pos(Co.at(0)->balasA.at(0)->get_pos_at(t));
                    rotateCo(180-Co.at(0)->balasA.at(0)->angle,1);
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
                    radD1->set_pos(Cd.at(0)->balasD.at(0)->get_pos_at(t-OtoD));
                    rotateCd(180-Cd.at(0)->balasD.at(0)->angle);
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
                    radO1->set_pos(Co.at(0)->balasA.at(0)->get_pos_at(t));
                    rotateCo(180-Co.at(0)->balasA.at(0)->angle,1);
                }
                if(Co.at(0)->balasD.size()!=0)
                {
                    Co.at(0)->balasD.at(0)->bala_at(t);
                }
                if(Co.at(0)->balasDD.size()!=0 && t>OtoD+DtoO)
                {
                    Co.at(0)->balasDD.at(0)->bala_at(t-(OtoD+DtoO));
                    radO2->set_pos(Co.at(0)->balasDD.at(0)->get_pos_at(t-(OtoD+DtoO)));
                    Co_state=1;
                    rotateCo(180-Co.at(0)->balasDD.at(0)->angle,2);
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
                    radD1->set_pos(Cd.at(0)->balasA.at(0)->get_pos_at(t));
                    rotateCd(180-Cd.at(0)->balasA.at(0)->angle);
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
                    radO1->set_pos(Co.at(0)->balasD.at(0)->get_pos_at(t-DtoO));
                    rotateCo(180-Co.at(0)->balasD.at(0)->angle,1);
                }
                if(Co.at(0)->balasDD.size()!=0)
                {
                    Co.at(0)->balasDD.at(0)->bala_at(t);
                }
            }
        }
        if(t>=t_limit)
        {
            punto=0;
        }
        make_trayectory();
        make_collitions();

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
    radD1= new radio_d_explocion('y',Cd.at(0)->RB1);
    radO1= new radio_d_explocion('R',Co.at(0)->RB1);
    radO2= new radio_d_explocion('R',Co.at(0)->RB2);


    scene->addItem(Co.at(0)->rad);
    scene->addItem(Co.at(0));
    scene->addItem(Co.at(0)->platform);
    scene->addItem(Cd.at(0)->rad);
    scene->addItem(Cd.at(0));
    scene->addItem(Cd.at(0)->platform);




    scene->addItem(radD1);
    scene->addItem(radO1);
    scene->addItem(radO2);
}




void MainWindow::primero()
{
     Co.at(0)->balasA.push_back(new balas(Co.at(0)->get_pos(),Cd.at(0)->get_pos(),'O',Co.at(0)->RB1));
     t_limit=Co.at(0)->balasA.at(0)->ipotetical_moment_colition;
}

void MainWindow::segundo()
{
    Cd.at(0)->balasA.push_back(new balas(Cd.at(0)->get_pos(),Co.at(0)->get_pos(),'D',Cd.at(0)->RB1));
    t_limit=Cd.at(0)->balasA.at(0)->ipotetical_moment_colition;
}

void MainWindow::tercero()
{
    do
    {
    primero();
    }
    while(t_limit-1.3<OtoD+OtoD);
    Cd.at(0)->balasD.push_back( new balas(Cd.at(0)->get_pos(),Co.at(0)->balasA.at(0)->get_pos_at(OtoD),Co.at(0)->balasA.at(0)->get_vel_at(OtoD),
                                          'D',Cd.at(0)->RB1,Co.at(0)->balasA.at(0)->get_colitio_moment()-OtoD));

}

void MainWindow::cuarto()
{
    do
    {
    segundo();
    }
    while(t_limit-0.3<DtoO);
    Co.at(0)->balasD.push_back( new balas(Co.at(0)->get_pos(),Cd.at(0)->balasA.at(0)->get_pos_at(DtoO),Cd.at(0)->balasA.at(0)->get_vel_at(DtoO),
                                          'O',Co.at(0)->RB1,Cd.at(0)->balasA.at(0)->get_colitio_moment()-DtoO));
}

void MainWindow::quinto()
{
        do
        {
            tercero();
        }
        while(Cd.at(0)->balasD.at(0)->get_colitio_moment()-DtoO<0.6 );
        Co.at(0)->balasDD.push_back( new balas(Co.at(0)->get_pos(), Cd.at(0)->balasD.at(0)->get_pos_at(DtoO),Cd.at(0)->balasD.at(0)->get_vel_at(DtoO),
                                              'O',Co.at(0)->RB2, Cd.at(0)->balasD.at(0)->get_colitio_moment()-DtoO));
}

void MainWindow::rotateCd(float ang)
{
    Cd.at(0)->setRotation(ang);
}

void MainWindow::rotateCo(float ang, int i)
{
    if(Co_state==0 && i==1)
    {
        Co.at(0)->setRotation(ang);
    }
    else
    {
        Co.at(0)->setRotation(ang);
    }
}

void MainWindow::on_pushButton_clicked()
{
    on_pushButton_6_clicked();
    punto=1;
    primero();
    scene->addItem( Co.at(0)->balasA.at(0));
    t=0;
    trayectory_moment=0;

}

void MainWindow::on_pushButton_2_clicked()
{
    on_pushButton_6_clicked();
    punto=2;
    segundo();
    scene->addItem( Cd.at(0)->balasA.at(0));
    t=0;
    trayectory_moment=0;
}

void MainWindow::on_pushButton_3_clicked()
{
    on_pushButton_6_clicked();
    punto=3;
    tercero();
    scene->removeItem(radD1);
    scene->removeItem(radO1);
    scene->removeItem(radO2);
    scene->addItem(radO1);
    scene->addItem(radD1);
    scene->addItem(radO2);
    scene->addItem( Cd.at(0)->balasD.at(0));
    scene->addItem( Co.at(0)->balasA.at(0));
    t=0;
    trayectory_moment=0;
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    delt_t= float(value)/300;
    ui->lcdNumber->display(delt_t*60);
}

void MainWindow::on_pushButton_4_clicked()
{
    on_pushButton_6_clicked();
    punto=4;
    cuarto();
    scene->removeItem(radD1);
    scene->removeItem(radO1);
    scene->removeItem(radO2);
    scene->addItem(radD1);
    scene->addItem(radO2);
    scene->addItem(radO1);
    scene->addItem( Cd.at(0)->balasA.at(0));
    scene->addItem( Co.at(0)->balasD.at(0));
    t=0;
    trayectory_moment=0;
}

void MainWindow::on_pushButton_5_clicked()
{
    on_pushButton_6_clicked();
    punto=5;
    quinto();
    scene->removeItem(radD1);
    scene->removeItem(radO1);
    scene->removeItem(radO2);
    scene->addItem(radO1);
    scene->addItem(radD1);
    scene->addItem(radO2);
    scene->addItem( Cd.at(0)->balasD.at(0));
    scene->addItem( Co.at(0)->balasA.at(0));
    scene->addItem( Co.at(0)->balasDD.at(0));
    t=0;
    trayectory_moment=0;
}
