#include "listenclient.h"

#include <QTcpSocket>
#include <QTime>
#include <QDebug>

ListConnectClient ListenClient::q_listConnectClient;

ListenClient::ListenClient()
{
    m_server = new QTcpServer(this);
    m_server->listen(QHostAddress::Any,55555);

    connect(m_server,SIGNAL(newConnection()),
            this,SLOT(slotServerConnected()));
}

ListenClient::~ListenClient()
{

}

void ListenClient::slotServerConnected()
{
    ConnectClient *socket = new ConnectClient(
                m_server->nextPendingConnection());

    connect(socket, SIGNAL(signalUserLoginSuccess(User)),
            this, SIGNAL(signalUserLoginSuccess(User)));
    q_listConnectClient.append(socket);

    socket->start();
}
