#include "canhon.h"

canhon::canhon()
{
    pos={0,0};
    type='I';
        RB1 =0;
        RB2=0;
        setPos(0,0);
}

canhon::canhon(std::array<float, 2> p, char t, float d)
{
    pos=p;
    type=t;
    if (type=='D')
    {
        RB1 =0.025*d;
        RB2=0.025*d;
    }
    else
    {
        RB1 =0.05*d;
        RB2=0.005*d;
    }
        setPos(pos[0],-pos[1]);

}

std::array<float, 2> canhon::get_pos()
{
    return pos;
}

QRectF canhon::boundingRect() const
{
            return QRectF(-5,-5,10,10);
}

void canhon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRoundRect(boundingRect());
}
