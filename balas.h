#ifndef BALAS_H
#define BALAS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <array>
#include <QTimer>

class balas: public QGraphicsItem
{
public:
    balas();
    //bala que dispara a un punto
    balas(std::array <float,2>posM,std::array <float,2>posT,char canhon,float r);
    //bala que dispara aun punto en moviemineto
    balas(std::array <float,2>posM, std::array <float,2>posT,std::array <float,2>velT, char canhon,float r, float tlim);

    std::array <float,2> get_vel_at(float t);
    std::array <float,2> get_pos_at(float t);
    void bala_at(float t);
    float get_colitio_moment();
    float ipotetical_moment_colition=0;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget =nullptr);
private:
    std::array <float,2> pos;
    std::array <float,2> vel;
    float gravity=-9.8;
    char state;
    float colition_moment;
};
#endif // BALAS_H
