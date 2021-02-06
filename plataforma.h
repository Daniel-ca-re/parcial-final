#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <array>
#include <QTimer>


class plataforma: public QGraphicsItem
{
public:
    plataforma();
    plataforma(std::array<float, 2> p);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget =nullptr);
};

#endif // PLATAFORMA_H
