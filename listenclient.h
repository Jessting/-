#ifndef LISTENCLIENT_H
#define LISTENCLIENT_H

#include <QObject>
#include <QTcpServer>
#include <QList>
#include <QTcpSocket>

#include "connectclient.h"

class ListenClient : public QObject
{
    Q_OBJECT
public:
    ListenClient();
    ~ListenClient();

    static ListConnectClient q_listConnectClient;

signals:
    void signalUserLoginSuccess(User info);

public slots:
    void slotServerConnected();

private:
    QTcpServer *m_server;
};

#endif // LISTENCLIENT_H
