#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "canhon.h"
#include "puntos_de_trayectoria.h"

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
    float OtoD=2;
    float DtoO=1;
    QList <puntos_de_trayectoria *> T1;
    QList <puntos_de_trayectoria *> T2;
    QList <puntos_de_trayectoria *> T3;
    QTimer * timer;

    int punto;
    void primero();
    void segundo();
    void tercero();
    void cuarto();
    void quinto();

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
