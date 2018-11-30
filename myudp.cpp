// myudp.cpp

#include "myudp.h"
#include <QNmeaPositionInfoSource>

MyUDP::MyUDP(QObject *parent) :
    QObject(parent)
{

    socket = new QUdpSocket(this);
    nmeasource = new QNmeaPositionInfoSource(QNmeaPositionInfoSource::UpdateMode::RealTimeMode);

    nmeasource->setDevice(socket);

    connect(nmeasource, &QGeoPositionInfoSource::positionUpdated,
            this, [](const QGeoPositionInfo &update){qDebug() << "data: " << update;});

    connect(nmeasource, &QGeoPositionInfoSource::updateTimeout,
            this, [] () { qDebug() << "timeout"; });

    connect(socket, &QUdpSocket::readyRead,
            [] () { qDebug() << "got data"; });

    socket->bind(QHostAddress::AnyIPv4, 14401);

    nmeasource->setUpdateInterval(1000);
    nmeasource->startUpdates();
}
