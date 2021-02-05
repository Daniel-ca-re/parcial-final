#ifndef RADIO_D_EXPLOCION_H
#define RADIO_D_EXPLOCION_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <array>
#include <QTimer>


class radio_d_explocion: public QGraphicsItem
{
private:
    float r;
    char color;
    std::array <float,2> pos;
public:
    radio_d_explocion();
    radio_d_explocion( char col, float rad );
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget =nullptr);
    void set_pos(std::array <float,2> p);
    void set_ini();
};

#endif // RADIO_D_EXPLOCION_H
