#ifndef PUNTOS_DE_TRAYECTORIA_H
#define PUNTOS_DE_TRAYECTORIA_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <array>
#include <QTimer>


class puntos_de_trayectoria: public QGraphicsItem
{
public:
    puntos_de_trayectoria();
    puntos_de_trayectoria(std::array <float,2> p);
    std::array <float,2> pos;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget =nullptr);
};

#endif // PUNTOS_DE_TRAYECTORIA_H
