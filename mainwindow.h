#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "canhon.h"
#include "puntos_de_trayectoria.h"
#include "radio_d_explocion.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <vector>
#include <iostream>
#include <QTimer>
#include <QGraphicsView>
#include <QRectF>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void delete_all();


public slots:






private:
    QGraphicsScene *scene;

    Ui::MainWindow *ui;
    QList <canhon *> Cd;
    QList <canhon *> Co;
    float delt_t;
    float t;
    float t_limit;
    float trayectory_moment;
    void make_trayectory();
    void make_collitions();
    float OtoD=2;
    float DtoO=1;
    bool se_puede_avanzar=true;
    radio_d_explocion *radO1;
    radio_d_explocion *radD1;
    radio_d_explocion *radO2;


    QList <puntos_de_trayectoria *> T1;
    QTimer * timer;

    int punto;
    void primero();
    void segundo();
    void tercero();
    void cuarto();
    void quinto();

    void rotateCd(float ang);
    void rotateCo(float ang, int i);
    int Co_state=0;

private slots:
    void on_pushButton_6_clicked();

    void advance_funtion();


    void on_pushButton_clicked();



    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_verticalSlider_valueChanged(int value);
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
};
#endif // MAINWINDOW_H
