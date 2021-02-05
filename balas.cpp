#include "balas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cmath"
#include <iostream>
balas::balas()
{
    vel={0,0};
    pos={0,0};
}

balas::balas(std::array<float, 2> posM, std::array<float, 2> posT, char canhon,float r)
{
    state=canhon;
    pos=posM;
    float D = posT[0]-posM[0];
    float deltH= posT[1]-posM[1];
    do
    {
        float angle =float(rand()%900)/10;
        if(state=='D')
        {
            angle+=90;
        }
        std::cout<<angle<<'\n';
        float V=(D*sqrt(gravity/(2*(deltH-D*tan((3.1416/180)*angle))))/cos((3.1416/180)*angle));
        vel={float(V*cos((3.1416/180)*angle)),float(V*sin((3.1416/180)*angle))};
        colition_moment=(abs(D)-r)/abs(vel[0]);
    }
    while(get_pos_at(colition_moment/2)[1]>881);
    setPos(pos[0],-pos[1]);
}

balas::balas(std::array<float, 2> posM, std::array<float, 2> posT, std::array<float, 2> velT, char canhon, float r , float tlim)
{
    state=canhon;
    pos=posM;
    float D = posT[0]-posM[0];
    float deltH= posT[1]-posM[1];
    do
    {
    float angle =float(rand()%900)/10;
    if(state=='D')
    {
        angle+=90;
    }
    std::cout<<angle<<'\n';
    float V=(deltH*velT[0]-D*velT[1])/(deltH*cos((3.1416/180)*angle)-D*sin((3.1416/180)*angle));
    vel={float(V*cos((3.1416/180)*angle)),float(V*sin((3.1416/180)*angle))};
    }
    while(D/(vel[0]-velT[0])<0 || D/(vel[0]-velT[0])>tlim || abs(get_pos_at(D/(vel[0]-velT[0]))[0]-pos[0])<r);
    colition_moment=(abs(D)-r)/abs(vel[0]-velT[0]);
    setPos(pos[0],-pos[1]);
}

std::array<float, 2> balas::get_vel_at(float t)
{
    return {vel[0],vel[1]+gravity*t};
}

std::array<float, 2> balas::get_pos_at(float t)
{
    return {pos[0]+vel[0]*t,float(pos[1]+vel[1]*t+(gravity/2)*pow(t,2))};
}

void balas::bala_at(float t)
{
    auto p = get_pos_at(t);
    setPos(p[0],-p[1]);
}

float balas::get_colitio_moment()
{
    return colition_moment;
}

QRectF balas::boundingRect() const
{
        return QRectF(-5,-5,10,10);
}

void balas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}
