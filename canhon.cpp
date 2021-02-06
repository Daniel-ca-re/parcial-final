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
        RB2=0.01*d;
    }
    setPos(pos[0],-pos[1]);
    rad= new radio_d_explocion('w',35);
    rad->set_pos(p);
    platform= new plataforma(p);


}

std::array<float, 2> canhon::get_pos()
{
    return pos;
}

QRectF canhon::boundingRect() const
{
            return QRectF(-15,-5,20,10);
}

void canhon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRoundRect(boundingRect());
}
