#ifndef CANHON_H
#define CANHON_H
#include "balas.h"
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <array>
#include <QTimer>
#include "radio_d_explocion.h"
#include "plataforma.h"


class canhon: public QGraphicsItem
{
private:
        std::array <float,2> pos;
public:
    canhon();
    canhon(std::array <float,2> p, char t, float d);
        std::array <float,2> get_pos();
        float  RB1 , RB2;
        QList <balas *> balasA;
        QList <balas *> balasD;
        QList <balas *> balasDD;

        radio_d_explocion *rad;
        plataforma *platform;

        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget =nullptr);
        char type;

};

#endif // CANHON_H
