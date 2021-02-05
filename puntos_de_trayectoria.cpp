#include "puntos_de_trayectoria.h"

puntos_de_trayectoria::puntos_de_trayectoria()
{

}
QRectF puntos_de_trayectoria::boundingRect() const
{
            return QRectF(-1,-1,2,2);
}

void puntos_de_trayectoria::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}
