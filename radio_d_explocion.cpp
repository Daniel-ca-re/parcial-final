#include "radio_d_explocion.h"

radio_d_explocion::radio_d_explocion()
{
    set_ini();
    r=5;
}

radio_d_explocion::radio_d_explocion( char col, float rad )
{
    color=col;
    r=rad;
    set_ini();
}

QRectF radio_d_explocion::boundingRect() const
{
            return QRectF(-r/2,-r/2,r,r);
}

void radio_d_explocion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if(color=='R')
    {
        painter->setBrush(Qt::red);
        painter->drawEllipse(boundingRect());
    }
    else
    {
        painter->setBrush(Qt::darkYellow);
        painter->drawEllipse(boundingRect());
    }
}

void radio_d_explocion::set_pos(std::array<float, 2> p)
{
    pos=p;
    setPos(pos[0],-pos[1]);
}

void radio_d_explocion::set_ini()
{
    pos={-500,-500};
    setPos(pos[0],-pos[1]);

}
