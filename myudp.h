// myudp.h

#ifndef MYUDP_H
#define MYUDP_H

#include <QNmeaPositionInfoSource>
#include <QObject>
#include <QUdpSocket>

class MyUDP : public QObject
{
    Q_OBJECT
public:
    explicit MyUDP(QObject *parent = nullptr);
signals:

public slots:

private:
    QUdpSocket *socket;
    QNmeaPositionInfoSource* nmeasource;

};

#endif // MYUDP_H
