#include "plataforma.h"

plataforma::plataforma()
{

}

plataforma::plataforma(std::array<float, 2> p)
{
    setPos(p[0],-p[1]);
}

QRectF plataforma::boundingRect() const
{
    return QRectF(-15,0,30,10);
}

void plataforma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawRoundRect(boundingRect());
}
